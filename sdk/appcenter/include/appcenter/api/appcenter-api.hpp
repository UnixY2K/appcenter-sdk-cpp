#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <appcenter/service/IService.hpp>
#include <appcenter/api/memory.hpp>

namespace appcenter::api::bindings {
/**
 * @brief AppCenter API c interface.
 *
 */
extern "C" {

/**
 * @brief returns the Log level of the SDK.
 *
 * @return appcenterAPI LogLevel_t the log level.
 */
appcenterAPI int APPCENTER_API_GET_LOG_LEVEL();

/**
 * @brief Set the Log level of the SDK.
 *
 * @param logLevel the log level.
 */
appcenterAPI void APPCENTER_API_SET_LOG_LEVEL(int logLevel);

/**
 * @brief Change the base URL used to send logs
 *
 * @param logUrl the new log URL.
 */
appcenterAPI void APPCENTER_API_SET_LOG_URL(const char *logUrl);

/**
 * @brief Set the two-letter ISO country code.
 *
 * @param countryCode the two-letter ISO country code. See
 * <code>https://www.iso.org/obp/ui/#search</code> for more information.
 */
appcenterAPI void APPCENTER_API_SET_COUNTRY_CODE(const char *countryCode);

/**
 * @brief Get the current version of App Center SDK.
 *
 * @return The current version of App Center SDK.
 */
appcenterAPI const char *APPCENTER_API_GET_SDK_VERSION();

/**
 * @brief Check whether SDK has already been configured.
 *
 * @return int 1 if configured, 0 otherwise
 */
appcenterAPI int APPCENTER_API_IS_CONFIGURED();

/**
 * @brief Configure the SDK with an app secret.
 * @note This may be called only once per application process/handle lifetime.
 *
 * @param appSecret the app secret.
 */
appcenterAPI void APPCENTER_API_CONFIGURE(const char *appSecret);

/**
 * @brief Configure the SDK witout an app secret.
 * @note This may be called only once per application process/handle lifetime.
 *
 */
appcenterAPI void APPCENTER_API_CONFIGURE_WITHOUT_APP_SECRET();

// TODO: design an interface to start app center and its services

/**
 * @brief start the App Center SDK.
 * 
 * @param appSecret the app secret.
 * @param services the services to start.
 */
appcenterAPI void APPCENTER_API_START(const char* appSecret, memory::Array_t* services);

/**
 * @brief start the App Center SDK.
 * 
 * @param service the service to start.
 */
appcenterAPI void APPCENTER_API_START_SERVICE(service::IService* service);

// TODO: also, provide an C interface for the services

// TODO: design an interface for custom user defined loggers(logging)

// TODO: design an interface for isNetworkRequestsAllowed

/**
 * @brief Check whether the SDK is enabled or not as a whole.
 *
 * @return appcenterAPI int 1 if enabled, 0 otherwise
 */
appcenterAPI int APPCENTER_API_IS_ENABLED();

/**
 * @brief Enable/Disable the SDK as a whole.
 *
 * @param enabled 1 to enable, 0 to disable
 */
appcenterAPI void APPCENTER_API_SET_ENABLED(int enabled);

/**
 * @brief Get the unique installation identifier.
 *
 * @return const char* the installation identifier.
 */
appcenterAPI const char *APPCENTER_API_GET_INSTALL_ID();

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
APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE(int maxStorageSize);

/**
 * @brief Same as APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE but is
 * asynchronous.
 *
 * @param callback the callback to be called when the operation is done.
 */
appcenterAPI int
APPCENTER_API_ASYNC_GET_MAX_STORAGE_SIZE(void (*callback)(int result));

// TODO: Add an interface for wrappers SDK, if it is in pimpl pattern is better.

/**
 * @brief start the SDK core services.
 *
 * @return appcenterAPI* handle to the new AppCenter API handle.
 */
appcenterAPI void APPCENTER_API_INIT_SDK();

/**
 * @brief Stop the SDK services.
 *
 */
appcenterAPI void APPCENTER_API_STOP_SDK();
}

} // namespace appcenter::api::bindings