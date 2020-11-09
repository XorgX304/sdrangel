/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1, USRP and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.15.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGChirpChatModSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGChirpChatModSettings::SWGChirpChatModSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGChirpChatModSettings::SWGChirpChatModSettings() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    bandwidth_index = 0;
    m_bandwidth_index_isSet = false;
    spread_factor = 0;
    m_spread_factor_isSet = false;
    de_bits = 0;
    m_de_bits_isSet = false;
    preamble_chirps = 0;
    m_preamble_chirps_isSet = false;
    quiet_millis = 0;
    m_quiet_millis_isSet = false;
    sync_word = 0;
    m_sync_word_isSet = false;
    channel_mute = 0;
    m_channel_mute_isSet = false;
    coding_scheme = 0;
    m_coding_scheme_isSet = false;
    nb_parity_bits = 0;
    m_nb_parity_bits_isSet = false;
    has_crc = 0;
    m_has_crc_isSet = false;
    has_header = 0;
    m_has_header_isSet = false;
    my_call = nullptr;
    m_my_call_isSet = false;
    ur_call = nullptr;
    m_ur_call_isSet = false;
    my_loc = nullptr;
    m_my_loc_isSet = false;
    my_rpt = nullptr;
    m_my_rpt_isSet = false;
    message_type = 0;
    m_message_type_isSet = false;
    beacon_message = nullptr;
    m_beacon_message_isSet = false;
    cq_message = nullptr;
    m_cq_message_isSet = false;
    reply_message = nullptr;
    m_reply_message_isSet = false;
    report_message = nullptr;
    m_report_message_isSet = false;
    reply_report_message = nullptr;
    m_reply_report_message_isSet = false;
    rrr_message = nullptr;
    m_rrr_message_isSet = false;
    message73 = nullptr;
    m_message73_isSet = false;
    qso_text_message = nullptr;
    m_qso_text_message_isSet = false;
    text_message = nullptr;
    m_text_message_isSet = false;
    bytes_message = nullptr;
    m_bytes_message_isSet = false;
    message_repeat = 0;
    m_message_repeat_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = nullptr;
    m_title_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

SWGChirpChatModSettings::~SWGChirpChatModSettings() {
    this->cleanup();
}

void
SWGChirpChatModSettings::init() {
    input_frequency_offset = 0L;
    m_input_frequency_offset_isSet = false;
    bandwidth_index = 0;
    m_bandwidth_index_isSet = false;
    spread_factor = 0;
    m_spread_factor_isSet = false;
    de_bits = 0;
    m_de_bits_isSet = false;
    preamble_chirps = 0;
    m_preamble_chirps_isSet = false;
    quiet_millis = 0;
    m_quiet_millis_isSet = false;
    sync_word = 0;
    m_sync_word_isSet = false;
    channel_mute = 0;
    m_channel_mute_isSet = false;
    coding_scheme = 0;
    m_coding_scheme_isSet = false;
    nb_parity_bits = 0;
    m_nb_parity_bits_isSet = false;
    has_crc = 0;
    m_has_crc_isSet = false;
    has_header = 0;
    m_has_header_isSet = false;
    my_call = new QString("");
    m_my_call_isSet = false;
    ur_call = new QString("");
    m_ur_call_isSet = false;
    my_loc = new QString("");
    m_my_loc_isSet = false;
    my_rpt = new QString("");
    m_my_rpt_isSet = false;
    message_type = 0;
    m_message_type_isSet = false;
    beacon_message = new QString("");
    m_beacon_message_isSet = false;
    cq_message = new QString("");
    m_cq_message_isSet = false;
    reply_message = new QString("");
    m_reply_message_isSet = false;
    report_message = new QString("");
    m_report_message_isSet = false;
    reply_report_message = new QString("");
    m_reply_report_message_isSet = false;
    rrr_message = new QString("");
    m_rrr_message_isSet = false;
    message73 = new QString("");
    m_message73_isSet = false;
    qso_text_message = new QString("");
    m_qso_text_message_isSet = false;
    text_message = new QString("");
    m_text_message_isSet = false;
    bytes_message = new QList<QString*>();
    m_bytes_message_isSet = false;
    message_repeat = 0;
    m_message_repeat_isSet = false;
    rgb_color = 0;
    m_rgb_color_isSet = false;
    title = new QString("");
    m_title_isSet = false;
    stream_index = 0;
    m_stream_index_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
    reverse_api_channel_index = 0;
    m_reverse_api_channel_index_isSet = false;
}

void
SWGChirpChatModSettings::cleanup() {












    if(my_call != nullptr) { 
        delete my_call;
    }
    if(ur_call != nullptr) { 
        delete ur_call;
    }
    if(my_loc != nullptr) { 
        delete my_loc;
    }
    if(my_rpt != nullptr) { 
        delete my_rpt;
    }

    if(beacon_message != nullptr) { 
        delete beacon_message;
    }
    if(cq_message != nullptr) { 
        delete cq_message;
    }
    if(reply_message != nullptr) { 
        delete reply_message;
    }
    if(report_message != nullptr) { 
        delete report_message;
    }
    if(reply_report_message != nullptr) { 
        delete reply_report_message;
    }
    if(rrr_message != nullptr) { 
        delete rrr_message;
    }
    if(message73 != nullptr) { 
        delete message73;
    }
    if(qso_text_message != nullptr) { 
        delete qso_text_message;
    }
    if(text_message != nullptr) { 
        delete text_message;
    }
    if(bytes_message != nullptr) { 
        auto arr = bytes_message;
        for(auto o: *arr) { 
            delete o;
        }
        delete bytes_message;
    }


    if(title != nullptr) { 
        delete title;
    }


    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }



}

SWGChirpChatModSettings*
SWGChirpChatModSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGChirpChatModSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&input_frequency_offset, pJson["inputFrequencyOffset"], "qint64", "");
    
    ::SWGSDRangel::setValue(&bandwidth_index, pJson["bandwidthIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&spread_factor, pJson["spreadFactor"], "qint32", "");
    
    ::SWGSDRangel::setValue(&de_bits, pJson["deBits"], "qint32", "");
    
    ::SWGSDRangel::setValue(&preamble_chirps, pJson["preambleChirps"], "qint32", "");
    
    ::SWGSDRangel::setValue(&quiet_millis, pJson["quietMillis"], "qint32", "");
    
    ::SWGSDRangel::setValue(&sync_word, pJson["syncWord"], "qint32", "");
    
    ::SWGSDRangel::setValue(&channel_mute, pJson["channelMute"], "qint32", "");
    
    ::SWGSDRangel::setValue(&coding_scheme, pJson["codingScheme"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nb_parity_bits, pJson["nbParityBits"], "qint32", "");
    
    ::SWGSDRangel::setValue(&has_crc, pJson["hasCRC"], "qint32", "");
    
    ::SWGSDRangel::setValue(&has_header, pJson["hasHeader"], "qint32", "");
    
    ::SWGSDRangel::setValue(&my_call, pJson["myCall"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&ur_call, pJson["urCall"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&my_loc, pJson["myLoc"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&my_rpt, pJson["myRpt"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&message_type, pJson["messageType"], "qint32", "");
    
    ::SWGSDRangel::setValue(&beacon_message, pJson["beaconMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&cq_message, pJson["cqMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reply_message, pJson["replyMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&report_message, pJson["reportMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reply_report_message, pJson["replyReportMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&rrr_message, pJson["rrrMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&message73, pJson["message73"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&qso_text_message, pJson["qsoTextMessage"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&text_message, pJson["textMessage"], "QString", "QString");
    
    
    ::SWGSDRangel::setValue(&bytes_message, pJson["bytesMessage"], "QList", "QString");
    ::SWGSDRangel::setValue(&message_repeat, pJson["messageRepeat"], "qint32", "");
    
    ::SWGSDRangel::setValue(&rgb_color, pJson["rgbColor"], "qint32", "");
    
    ::SWGSDRangel::setValue(&title, pJson["title"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&stream_index, pJson["streamIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_channel_index, pJson["reverseAPIChannelIndex"], "qint32", "");
    
}

QString
SWGChirpChatModSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGChirpChatModSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_input_frequency_offset_isSet){
        obj->insert("inputFrequencyOffset", QJsonValue(input_frequency_offset));
    }
    if(m_bandwidth_index_isSet){
        obj->insert("bandwidthIndex", QJsonValue(bandwidth_index));
    }
    if(m_spread_factor_isSet){
        obj->insert("spreadFactor", QJsonValue(spread_factor));
    }
    if(m_de_bits_isSet){
        obj->insert("deBits", QJsonValue(de_bits));
    }
    if(m_preamble_chirps_isSet){
        obj->insert("preambleChirps", QJsonValue(preamble_chirps));
    }
    if(m_quiet_millis_isSet){
        obj->insert("quietMillis", QJsonValue(quiet_millis));
    }
    if(m_sync_word_isSet){
        obj->insert("syncWord", QJsonValue(sync_word));
    }
    if(m_channel_mute_isSet){
        obj->insert("channelMute", QJsonValue(channel_mute));
    }
    if(m_coding_scheme_isSet){
        obj->insert("codingScheme", QJsonValue(coding_scheme));
    }
    if(m_nb_parity_bits_isSet){
        obj->insert("nbParityBits", QJsonValue(nb_parity_bits));
    }
    if(m_has_crc_isSet){
        obj->insert("hasCRC", QJsonValue(has_crc));
    }
    if(m_has_header_isSet){
        obj->insert("hasHeader", QJsonValue(has_header));
    }
    if(my_call != nullptr && *my_call != QString("")){
        toJsonValue(QString("myCall"), my_call, obj, QString("QString"));
    }
    if(ur_call != nullptr && *ur_call != QString("")){
        toJsonValue(QString("urCall"), ur_call, obj, QString("QString"));
    }
    if(my_loc != nullptr && *my_loc != QString("")){
        toJsonValue(QString("myLoc"), my_loc, obj, QString("QString"));
    }
    if(my_rpt != nullptr && *my_rpt != QString("")){
        toJsonValue(QString("myRpt"), my_rpt, obj, QString("QString"));
    }
    if(m_message_type_isSet){
        obj->insert("messageType", QJsonValue(message_type));
    }
    if(beacon_message != nullptr && *beacon_message != QString("")){
        toJsonValue(QString("beaconMessage"), beacon_message, obj, QString("QString"));
    }
    if(cq_message != nullptr && *cq_message != QString("")){
        toJsonValue(QString("cqMessage"), cq_message, obj, QString("QString"));
    }
    if(reply_message != nullptr && *reply_message != QString("")){
        toJsonValue(QString("replyMessage"), reply_message, obj, QString("QString"));
    }
    if(report_message != nullptr && *report_message != QString("")){
        toJsonValue(QString("reportMessage"), report_message, obj, QString("QString"));
    }
    if(reply_report_message != nullptr && *reply_report_message != QString("")){
        toJsonValue(QString("replyReportMessage"), reply_report_message, obj, QString("QString"));
    }
    if(rrr_message != nullptr && *rrr_message != QString("")){
        toJsonValue(QString("rrrMessage"), rrr_message, obj, QString("QString"));
    }
    if(message73 != nullptr && *message73 != QString("")){
        toJsonValue(QString("message73"), message73, obj, QString("QString"));
    }
    if(qso_text_message != nullptr && *qso_text_message != QString("")){
        toJsonValue(QString("qsoTextMessage"), qso_text_message, obj, QString("QString"));
    }
    if(text_message != nullptr && *text_message != QString("")){
        toJsonValue(QString("textMessage"), text_message, obj, QString("QString"));
    }
    if(bytes_message && bytes_message->size() > 0){
        toJsonArray((QList<void*>*)bytes_message, obj, "bytesMessage", "QString");
    }
    if(m_message_repeat_isSet){
        obj->insert("messageRepeat", QJsonValue(message_repeat));
    }
    if(m_rgb_color_isSet){
        obj->insert("rgbColor", QJsonValue(rgb_color));
    }
    if(title != nullptr && *title != QString("")){
        toJsonValue(QString("title"), title, obj, QString("QString"));
    }
    if(m_stream_index_isSet){
        obj->insert("streamIndex", QJsonValue(stream_index));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }
    if(m_reverse_api_channel_index_isSet){
        obj->insert("reverseAPIChannelIndex", QJsonValue(reverse_api_channel_index));
    }

    return obj;
}

qint64
SWGChirpChatModSettings::getInputFrequencyOffset() {
    return input_frequency_offset;
}
void
SWGChirpChatModSettings::setInputFrequencyOffset(qint64 input_frequency_offset) {
    this->input_frequency_offset = input_frequency_offset;
    this->m_input_frequency_offset_isSet = true;
}

qint32
SWGChirpChatModSettings::getBandwidthIndex() {
    return bandwidth_index;
}
void
SWGChirpChatModSettings::setBandwidthIndex(qint32 bandwidth_index) {
    this->bandwidth_index = bandwidth_index;
    this->m_bandwidth_index_isSet = true;
}

qint32
SWGChirpChatModSettings::getSpreadFactor() {
    return spread_factor;
}
void
SWGChirpChatModSettings::setSpreadFactor(qint32 spread_factor) {
    this->spread_factor = spread_factor;
    this->m_spread_factor_isSet = true;
}

qint32
SWGChirpChatModSettings::getDeBits() {
    return de_bits;
}
void
SWGChirpChatModSettings::setDeBits(qint32 de_bits) {
    this->de_bits = de_bits;
    this->m_de_bits_isSet = true;
}

qint32
SWGChirpChatModSettings::getPreambleChirps() {
    return preamble_chirps;
}
void
SWGChirpChatModSettings::setPreambleChirps(qint32 preamble_chirps) {
    this->preamble_chirps = preamble_chirps;
    this->m_preamble_chirps_isSet = true;
}

qint32
SWGChirpChatModSettings::getQuietMillis() {
    return quiet_millis;
}
void
SWGChirpChatModSettings::setQuietMillis(qint32 quiet_millis) {
    this->quiet_millis = quiet_millis;
    this->m_quiet_millis_isSet = true;
}

qint32
SWGChirpChatModSettings::getSyncWord() {
    return sync_word;
}
void
SWGChirpChatModSettings::setSyncWord(qint32 sync_word) {
    this->sync_word = sync_word;
    this->m_sync_word_isSet = true;
}

qint32
SWGChirpChatModSettings::getChannelMute() {
    return channel_mute;
}
void
SWGChirpChatModSettings::setChannelMute(qint32 channel_mute) {
    this->channel_mute = channel_mute;
    this->m_channel_mute_isSet = true;
}

qint32
SWGChirpChatModSettings::getCodingScheme() {
    return coding_scheme;
}
void
SWGChirpChatModSettings::setCodingScheme(qint32 coding_scheme) {
    this->coding_scheme = coding_scheme;
    this->m_coding_scheme_isSet = true;
}

qint32
SWGChirpChatModSettings::getNbParityBits() {
    return nb_parity_bits;
}
void
SWGChirpChatModSettings::setNbParityBits(qint32 nb_parity_bits) {
    this->nb_parity_bits = nb_parity_bits;
    this->m_nb_parity_bits_isSet = true;
}

qint32
SWGChirpChatModSettings::getHasCrc() {
    return has_crc;
}
void
SWGChirpChatModSettings::setHasCrc(qint32 has_crc) {
    this->has_crc = has_crc;
    this->m_has_crc_isSet = true;
}

qint32
SWGChirpChatModSettings::getHasHeader() {
    return has_header;
}
void
SWGChirpChatModSettings::setHasHeader(qint32 has_header) {
    this->has_header = has_header;
    this->m_has_header_isSet = true;
}

QString*
SWGChirpChatModSettings::getMyCall() {
    return my_call;
}
void
SWGChirpChatModSettings::setMyCall(QString* my_call) {
    this->my_call = my_call;
    this->m_my_call_isSet = true;
}

QString*
SWGChirpChatModSettings::getUrCall() {
    return ur_call;
}
void
SWGChirpChatModSettings::setUrCall(QString* ur_call) {
    this->ur_call = ur_call;
    this->m_ur_call_isSet = true;
}

QString*
SWGChirpChatModSettings::getMyLoc() {
    return my_loc;
}
void
SWGChirpChatModSettings::setMyLoc(QString* my_loc) {
    this->my_loc = my_loc;
    this->m_my_loc_isSet = true;
}

QString*
SWGChirpChatModSettings::getMyRpt() {
    return my_rpt;
}
void
SWGChirpChatModSettings::setMyRpt(QString* my_rpt) {
    this->my_rpt = my_rpt;
    this->m_my_rpt_isSet = true;
}

qint32
SWGChirpChatModSettings::getMessageType() {
    return message_type;
}
void
SWGChirpChatModSettings::setMessageType(qint32 message_type) {
    this->message_type = message_type;
    this->m_message_type_isSet = true;
}

QString*
SWGChirpChatModSettings::getBeaconMessage() {
    return beacon_message;
}
void
SWGChirpChatModSettings::setBeaconMessage(QString* beacon_message) {
    this->beacon_message = beacon_message;
    this->m_beacon_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getCqMessage() {
    return cq_message;
}
void
SWGChirpChatModSettings::setCqMessage(QString* cq_message) {
    this->cq_message = cq_message;
    this->m_cq_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getReplyMessage() {
    return reply_message;
}
void
SWGChirpChatModSettings::setReplyMessage(QString* reply_message) {
    this->reply_message = reply_message;
    this->m_reply_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getReportMessage() {
    return report_message;
}
void
SWGChirpChatModSettings::setReportMessage(QString* report_message) {
    this->report_message = report_message;
    this->m_report_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getReplyReportMessage() {
    return reply_report_message;
}
void
SWGChirpChatModSettings::setReplyReportMessage(QString* reply_report_message) {
    this->reply_report_message = reply_report_message;
    this->m_reply_report_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getRrrMessage() {
    return rrr_message;
}
void
SWGChirpChatModSettings::setRrrMessage(QString* rrr_message) {
    this->rrr_message = rrr_message;
    this->m_rrr_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getMessage73() {
    return message73;
}
void
SWGChirpChatModSettings::setMessage73(QString* message73) {
    this->message73 = message73;
    this->m_message73_isSet = true;
}

QString*
SWGChirpChatModSettings::getQsoTextMessage() {
    return qso_text_message;
}
void
SWGChirpChatModSettings::setQsoTextMessage(QString* qso_text_message) {
    this->qso_text_message = qso_text_message;
    this->m_qso_text_message_isSet = true;
}

QString*
SWGChirpChatModSettings::getTextMessage() {
    return text_message;
}
void
SWGChirpChatModSettings::setTextMessage(QString* text_message) {
    this->text_message = text_message;
    this->m_text_message_isSet = true;
}

QList<QString*>*
SWGChirpChatModSettings::getBytesMessage() {
    return bytes_message;
}
void
SWGChirpChatModSettings::setBytesMessage(QList<QString*>* bytes_message) {
    this->bytes_message = bytes_message;
    this->m_bytes_message_isSet = true;
}

qint32
SWGChirpChatModSettings::getMessageRepeat() {
    return message_repeat;
}
void
SWGChirpChatModSettings::setMessageRepeat(qint32 message_repeat) {
    this->message_repeat = message_repeat;
    this->m_message_repeat_isSet = true;
}

qint32
SWGChirpChatModSettings::getRgbColor() {
    return rgb_color;
}
void
SWGChirpChatModSettings::setRgbColor(qint32 rgb_color) {
    this->rgb_color = rgb_color;
    this->m_rgb_color_isSet = true;
}

QString*
SWGChirpChatModSettings::getTitle() {
    return title;
}
void
SWGChirpChatModSettings::setTitle(QString* title) {
    this->title = title;
    this->m_title_isSet = true;
}

qint32
SWGChirpChatModSettings::getStreamIndex() {
    return stream_index;
}
void
SWGChirpChatModSettings::setStreamIndex(qint32 stream_index) {
    this->stream_index = stream_index;
    this->m_stream_index_isSet = true;
}

qint32
SWGChirpChatModSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGChirpChatModSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGChirpChatModSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGChirpChatModSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGChirpChatModSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGChirpChatModSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGChirpChatModSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGChirpChatModSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}

qint32
SWGChirpChatModSettings::getReverseApiChannelIndex() {
    return reverse_api_channel_index;
}
void
SWGChirpChatModSettings::setReverseApiChannelIndex(qint32 reverse_api_channel_index) {
    this->reverse_api_channel_index = reverse_api_channel_index;
    this->m_reverse_api_channel_index_isSet = true;
}


bool
SWGChirpChatModSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_input_frequency_offset_isSet){
            isObjectUpdated = true; break;
        }
        if(m_bandwidth_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_spread_factor_isSet){
            isObjectUpdated = true; break;
        }
        if(m_de_bits_isSet){
            isObjectUpdated = true; break;
        }
        if(m_preamble_chirps_isSet){
            isObjectUpdated = true; break;
        }
        if(m_quiet_millis_isSet){
            isObjectUpdated = true; break;
        }
        if(m_sync_word_isSet){
            isObjectUpdated = true; break;
        }
        if(m_channel_mute_isSet){
            isObjectUpdated = true; break;
        }
        if(m_coding_scheme_isSet){
            isObjectUpdated = true; break;
        }
        if(m_nb_parity_bits_isSet){
            isObjectUpdated = true; break;
        }
        if(m_has_crc_isSet){
            isObjectUpdated = true; break;
        }
        if(m_has_header_isSet){
            isObjectUpdated = true; break;
        }
        if(my_call && *my_call != QString("")){
            isObjectUpdated = true; break;
        }
        if(ur_call && *ur_call != QString("")){
            isObjectUpdated = true; break;
        }
        if(my_loc && *my_loc != QString("")){
            isObjectUpdated = true; break;
        }
        if(my_rpt && *my_rpt != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_message_type_isSet){
            isObjectUpdated = true; break;
        }
        if(beacon_message && *beacon_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(cq_message && *cq_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(reply_message && *reply_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(report_message && *report_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(reply_report_message && *reply_report_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(rrr_message && *rrr_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(message73 && *message73 != QString("")){
            isObjectUpdated = true; break;
        }
        if(qso_text_message && *qso_text_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(text_message && *text_message != QString("")){
            isObjectUpdated = true; break;
        }
        if(bytes_message && (bytes_message->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(m_message_repeat_isSet){
            isObjectUpdated = true; break;
        }
        if(m_rgb_color_isSet){
            isObjectUpdated = true; break;
        }
        if(title && *title != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_stream_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_channel_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

