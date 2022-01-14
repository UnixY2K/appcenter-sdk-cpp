#pragma once
#include <appcenter/common/LogLevel.hpp>
#include <appcenter/service/services.hpp>
#include <future>
#include <string>

// GUID
#include <appcenter/util/UUID.hpp>

namespace appcenter {
namespace SDK {
namespace platform {
// Error message to display for unsupported targets
const std::string &getErrorMessage();

/**
 * @brief Get the Platform Log Level object
 *
 * @return the Platform Log Level
 */
common::LogLevel getPlatformLogLevel();
/**
 * @brief Set the Platform Log Level object
 *
 * @param logLevel the Platform Log Level
 */
void setPlatformLogLevel(common::LogLevel level);

/**
 * @brief Get if Network requests are allowed
 *
 */
bool isNetworkAllowed();

/**
 * @brief Set if Network requests are allowed
 *
 */
void setNetworkAllowed(bool allowed);

// ignore PlatformIsEnabledAsync
// ignore PlatformSetEnabledAsync

/**
 * @brief return the InstallID asynchronously
 *
 */
std::future<appcenter::util::UUID> getInstallIdAsync();

/**
 * @brief sets the Log URL
 */
void setLogUrl(const std::string &url);

/**
 * @brief sets the userId
 */
void setUserId(const std::string &userId);

/**
 * @brief sets the country code
 * 
 * @param countryCode the two-letter ISO country code
 */
void setCountryCode(const std::string &countryCode);

/**
 * @brief check if the platform is configured
 *
 * @return true the platform is configured
 * @return false the platform is not configured
 */
bool isConfigured();

/**
 * @brief configure the platform with the given app secret
 *
 * @param appSecret the app secret
 */
void configure(const std::string &appSecret);

/**
 * @brief start the given services
 */
void start(Services_t services);

/**
 * @brief start the given services
 *
 * @param appSecret the app secret
 * @param services the services to start
 */
void start(const std::string &appSecret, Services_t services);

/**
 * @brief Set the Max Storage Size for App Center
 *
 * @param bytes the max storage size in bytes
 * @return std::future<bool> the future of the operation
 */
std::future<bool> setMaxStorageSizeAsync(size_t bytes);

void unsetInstance();

} // namespace platform
} // namespace SDK
} // namespace appcenter