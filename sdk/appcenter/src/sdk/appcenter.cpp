#include <appcenter/sdk/appcenter.hpp>
#include <appcenter/sdk/constants.hpp>
#include <appcenter/sdk/core/logger.hpp>
#include <appcenter/sdk/service/service.hpp>
#include <appcenter/service/IService.hpp>
#include <vector>

namespace appcenter::sdk {

core::logging::LogLevel AppCenter::getLogLevel() const {
	return core::logging::Logger::getInstance().getLogLevel();
}

void AppCenter::setLogLevel(core::logging::LogLevel level) {
	core::logging::Logger::getInstance().setLogLevel(level);
}

void AppCenter::setLogUrl(const std::string_view logUrl) {
	this->logUrl = logUrl;
}

void AppCenter::setCountryCode(const std::string_view countryCode) {
	this->countryCode = countryCode;
}

const std::string_view AppCenter::getSdkVersion() const {
	return constants::sdkVersion;
}

const bool AppCenter::isConfigured() const { return this->configured; }

void AppCenter::configure(const std::string_view appSecret) {
	if (!isConfigured()) {
		this->configured = true;
		this->appSecret = appSecret;
	}
}

void AppCenter::start(const std::string_view appSecret,
                      std::vector<sdk::service::Service *> services) {
	if (!isConfigured()) {
		configure(appSecret);
		for (auto service : services) {
			start(service);
		}
	}
}

void AppCenter::start(sdk::service::Service *service) {
	// TODO: init the service
	// TODO: check if the service is already started
	// add the service to the list of services
	services.push_back(service);
}

const bool AppCenter::isEnabled() const { return enabled; }

void AppCenter::setEnabled(bool enabled) { this->enabled = enabled; }

const std::string_view AppCenter::getInstallId() const { return installId; }

const bool AppCenter::setMaxStorageSize(int maxStorageSize) {
	// TODO: add the StorageService
	return false;
}

const int AppCenter::getMaxStorageSize() {
	// TODO: add the StorageService
	return 0;
}

void AppCenter::startSDK() {}

void AppCenter::stopSDK() {}
} // namespace appcenter::sdk