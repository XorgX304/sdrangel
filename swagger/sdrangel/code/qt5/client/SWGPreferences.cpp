/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.11.3
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGPreferences.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGPreferences::SWGPreferences(QString* json) {
    init();
    this->fromJson(*json);
}

SWGPreferences::SWGPreferences() {
    source_type = nullptr;
    m_source_type_isSet = false;
    source_device = nullptr;
    m_source_device_isSet = false;
    audio_type = nullptr;
    m_audio_type_isSet = false;
    audio_device = nullptr;
    m_audio_device_isSet = false;
    source_index = 0;
    m_source_index_isSet = false;
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    console_min_log_level = 0;
    m_console_min_log_level_isSet = false;
    use_log_file = 0;
    m_use_log_file_isSet = false;
    log_file_name = nullptr;
    m_log_file_name_isSet = false;
    file_min_log_level = 0;
    m_file_min_log_level_isSet = false;
}

SWGPreferences::~SWGPreferences() {
    this->cleanup();
}

void
SWGPreferences::init() {
    source_type = new QString("");
    m_source_type_isSet = false;
    source_device = new QString("");
    m_source_device_isSet = false;
    audio_type = new QString("");
    m_audio_type_isSet = false;
    audio_device = new QString("");
    m_audio_device_isSet = false;
    source_index = 0;
    m_source_index_isSet = false;
    latitude = 0.0f;
    m_latitude_isSet = false;
    longitude = 0.0f;
    m_longitude_isSet = false;
    console_min_log_level = 0;
    m_console_min_log_level_isSet = false;
    use_log_file = 0;
    m_use_log_file_isSet = false;
    log_file_name = new QString("");
    m_log_file_name_isSet = false;
    file_min_log_level = 0;
    m_file_min_log_level_isSet = false;
}

void
SWGPreferences::cleanup() {
    if(source_type != nullptr) { 
        delete source_type;
    }
    if(source_device != nullptr) { 
        delete source_device;
    }
    if(audio_type != nullptr) { 
        delete audio_type;
    }
    if(audio_device != nullptr) { 
        delete audio_device;
    }





    if(log_file_name != nullptr) { 
        delete log_file_name;
    }

}

SWGPreferences*
SWGPreferences::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGPreferences::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&source_type, pJson["sourceType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&source_device, pJson["sourceDevice"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&audio_type, pJson["audioType"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&audio_device, pJson["audioDevice"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&source_index, pJson["sourceIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&latitude, pJson["latitude"], "float", "");
    
    ::SWGSDRangel::setValue(&longitude, pJson["longitude"], "float", "");
    
    ::SWGSDRangel::setValue(&console_min_log_level, pJson["consoleMinLogLevel"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_log_file, pJson["useLogFile"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log_file_name, pJson["logFileName"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&file_min_log_level, pJson["fileMinLogLevel"], "qint32", "");
    
}

QString
SWGPreferences::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGPreferences::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(source_type != nullptr && *source_type != QString("")){
        toJsonValue(QString("sourceType"), source_type, obj, QString("QString"));
    }
    if(source_device != nullptr && *source_device != QString("")){
        toJsonValue(QString("sourceDevice"), source_device, obj, QString("QString"));
    }
    if(audio_type != nullptr && *audio_type != QString("")){
        toJsonValue(QString("audioType"), audio_type, obj, QString("QString"));
    }
    if(audio_device != nullptr && *audio_device != QString("")){
        toJsonValue(QString("audioDevice"), audio_device, obj, QString("QString"));
    }
    if(m_source_index_isSet){
        obj->insert("sourceIndex", QJsonValue(source_index));
    }
    if(m_latitude_isSet){
        obj->insert("latitude", QJsonValue(latitude));
    }
    if(m_longitude_isSet){
        obj->insert("longitude", QJsonValue(longitude));
    }
    if(m_console_min_log_level_isSet){
        obj->insert("consoleMinLogLevel", QJsonValue(console_min_log_level));
    }
    if(m_use_log_file_isSet){
        obj->insert("useLogFile", QJsonValue(use_log_file));
    }
    if(log_file_name != nullptr && *log_file_name != QString("")){
        toJsonValue(QString("logFileName"), log_file_name, obj, QString("QString"));
    }
    if(m_file_min_log_level_isSet){
        obj->insert("fileMinLogLevel", QJsonValue(file_min_log_level));
    }

    return obj;
}

QString*
SWGPreferences::getSourceType() {
    return source_type;
}
void
SWGPreferences::setSourceType(QString* source_type) {
    this->source_type = source_type;
    this->m_source_type_isSet = true;
}

QString*
SWGPreferences::getSourceDevice() {
    return source_device;
}
void
SWGPreferences::setSourceDevice(QString* source_device) {
    this->source_device = source_device;
    this->m_source_device_isSet = true;
}

QString*
SWGPreferences::getAudioType() {
    return audio_type;
}
void
SWGPreferences::setAudioType(QString* audio_type) {
    this->audio_type = audio_type;
    this->m_audio_type_isSet = true;
}

QString*
SWGPreferences::getAudioDevice() {
    return audio_device;
}
void
SWGPreferences::setAudioDevice(QString* audio_device) {
    this->audio_device = audio_device;
    this->m_audio_device_isSet = true;
}

qint32
SWGPreferences::getSourceIndex() {
    return source_index;
}
void
SWGPreferences::setSourceIndex(qint32 source_index) {
    this->source_index = source_index;
    this->m_source_index_isSet = true;
}

float
SWGPreferences::getLatitude() {
    return latitude;
}
void
SWGPreferences::setLatitude(float latitude) {
    this->latitude = latitude;
    this->m_latitude_isSet = true;
}

float
SWGPreferences::getLongitude() {
    return longitude;
}
void
SWGPreferences::setLongitude(float longitude) {
    this->longitude = longitude;
    this->m_longitude_isSet = true;
}

qint32
SWGPreferences::getConsoleMinLogLevel() {
    return console_min_log_level;
}
void
SWGPreferences::setConsoleMinLogLevel(qint32 console_min_log_level) {
    this->console_min_log_level = console_min_log_level;
    this->m_console_min_log_level_isSet = true;
}

qint32
SWGPreferences::getUseLogFile() {
    return use_log_file;
}
void
SWGPreferences::setUseLogFile(qint32 use_log_file) {
    this->use_log_file = use_log_file;
    this->m_use_log_file_isSet = true;
}

QString*
SWGPreferences::getLogFileName() {
    return log_file_name;
}
void
SWGPreferences::setLogFileName(QString* log_file_name) {
    this->log_file_name = log_file_name;
    this->m_log_file_name_isSet = true;
}

qint32
SWGPreferences::getFileMinLogLevel() {
    return file_min_log_level;
}
void
SWGPreferences::setFileMinLogLevel(qint32 file_min_log_level) {
    this->file_min_log_level = file_min_log_level;
    this->m_file_min_log_level_isSet = true;
}


bool
SWGPreferences::isSet(){
    bool isObjectUpdated = false;
    do{
        if(source_type != nullptr && *source_type != QString("")){ isObjectUpdated = true; break;}
        if(source_device != nullptr && *source_device != QString("")){ isObjectUpdated = true; break;}
        if(audio_type != nullptr && *audio_type != QString("")){ isObjectUpdated = true; break;}
        if(audio_device != nullptr && *audio_device != QString("")){ isObjectUpdated = true; break;}
        if(m_source_index_isSet){ isObjectUpdated = true; break;}
        if(m_latitude_isSet){ isObjectUpdated = true; break;}
        if(m_longitude_isSet){ isObjectUpdated = true; break;}
        if(m_console_min_log_level_isSet){ isObjectUpdated = true; break;}
        if(m_use_log_file_isSet){ isObjectUpdated = true; break;}
        if(log_file_name != nullptr && *log_file_name != QString("")){ isObjectUpdated = true; break;}
        if(m_file_min_log_level_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

