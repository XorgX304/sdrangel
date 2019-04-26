///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QUdpSocket>
#include <QDebug>
#include <QTimer>

#include "dsp/dspcommands.h"
#include "dsp/dspengine.h"
#include <device/devicesourceapi.h>

#include "remoteinputudphandler.h"
#include "remoteinput.h"

RemoteInputUDPHandler::RemoteInputUDPHandler(SampleSinkFifo *sampleFifo, DeviceSourceAPI *deviceAPI) :
    m_deviceAPI(deviceAPI),
    m_masterTimer(deviceAPI->getMasterTimer()),
    m_masterTimerConnected(false),
    m_running(false),
    m_rateDivider(1000/REMOTEINPUT_THROTTLE_MS),
	m_dataSocket(0),
	m_dataAddress(QHostAddress::LocalHost),
	m_remoteAddress(QHostAddress::LocalHost),
	m_dataPort(9090),
	m_dataConnected(false),
	m_udpBuf(0),
	m_udpReadBytes(0),
	m_sampleFifo(sampleFifo),
	m_samplerate(0),
	m_centerFrequency(0),
	m_tv_msec(0),
	m_outputMessageQueueToGUI(0),
	m_tickCount(0),
	m_samplesCount(0),
	m_timer(0),
    m_throttlems(REMOTEINPUT_THROTTLE_MS),
    m_readLengthSamples(0),
    m_readLength(0),
    m_converterBuffer(0),
    m_converterBufferNbSamples(0),
    m_throttleToggle(false),
	m_autoCorrBuffer(true)
{
    m_udpBuf = new char[RemoteUdpSize];

#ifdef USE_INTERNAL_TIMER
#warning "Uses internal timer"
    m_timer = new QTimer();
    m_timer->start(50);
    m_throttlems = m_timer->interval();
#else
    m_throttlems = m_masterTimer.interval();
#endif
    m_rateDivider = 1000 / m_throttlems;
}

RemoteInputUDPHandler::~RemoteInputUDPHandler()
{
	stop();
	delete[] m_udpBuf;
	if (m_converterBuffer) { delete[] m_converterBuffer; }
#ifdef USE_INTERNAL_TIMER
    if (m_timer) {
        delete m_timer;
    }
#endif
}

void RemoteInputUDPHandler::start()
{
	qDebug("RemoteInputUDPHandler::start");

	if (m_running) {
	    return;
	}

	if (!m_dataSocket)
	{
		m_dataSocket = new QUdpSocket(this);
	}

    if (!m_dataConnected)
	{
        connect(m_dataSocket, SIGNAL(readyRead()), this, SLOT(dataReadyRead())); //, Qt::QueuedConnection);

        if (m_dataSocket->bind(m_dataAddress, m_dataPort))
		{
			qDebug("RemoteInputUDPHandler::start: bind data socket to %s:%d", m_dataAddress.toString().toStdString().c_str(),  m_dataPort);
			m_dataConnected = true;
		}
		else
		{
			qWarning("RemoteInputUDPHandler::start: cannot bind data port %d", m_dataPort);
	        disconnect(m_dataSocket, SIGNAL(readyRead()), this, SLOT(dataReadyRead()));
			m_dataConnected = false;
		}
	}

    m_elapsedTimer.start();
    m_running = true;
}

void RemoteInputUDPHandler::stop()
{
	qDebug("RemoteInputUDPHandler::stop");

	if (!m_running) {
	    return;
	}

	disconnectTimer();

    if (m_dataConnected)
    {
		m_dataConnected = false;
	    disconnect(m_dataSocket, SIGNAL(readyRead()), this, SLOT(dataReadyRead()));
	}

	if (m_dataSocket)
	{
		delete m_dataSocket;
		m_dataSocket = 0;
	}

	m_centerFrequency = 0;
	m_samplerate = 0;
	m_running = false;
}

void RemoteInputUDPHandler::configureUDPLink(const QString& address, quint16 port)
{
	qDebug("RemoteInputUDPHandler::configureUDPLink: %s:%d", address.toStdString().c_str(), port);
	bool addressOK = m_dataAddress.setAddress(address);

	if (!addressOK)
	{
		qWarning("RemoteInputUDPHandler::configureUDPLink: invalid address %s. Set to localhost.", address.toStdString().c_str());
		m_dataAddress = QHostAddress::LocalHost;
	}

	m_dataPort = port;
	stop();
	start();
}

void RemoteInputUDPHandler::dataReadyRead()
{
    m_udpReadBytes = 0;

	while (m_dataSocket->hasPendingDatagrams() && m_dataConnected)
	{
		qint64 pendingDataSize = m_dataSocket->pendingDatagramSize();
		m_udpReadBytes += m_dataSocket->readDatagram(&m_udpBuf[m_udpReadBytes], pendingDataSize, &m_remoteAddress, 0);

		if (m_udpReadBytes == RemoteUdpSize) {
		    processData();
		    m_udpReadBytes = 0;
		}
	}
}

void RemoteInputUDPHandler::processData()
{
    m_remoteInputBuffer.writeData(m_udpBuf);
    const RemoteMetaDataFEC& metaData =  m_remoteInputBuffer.getCurrentMeta();
    bool change = false;

    m_tv_msec = m_remoteInputBuffer.getTVOutMSec();

    if (m_centerFrequency != metaData.m_centerFrequency)
    {
        m_centerFrequency = metaData.m_centerFrequency;
        change = true;
    }

    if (m_samplerate != metaData.m_sampleRate)
    {
        m_samplerate = metaData.m_sampleRate;
        change = true;
    }

    if (change && (m_samplerate != 0))
    {
        qDebug("RemoteInputUDPHandler::processData: m_samplerate: %u S/s m_centerFrequency: %lu Hz", m_samplerate, m_centerFrequency);

        DSPSignalNotification *notif = new DSPSignalNotification(m_samplerate, m_centerFrequency); // Frequency in Hz for the DSP engine
        m_deviceAPI->getDeviceEngineInputMessageQueue()->push(notif);

        if (m_outputMessageQueueToGUI)
        {
            RemoteInput::MsgReportRemoteInputStreamData *report = RemoteInput::MsgReportRemoteInputStreamData::create(
                m_samplerate,
                m_centerFrequency, // Frequency in Hz for the GUI
                m_tv_msec);

            m_outputMessageQueueToGUI->push(report);
        }

        connectTimer();
    }
}

void RemoteInputUDPHandler::connectTimer()
{
    if (!m_masterTimerConnected)
    {
        qDebug() << "RemoteInputUDPHandler::connectTimer";
#ifdef USE_INTERNAL_TIMER
#warning "Uses internal timer"
        connect(m_timer, SIGNAL(timeout()), this, SLOT(tick()));
#else
        connect(&m_masterTimer, SIGNAL(timeout()), this, SLOT(tick()));
#endif
        m_masterTimerConnected = true;
    }
}

void RemoteInputUDPHandler::disconnectTimer()
{
    if (m_masterTimerConnected)
    {
        qDebug() << "RemoteInputUDPHandler::disconnectTimer";
#ifdef USE_INTERNAL_TIMER
#warning "Uses internal timer"
        disconnect(m_timer, SIGNAL(timeout()), this, SLOT(tick()));
#else
        disconnect(&m_masterTimer, SIGNAL(timeout()), this, SLOT(tick()));
#endif
        m_masterTimerConnected = false;
    }
}

void RemoteInputUDPHandler::tick()
{
    // auto throttling
    int throttlems = m_elapsedTimer.restart();

    if (throttlems != m_throttlems)
    {
        m_throttlems = throttlems;
        m_readLengthSamples = (m_remoteInputBuffer.getCurrentMeta().m_sampleRate * (m_throttlems+(m_throttleToggle ? 1 : 0))) / 1000;
        m_throttleToggle = !m_throttleToggle;
    }

    if (m_autoCorrBuffer) {
        m_readLengthSamples += m_remoteInputBuffer.getRWBalanceCorrection();
    }

    const RemoteMetaDataFEC& metaData =  m_remoteInputBuffer.getCurrentMeta();
    m_readLength = m_readLengthSamples * (metaData.m_sampleBytes & 0xF) * 2;

    if ((metaData.m_sampleBits == 16) && (SDR_RX_SAMP_SZ == 24)) // 16 -> 24 bits
    {
        if (m_readLengthSamples > m_converterBufferNbSamples)
        {
            if (m_converterBuffer) { delete[] m_converterBuffer; }
            m_converterBuffer = new int32_t[m_readLengthSamples*2];
        }

        uint8_t *buf = m_remoteInputBuffer.readData(m_readLength);

        for (unsigned int is = 0; is < m_readLengthSamples; is++)
        {
            m_converterBuffer[2*is] = ((int16_t*)buf)[2*is]; // I
            m_converterBuffer[2*is]<<=8;
            m_converterBuffer[2*is+1] = ((int16_t*)buf)[2*is+1]; // Q
            m_converterBuffer[2*is+1]<<=8;
        }

        m_sampleFifo->write(reinterpret_cast<quint8*>(m_converterBuffer), m_readLengthSamples*sizeof(Sample));
    }
    else if ((metaData.m_sampleBits == 24) && (SDR_RX_SAMP_SZ == 16)) // 24 -> 16 bits
    {
        if (m_readLengthSamples > m_converterBufferNbSamples)
        {
            if (m_converterBuffer) { delete[] m_converterBuffer; }
            m_converterBuffer = new int32_t[m_readLengthSamples];
        }

        uint8_t *buf = m_remoteInputBuffer.readData(m_readLength);

        for (unsigned int is = 0; is < m_readLengthSamples; is++)
        {
            m_converterBuffer[is] =  ((int32_t *)buf)[2*is+1]>>8; // Q -> MSB
            m_converterBuffer[is] <<=16;
            m_converterBuffer[is] += ((int32_t *)buf)[2*is]>>8; // I -> LSB
        }

        m_sampleFifo->write(reinterpret_cast<quint8*>(m_converterBuffer), m_readLengthSamples*sizeof(Sample));
    }
    else if ((metaData.m_sampleBits == 16) || (metaData.m_sampleBits == 24)) // same sample size and valid size
    {
        // read samples directly feeding the SampleFifo (no callback)
        m_sampleFifo->write(reinterpret_cast<quint8*>(m_remoteInputBuffer.readData(m_readLength)), m_readLength);
        m_samplesCount += m_readLengthSamples;
    }
    else // invalid size
    {
        qWarning("RemoteInputUDPHandler::tick: unexpected sample size in stream: %d bits", (int) metaData.m_sampleBits);
    }

	if (m_tickCount < m_rateDivider)
	{
		m_tickCount++;
	}
	else
	{
		m_tickCount = 0;

		if (m_outputMessageQueueToGUI)
		{
	        int framesDecodingStatus;
	        int minNbBlocks = m_remoteInputBuffer.getMinNbBlocks();
	        int minNbOriginalBlocks = m_remoteInputBuffer.getMinOriginalBlocks();
	        int nbOriginalBlocks = m_remoteInputBuffer.getCurrentMeta().m_nbOriginalBlocks;
	        int nbFECblocks = m_remoteInputBuffer.getCurrentMeta().m_nbFECBlocks;
	        int sampleBits = m_remoteInputBuffer.getCurrentMeta().m_sampleBits;
	        int sampleBytes = m_remoteInputBuffer.getCurrentMeta().m_sampleBytes;

	        //framesDecodingStatus = (minNbOriginalBlocks == nbOriginalBlocks ? 2 : (minNbOriginalBlocks < nbOriginalBlocks - nbFECblocks ? 0 : 1));
	        if (minNbBlocks < nbOriginalBlocks) {
	            framesDecodingStatus = 0;
	        } else if (minNbBlocks < nbOriginalBlocks + nbFECblocks) {
	            framesDecodingStatus = 1;
	        } else {
	            framesDecodingStatus = 2;
	        }

	        RemoteInput::MsgReportRemoteInputStreamTiming *report = RemoteInput::MsgReportRemoteInputStreamTiming::create(
	            m_tv_msec,
	            m_remoteInputBuffer.getBufferLengthInSecs(),
	            m_remoteInputBuffer.getBufferGauge(),
	            framesDecodingStatus,
	            minNbBlocks == nbOriginalBlocks + nbFECblocks,
	            minNbBlocks,
	            minNbOriginalBlocks,
	            m_remoteInputBuffer.getMaxNbRecovery(),
	            m_remoteInputBuffer.getAvgNbBlocks(),
	            m_remoteInputBuffer.getAvgOriginalBlocks(),
	            m_remoteInputBuffer.getAvgNbRecovery(),
	            nbOriginalBlocks,
	            nbFECblocks,
	            sampleBits,
	            sampleBytes);

	            m_outputMessageQueueToGUI->push(report);
		}
	}
}
