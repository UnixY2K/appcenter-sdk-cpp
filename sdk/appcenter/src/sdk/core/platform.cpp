#include <algorithm>
#include <appcenter/sdk/core/logger.hpp>
#include <appcenter/sdk/core/platform.hpp>
#include <appcenter/service/services.hpp>
#include <future>
#include <libuuid/UUID.hpp>

namespace appcenter::sdk::core {
const core::logging::LogLevel Platform::getPlatformLogLevel() const {
	return logging::Logger::getInstance().getLogLevel();
}
void Platform::setPlatformLogLevel(const core::logging::LogLevel level) {
	logging::Logger::getInstance().setLogLevel(level);
}
const bool Platform::isNetworkAllowed() const { return networkAllowed; }
void Platform::setNetworkAllowed(const bool allowed) {
	networkAllowed = allowed;
}
std::future<libUUID::UUID> Platform::getInstallIdAsync() {
	return std::async(std::launch::async,
	                  []() { return Platform::getInstance().getInstallId(); });
}
const libUUID::UUID Platform::getInstallId() {
	if (installId.to_string().empty()) {
		libUUID::UUID uuid = libUUID::UUID::generate();
		installId = std::move(uuid);
	}
	return installId;
}

void Platform::setLogUrl(const std::string &url) { logUrl = url; }

void Platform::setUserId(const std::string &userId) { this->userId = userId; }

void Platform::setCountryCode(const std::string &countryCode) {
	this->countryCode = countryCode;
}

const bool Platform::isConfigured() const { return configured; }

void Platform::configure(const std::string &appSecret) {
	configured = true;
	this->appSecret = appSecret;
	// TODO: setup logger level depending on build type
}

void Platform::start(const Services_t services) {}

void Platform::start(const std::string &appSecret, const Services_t services) {
	configure(appSecret);
	// TODO: start services
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