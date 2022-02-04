#include <appcenter/sdk/ingestion/device.hpp>

namespace appcenter::sdk::ingestion {

const std::string_view Device::getSdkName() const { return sdkName; }
void Device::setSdkName(const std::string &sdkName) { this->sdkName = sdkName; }

const std::string_view Device::getSdkVersion() const { return sdkVersion; }
void Device::setSdkVersion(const std::string &sdkVersion) {
	this->sdkVersion = sdkVersion;
}

const std::string_view Device::getOsName() const { return osName; }
void Device::setOsName(const std::string &osName) { this->osName = osName; }

const std::string_view Device::getOsVersion() const { return osVersion; }
void Device::setOsVersion(const std::string &OsVersion) {
	this->osVersion = OsVersion;
}

const std::string_view Device::getLocale() const { return locale; }
void Device::setLocale(const std::string &locale) { this->locale = locale; }

const Timestamp &Device::getTimeZoneOffset() const { return timeZoneOffset; }
void Device::setTimeZoneOffset(const Timestamp &timeZoneOffset) {
	this->timeZoneOffset = timeZoneOffset;
}

const std::string_view Device::getWrapperSdkVersion() const {
	return wrapperSdkVersion;
}
void Device::setWrapperSdkVersion(const std::string &wrapperSdkVersion) {
	this->wrapperSdkVersion = wrapperSdkVersion;
}

const std::string_view Device::getWrapperSdkName() const {
	return wrapperSdkName;
}
void Device::setWrapperSdkName(const std::string &wrapperSdkName) {
	this->wrapperSdkName = wrapperSdkName;
}

const std::string_view Device::getModel() const { return model; }
void Device::setModel(const std::string &model) { this->model = model; }

const std::string_view Device::getOemName() const { return oemName; }
void Device::setOemName(const std::string &oemName) { this->oemName = oemName; }

const std::string_view Device::getOsBuild() const { return osBuild; }
void Device::setOsBuild(const std::string &osBuild) { this->osBuild = osBuild; }

const int Device::getOsApiLevel() const { return osApiLevel; }
void Device::setOsApiLevel(const int osApiLevel) {
	this->osApiLevel = osApiLevel;
}

const std::string_view Device::getScreenSize() const { return screenSize; }
void Device::setScreenSize(const std::string &screenSize) {
	this->screenSize = screenSize;
}

} // namespace appcenter::sdk::ingestion