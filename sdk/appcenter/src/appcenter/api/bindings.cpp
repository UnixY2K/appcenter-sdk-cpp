#include <appcenter/api/memory.hpp>
#include <appcenter/sdk/service/service.hpp>
#include <cstddef>
#include <string_view>
#define appcenterLIBRARY_EXPORT
#include <appcenter/api/appcenter-api.hpp>
#include <appcenter/sdk/appcenter.hpp>

namespace appcenter::api::bindings {
const char *copyString(const std::string_view sv) {
	auto *str = new char[sv.size() + 1];
	std::copy(sv.begin(), sv.end(), str);
	str[sv.size()] = '\0';
	return str;
}

extern "C" {
/**
 * @brief returns the Log level of the SDK.
 *
 * @return appcenterAPI LogLevel_t the log level.
 */
appcenterAPI int APPCENTER_API_GET_LOG_LEVEL() {
	return static_cast<int>(sdk::AppCenter::getInstance().getLogLevel());
}

/**
 * @brief Set the Log level of the SDK.
 *
 * @param logLevel the log level.
 */
appcenterAPI void APPCENTER_API_SET_LOG_LEVEL(int logLevel) {
	sdk::AppCenter::getInstance().setLogLevel(
	    static_cast<core::logging::LogLevel>(logLevel));
}

/**
 * @brief Change the base URL used to send logs
 *
 * @param logUrl the new log URL.
 */
appcenterAPI void APPCENTER_API_SET_LOG_URL(const char *logUrl) {
	sdk::AppCenter::getInstance().setLogUrl(logUrl ? logUrl : "");
}

/**
 * @brief Set the two-letter ISO country code.
 *
 * @param countryCode the two-letter ISO country code. See
 * <code>https://www.iso.org/obp/ui/#search</code> for more information.
 */
appcenterAPI void APPCENTER_API_SET_COUNTRY_CODE(const char *countryCode) {
	sdk::AppCenter::getInstance().setCountryCode(countryCode ? countryCode
	                                                         : "");
}

/**
 * @brief Get the current version of App Center SDK.
 *
 * @return The current version of App Center SDK.
 */
appcenterAPI const char *APPCENTER_API_GET_SDK_VERSION() {
	return copyString(sdk::AppCenter::getInstance().getSdkVersion());
}

/**
 * @brief Check whether SDK has already been configured.
 *
 * @return int 1 if configured, 0 otherwise
 */
appcenterAPI int APPCENTER_API_IS_CONFIGURED() {
	return sdk::AppCenter::getInstance().isConfigured() ? 1 : 0;
}

/**
 * @brief Configure the SDK with an app secret.
 * @note This may be called only once per application process/handle lifetime.
 *
 * @param appSecret the app secret, null if none.
 */
appcenterAPI void APPCENTER_API_CONFIGURE(const char *appSecret) {
	// TODO: implement
	sdk::AppCenter::getInstance().configure(appSecret);
}

// TODO: design an interface to start app center and its services

/**
 * @brief start the App Center SDK.
 *
 * @param appSecret the app secret.
 * @param services the services to start.
 */
appcenterAPI void APPCENTER_API_START(const char *appSecret,
                                      memory::Array_t *services) {
	std::vector<sdk::service::Service *> services_;
	if (services) {
		for (std::size_t i = 0; i < services->size; i++) {
			services_.push_back(
			    reinterpret_cast<sdk::service::Service *>(services->data[i]));
		}
		api::memory::APPCENTER_API_UTIL_DEALLOCATE_ARRAY(services);
	}
	sdk::AppCenter::getInstance().start(appSecret, services_);
}

/**
 * @brief start the App Center SDK.
 *
 * @param service the service to start.
 */
appcenterAPI void APPCENTER_API_START_SERVICE(service::IService *service) {
	if (service) {
		sdk::service::Service *service_ =
		    reinterpret_cast<sdk::service::Service *>(service);
		sdk::AppCenter::getInstance().start(service_);
	}
}

/**
 * @brief Check whether the SDK is enabled or not as a whole.
 *
 * @return appcenterAPI int 1 if enabled, 0 otherwise
 */
appcenterAPI int APPCENTER_API_IS_ENABLED() {
	return sdk::AppCenter::getInstance().isEnabled() ? 1 : 0;
}

/**
 * @brief Enable/Disable the SDK as a whole.
 *
 * @param enabled 1 to enable, 0 to disable
 */
appcenterAPI void APPCENTER_API_SET_ENABLED(int enabled) {
	sdk::AppCenter::getInstance().setEnabled(enabled != 0);
}

/**
 * @brief Get the unique installation identifier.
 *
 * @return const char* the installation identifier.
 */
appcenterAPI const char *APPCENTER_API_GET_INSTALL_ID() {
	return copyString(sdk::AppCenter::getInstance().getInstallId());
}

/**
 * @brief Set the SQLite storage size.
 * @note Returns true if the operation succeeded. If the new size
 * is smaller than the previous size (database is shrinking) and the capacity is
 * greater than the new size, then the operation will fail and a warning will be
 * emitted. Can only be called once per app lifetime and only before
 * AppCenter.start(...)
 *
 * @param maxStorageSize New size for the SQLite db in bytes
 * @return int 1 if the operation succeeded, 0 otherwise
 */
appcenterAPI int
APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE(int maxStorageSize) {
	return sdk::AppCenter::getInstance().setMaxStorageSize(maxStorageSize) ? 1
	                                                                       : 0;
}

/**
 * @brief return the current max storage size in bytes.
 *
 * @return int the current max storage size in bytes.
 */
appcenterAPI int APPCENTER_API_BLOCKING_GET_MAX_STORAGE_SIZE() {
	return sdk::AppCenter::getInstance().getMaxStorageSize();
}

// TODO: Add an interface for wrappers SDK, if it is in pimpl pattern is better.

/**
 * @brief start the SDK core services.
 *
 * @return appcenterAPI* handle to the new AppCenter API handle.
 */
appcenterAPI void APPCENTER_API_INIT_SDK() { sdk::AppCenter::startSDK(); }

/**
 * @brief Stop the SDK services.
 *
 */
appcenterAPI void APPCENTER_API_STOP_SDK() { sdk::AppCenter::stopSDK(); }
}

} // namespace appcenter::api::bindings