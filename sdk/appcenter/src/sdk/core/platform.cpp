#include <algorithm>
#include <appcenter/sdk/appcenter.hpp>
#include <appcenter/sdk/constants.hpp>
#include <appcenter/sdk/core/logger.hpp>
#include <appcenter/sdk/core/platform.hpp>
#include <appcenter/sdk/service/service.hpp>
#include <appcenter/sdk/storage/storageService.hpp>
#include <cfgpathpp/cfgpath.hpp>
#include <filesystem>
#include <fstream>
#include <future>
#include <libuuid/UUID.hpp>
#include <string>
#include <string_view>
#include <utility>

namespace appcenter::sdk::core {
const core::logging::LogLevel Platform::getPlatformLogLevel() const {
	return getLogger().getLogLevel();
}
void Platform::setPlatformLogLevel(const core::logging::LogLevel level) {
	getLogger().setLogLevel(level);
}
const bool Platform::isNetworkAllowed() const { return networkAllowed; }
void Platform::setNetworkAllowed(const bool allowed) {
	networkAllowed = allowed;
}
const libUUID::UUID Platform::getInstallId() {
	if (!installId.isEmpty() && installId.isValid()) {
		return installId;
	}
	getLogger().devel(logTag, "Install ID not cached, retrieving.");
	std::string appHash = cfgpathpp::generateAppHash();
	std::string path = cfgpathpp::getAppDataPath(
	    std::string(constants::appcenter_config_path) + "/" + appHash);
	// check if the file exists
	if (std::filesystem::exists(path)) {
		// read the file
		std::ifstream file(path + "/appid");
		std::string id;
		file >> id;
		// check if the id is valid
		if (libUUID::UUID::is_valid(id)) {
			getLogger().devel(logTag,
			                    "found valid install id in file:" + path);
			installId = libUUID::UUID(id);
		} else {
			getLogger().warn(logTag,
			                 "Invalid install id found in file: " + path);
		}
	}

	if (installId.to_string().empty()) {
		getLogger().verbose(logTag,
		                    "Install ID not found, generating a new one");
		libUUID::UUID uuid = libUUID::UUID::generate();
		installId = std::move(uuid);
		// save the id to file
		getLogger().verbose(logTag, "Saving install id to file: " + path);
		std::ofstream file(path + "/appid");
		file << installId.to_string();
	}
	return installId;
}

void Platform::setLogUrl(const std::string_view url) { logUrl = url; }

void Platform::setUserId(const std::string_view userId) {
	this->userId = userId;
}

void Platform::setCountryCode(const std::string_view countryCode) {
	this->countryCode = countryCode;
}

const bool Platform::isConfigured() const { return configured; }

void Platform::configure(const std::string_view appSecret) {
	if (!isConfigured()) {

		getLogger().devel(logTag, "Configuring App Center SDK.");

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
			if (secret.first == "default") {
				// we will use the default app secret if the current platform
				// is not found
				continue;
			}
			// meanwhile we will use the first app secret
			getLogger().debug(logTag,
			                  "Found app secret for platform: " + secret.first);
			// TODO: make this thread safe
			this->appSecret = secret.second;
			appSecretFound = true;
			break;
		}
		if (!appSecretFound) {
			// we will use the default app secret
			getLogger().devel(logTag, "Using default app secret.");
			// TODO: make this thread safe
			this->appSecret = secretMap.at("default");
		}
		// get the install ID
		std::string installId = getInstallId().to_string();
		// init the application directory
		std::string appPath = cfgpathpp::getAppDataPath(
		    std::string(constants::appconfig_path.data()) + "/" + installId);

		storage::StorageService::getInstance().init(appPath);

		this->configured = true;
	} else {
		getLogger().warn(logTag, "SDK is already configured.");
	}
	// TODO: setup logger level depending on build type
}

void Platform::start(service::Service *service) {
	if (service) {
		// TODO: init the service
		// TODO: check if the service is already started
		// add the service to the list of services
		services.push_back(service);
	} else {
		getLogger().error(logTag, "Cannot Start a null service.");
	}
}

void Platform::start(const std::vector<service::Service *> services) {
	if (isConfigured()) {
		for (auto service : services) {
			start(service);
		}
	}
	else{
		getLogger().warn(logTag, "SDK is not configured.");
	}
}

void Platform::start(const std::string_view appSecret,
                     const std::vector<service::Service *> services) {
	if (isConfigured()) {
		configure(appSecret);
		start(services);
	}
}

std::future<bool> Platform::setMaxStorageSizeAsync(size_t bytes) {
	return std::async(std::launch::async, [bytes]() {
		return Platform::getInstance().setMaxStorageSize(bytes);
	});
}

bool Platform::setMaxStorageSize(size_t bytes) {
	maxStorageSize = bytes;
	return true;
}

} // namespace appcenter::sdk::core