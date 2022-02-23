#include <appcenter/sdk/appcenter.hpp>
#include <appcenter/sdk/constants.hpp>
#include <appcenter/sdk/core/logger.hpp>
#include <appcenter/sdk/service/service.hpp>
#include <appcenter/service/IService.hpp>
#include <libuuid/UUID.hpp>
#include <unordered_map>
#include <vector>

namespace appcenter::sdk {

AppCenter::AppCenter() { startSDK(); }

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
		getLogger().verbose(logTag, "Configuring App Center SDK.");

		// the secret map
		std::unordered_map<std::string, libUUID::UUID> secretMap;
		// validate app secret
		// TODO: add support for multiple app secrets on the same string
		// TODO: strip the app secrets from the string
		// check if the app secret is an valid UUID

		if (libUUID::UUID::is_valid(appSecret.data())) {
			getLogger().debug(
			    logTag, "No named identifier found in appSecret; using as-is");
			secretMap.insert(
			    std::make_pair("default", libUUID::UUID(appSecret.data())));
		} else {
			// TODO: check and strip the identifiers
			// the format is:
			// "android=397ac247-d473-44f6-a441-f0d84e22fb6e;" +
            // "uwp={Your UWP App secret here};" +
            // "ios={Your iOS App secret here};" +
            // "macos={Your macOS App secret here};
			// "{tag}={UUID};"
			// meanwhile we will fail if the app secret is not a valid UUID
			getLogger().error(logTag, "App secret is not a valid UUID.");
		}
		if (secretMap.empty()) {
			getLogger().warn(logTag, "Not found any valid app secret, "
			                         "configuring witouth app secret.");
			secretMap.insert(
			    std::make_pair(std::string("default"), libUUID::UUID()));
		}
		// search for an app secret which matches for the current platform
		// TODO: add support for setting the target platform
		// TODO: or automatically detect the target platform
		bool appSecretFound = false;
		for (auto &secret : secretMap) {
			if(secret.first == "default") {
				// we will use the default app secret if the current platform
				// is not found
				continue;
			}
			// meanwhile we will use the first app secret
			getLogger().debug(logTag, "Found app secret for platform: " + secret.first);
			// TODO: make this thread safe
			this->appSecret = secret.second;
			appSecretFound = true;
			break;
		}
		if (!appSecretFound) {
			// we will use the default app secret
			getLogger().debug(logTag, "Using default app secret.");
			// TODO: make this thread safe
			this->appSecret = secretMap.at("default");
		}
		

		this->configured = true;
	} else {
		getLogger().warn(logTag, "SDK is already configured.");
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
	if (service) {
		// TODO: init the service
		// TODO: check if the service is already started
		// add the service to the list of services
		services.push_back(service);
	} else {
		getLogger().error(logTag, "Cannot Start a null service.");
	}
}

const bool AppCenter::isEnabled() const { return enabled; }

void AppCenter::setEnabled(bool enabled) { this->enabled = enabled; }

const std::string_view AppCenter::getInstallId() const {
	return installId.to_string();
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