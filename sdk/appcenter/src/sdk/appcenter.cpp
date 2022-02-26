#include <appcenter/sdk/appcenter.hpp>
#include <appcenter/sdk/constants.hpp>
#include <appcenter/sdk/core/logger.hpp>
#include <appcenter/sdk/core/platform.hpp>
#include <appcenter/sdk/service/service.hpp>
#include <appcenter/service/IService.hpp>
#include <libuuid/UUID.hpp>
#include <unordered_map>
#include <vector>

namespace appcenter::sdk {

AppCenter::AppCenter() { startSDK(); }

core::logging::LogLevel AppCenter::getLogLevel() const {
	return sdk::core::Platform::getInstance().getPlatformLogLevel();
}

void AppCenter::setLogLevel(core::logging::LogLevel level) {
	sdk::core::Platform::getInstance().setPlatformLogLevel(level);
}

void AppCenter::setLogUrl(const std::string_view logUrl) {
	sdk::core::Platform::getInstance().setLogUrl(logUrl);
}

void AppCenter::setCountryCode(const std::string_view countryCode) {
	sdk::core::Platform::getInstance().setCountryCode(countryCode);
}

const std::string_view AppCenter::getSdkVersion() const {
	return constants::sdkVersion;
}

const bool AppCenter::isConfigured() const {
	return core::Platform::getInstance().isConfigured();
}

void AppCenter::configure(const std::string_view appSecret) {
	core::Platform::getInstance().configure(appSecret);
}

void AppCenter::start(const std::string_view appSecret,
                      std::vector<sdk::service::Service *> services) {
	core::Platform::getInstance().start(appSecret, services);
}

void AppCenter::start(sdk::service::Service *service) {
	core::Platform::getInstance().start(service);
}

const bool AppCenter::isEnabled() const { return enabled; }

void AppCenter::setEnabled(bool enabled) { this->enabled = enabled; }

const std::string_view AppCenter::getInstallId() const {
	return sdk::core::Platform::getInstance().getInstallId().to_string();
}

const bool AppCenter::setMaxStorageSize(int maxStorageSize) {
	// TODO: add the StorageService
	return false;
}

const int AppCenter::getMaxStorageSize() {
	// TODO: add the StorageService
	return 0;
}

sdk::core::logging::Logger &AppCenter::getLogger() const {
	return core::logging::Logger::getInstance();
}

void AppCenter::startSDK() {
	if (!sdkStarted) {
		sdkStarted = true;
		getLogger().verbose(logTag, "Starting SDK");
	} else {
		getLogger().warn(logTag, "SDK already started");
	}
}

void AppCenter::stopSDK() {
	if (sdkStarted) {
		sdkStarted = false;
		getLogger().verbose(logTag, "Stopping SDK");
	} else {
		getLogger().warn(logTag, "SDK already stopped");
	}
}
} // namespace appcenter::sdk