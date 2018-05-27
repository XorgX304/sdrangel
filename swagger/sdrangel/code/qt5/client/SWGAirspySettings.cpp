/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube     ---   Limitations and specifcities:       * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Stopping instance i.e. /sdrangel with DELETE method is a server only feature. It allows stopping the instance nicely.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV demodulator, Channel Analyzer, Channel Analyzer NG, LoRa demodulator, TCP source   * The content type returned is always application/json except in the following cases:     * An incorrect URL was specified: this document is returned as text/html with a status 400    --- 
 *
 * OpenAPI spec version: 4.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGAirspySettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGAirspySettings::SWGAirspySettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAirspySettings::SWGAirspySettings() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    dev_sample_rate_index = 0;
    m_dev_sample_rate_index_isSet = false;
    lna_gain = 0;
    m_lna_gain_isSet = false;
    mixer_gain = 0;
    m_mixer_gain_isSet = false;
    vga_gain = 0;
    m_vga_gain_isSet = false;
    lna_agc = 0;
    m_lna_agc_isSet = false;
    mixer_agc = 0;
    m_mixer_agc_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    bias_t = 0;
    m_bias_t_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    file_record_name = nullptr;
    m_file_record_name_isSet = false;
}

SWGAirspySettings::~SWGAirspySettings() {
    this->cleanup();
}

void
SWGAirspySettings::init() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    dev_sample_rate_index = 0;
    m_dev_sample_rate_index_isSet = false;
    lna_gain = 0;
    m_lna_gain_isSet = false;
    mixer_gain = 0;
    m_mixer_gain_isSet = false;
    vga_gain = 0;
    m_vga_gain_isSet = false;
    lna_agc = 0;
    m_lna_agc_isSet = false;
    mixer_agc = 0;
    m_mixer_agc_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    bias_t = 0;
    m_bias_t_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    file_record_name = new QString("");
    m_file_record_name_isSet = false;
}

void
SWGAirspySettings::cleanup() {















    if(file_record_name != nullptr) { 
        delete file_record_name;
    }
}

SWGAirspySettings*
SWGAirspySettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAirspySettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dev_sample_rate_index, pJson["devSampleRateIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lna_gain, pJson["lnaGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&mixer_gain, pJson["mixerGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&vga_gain, pJson["vgaGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lna_agc, pJson["lnaAGC"], "qint32", "");
    
    ::SWGSDRangel::setValue(&mixer_agc, pJson["mixerAGC"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fc_pos, pJson["fcPos"], "qint32", "");
    
    ::SWGSDRangel::setValue(&bias_t, pJson["biasT"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGSDRangel::setValue(&transverter_mode, pJson["transverterMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&transverter_delta_frequency, pJson["transverterDeltaFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&file_record_name, pJson["fileRecordName"], "QString", "QString");
    
}

QString
SWGAirspySettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAirspySettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_dev_sample_rate_index_isSet){
        obj->insert("devSampleRateIndex", QJsonValue(dev_sample_rate_index));
    }
    if(m_lna_gain_isSet){
        obj->insert("lnaGain", QJsonValue(lna_gain));
    }
    if(m_mixer_gain_isSet){
        obj->insert("mixerGain", QJsonValue(mixer_gain));
    }
    if(m_vga_gain_isSet){
        obj->insert("vgaGain", QJsonValue(vga_gain));
    }
    if(m_lna_agc_isSet){
        obj->insert("lnaAGC", QJsonValue(lna_agc));
    }
    if(m_mixer_agc_isSet){
        obj->insert("mixerAGC", QJsonValue(mixer_agc));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_fc_pos_isSet){
        obj->insert("fcPos", QJsonValue(fc_pos));
    }
    if(m_bias_t_isSet){
        obj->insert("biasT", QJsonValue(bias_t));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
    }
    if(m_transverter_mode_isSet){
        obj->insert("transverterMode", QJsonValue(transverter_mode));
    }
    if(m_transverter_delta_frequency_isSet){
        obj->insert("transverterDeltaFrequency", QJsonValue(transverter_delta_frequency));
    }
    if(file_record_name != nullptr && *file_record_name != QString("")){
        toJsonValue(QString("fileRecordName"), file_record_name, obj, QString("QString"));
    }

    return obj;
}

qint64
SWGAirspySettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGAirspySettings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGAirspySettings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGAirspySettings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint32
SWGAirspySettings::getDevSampleRateIndex() {
    return dev_sample_rate_index;
}
void
SWGAirspySettings::setDevSampleRateIndex(qint32 dev_sample_rate_index) {
    this->dev_sample_rate_index = dev_sample_rate_index;
    this->m_dev_sample_rate_index_isSet = true;
}

qint32
SWGAirspySettings::getLnaGain() {
    return lna_gain;
}
void
SWGAirspySettings::setLnaGain(qint32 lna_gain) {
    this->lna_gain = lna_gain;
    this->m_lna_gain_isSet = true;
}

qint32
SWGAirspySettings::getMixerGain() {
    return mixer_gain;
}
void
SWGAirspySettings::setMixerGain(qint32 mixer_gain) {
    this->mixer_gain = mixer_gain;
    this->m_mixer_gain_isSet = true;
}

qint32
SWGAirspySettings::getVgaGain() {
    return vga_gain;
}
void
SWGAirspySettings::setVgaGain(qint32 vga_gain) {
    this->vga_gain = vga_gain;
    this->m_vga_gain_isSet = true;
}

qint32
SWGAirspySettings::getLnaAgc() {
    return lna_agc;
}
void
SWGAirspySettings::setLnaAgc(qint32 lna_agc) {
    this->lna_agc = lna_agc;
    this->m_lna_agc_isSet = true;
}

qint32
SWGAirspySettings::getMixerAgc() {
    return mixer_agc;
}
void
SWGAirspySettings::setMixerAgc(qint32 mixer_agc) {
    this->mixer_agc = mixer_agc;
    this->m_mixer_agc_isSet = true;
}

qint32
SWGAirspySettings::getLog2Decim() {
    return log2_decim;
}
void
SWGAirspySettings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGAirspySettings::getFcPos() {
    return fc_pos;
}
void
SWGAirspySettings::setFcPos(qint32 fc_pos) {
    this->fc_pos = fc_pos;
    this->m_fc_pos_isSet = true;
}

qint32
SWGAirspySettings::getBiasT() {
    return bias_t;
}
void
SWGAirspySettings::setBiasT(qint32 bias_t) {
    this->bias_t = bias_t;
    this->m_bias_t_isSet = true;
}

qint32
SWGAirspySettings::getDcBlock() {
    return dc_block;
}
void
SWGAirspySettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGAirspySettings::getIqCorrection() {
    return iq_correction;
}
void
SWGAirspySettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGAirspySettings::getTransverterMode() {
    return transverter_mode;
}
void
SWGAirspySettings::setTransverterMode(qint32 transverter_mode) {
    this->transverter_mode = transverter_mode;
    this->m_transverter_mode_isSet = true;
}

qint64
SWGAirspySettings::getTransverterDeltaFrequency() {
    return transverter_delta_frequency;
}
void
SWGAirspySettings::setTransverterDeltaFrequency(qint64 transverter_delta_frequency) {
    this->transverter_delta_frequency = transverter_delta_frequency;
    this->m_transverter_delta_frequency_isSet = true;
}

QString*
SWGAirspySettings::getFileRecordName() {
    return file_record_name;
}
void
SWGAirspySettings::setFileRecordName(QString* file_record_name) {
    this->file_record_name = file_record_name;
    this->m_file_record_name_isSet = true;
}


bool
SWGAirspySettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){ isObjectUpdated = true; break;}
        if(m_l_oppm_tenths_isSet){ isObjectUpdated = true; break;}
        if(m_dev_sample_rate_index_isSet){ isObjectUpdated = true; break;}
        if(m_lna_gain_isSet){ isObjectUpdated = true; break;}
        if(m_mixer_gain_isSet){ isObjectUpdated = true; break;}
        if(m_vga_gain_isSet){ isObjectUpdated = true; break;}
        if(m_lna_agc_isSet){ isObjectUpdated = true; break;}
        if(m_mixer_agc_isSet){ isObjectUpdated = true; break;}
        if(m_log2_decim_isSet){ isObjectUpdated = true; break;}
        if(m_fc_pos_isSet){ isObjectUpdated = true; break;}
        if(m_bias_t_isSet){ isObjectUpdated = true; break;}
        if(m_dc_block_isSet){ isObjectUpdated = true; break;}
        if(m_iq_correction_isSet){ isObjectUpdated = true; break;}
        if(m_transverter_mode_isSet){ isObjectUpdated = true; break;}
        if(m_transverter_delta_frequency_isSet){ isObjectUpdated = true; break;}
        if(file_record_name != nullptr && *file_record_name != QString("")){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}
