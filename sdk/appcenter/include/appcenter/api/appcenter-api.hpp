#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <appcenter/service/services.hpp>
#include <string>

namespace appcenter::api::bindings {
/**
 * @brief AppCenter API c interface.
 *
 */
extern "C" {
class AppCenterAPIHandle;

/**
 * @brief returns the Log level of the SDK.
 *
 * @param handle the SDK handle.
 * @return appcenterAPI LogLevel_t the log level.
 */
appcenterAPI int APPCENTER_API_GET_LOG_LEVEL(AppCenterAPIHandle *handle);

/**
 * @brief Set the Log level of the SDK.
 *
 * @param handle the SDK handle.
 * @param logLevel the log level.
 */
appcenterAPI void APPCENTER_API_SET_LOG_LEVEL(AppCenterAPIHandle *handle,
                                              int logLevel);

/**
 * @brief Change the base URL used to send logs
 *
 * @param handle the SDK handle.
 * @param logUrl the new log URL.
 */
appcenterAPI void APPCENTER_API_SET_LOG_URL(AppCenterAPIHandle *handle,
                                            const char *logUrl);

/**
 * @brief Set the two-letter ISO country code.
 *
 * @param handle the SDK handle.
 * @param countryCode the two-letter ISO country code. See
 * <code>https://www.iso.org/obp/ui/#search</code> for more information.
 */
appcenterAPI void APPCENTER_API_SET_COUNTRY_CODE(AppCenterAPIHandle *handle,
                                                 const char *countryCode);

/**
 * @brief Get the current version of App Center SDK.
 *
 * @param handle the SDK handle.
 * @return The current version of App Center SDK.
 */
appcenterAPI const char *
APPCENTER_API_GET_SDK_VERSION(AppCenterAPIHandle *handle);

/**
 * @brief Check whether SDK has already been configured.
 *
 * @param handle the SDK handle.
 * @return int 1 if configured, 0 otherwise
 */
appcenterAPI int APPCENTER_API_IS_CONFIGURED(AppCenterAPIHandle *handle);

// TODO: there is not much sense to check if running in test cloud so those
// functions are not exported

/**
 * @brief Configure the SDK with an app secret.
 * @note This may be called only once per application process/handle lifetime.
 *
 * @param handle the SDK handle.
 * @param appSecret the app secret.
 */
appcenterAPI void APPCENTER_API_CONFIGURE(AppCenterAPIHandle *handle,
                                          const char *appSecret);

/**
 * @brief Configure the SDK witout an app secret.
 * @note This may be called only once per application process/handle lifetime.
 *
 * @param handle the SDK handle.
 */
appcenterAPI void
APPCENTER_API_CONFIGURE_WITHOUT_APP_SECRET(AppCenterAPIHandle *handle);

// TODO: design an interface to start app center and its services
// TODO: also, provide an C interface for the services

// TODO: design an interface for custom user defined loggers(logging)

// TODO: design an interface for isNetworkRequestsAllowed

/**
 * @brief Check whether the SDK is enabled or not as a whole.
 *
 * @param handle the SDK handle.
 * @return appcenterAPI int 1 if enabled, 0 otherwise
 */
appcenterAPI int APPCENTER_API_IS_ENABLED(AppCenterAPIHandle *handle);

/**
 * @brief Enable/Disable the SDK as a whole.
 *
 * @param handle the SDK handle.
 * @param enabled 1 to enable, 0 to disable
 */
appcenterAPI void APPCENTER_API_SET_ENABLED(AppCenterAPIHandle *handle,
                                            int enabled);

/**
 * @brief Get the unique installation identifier.
 *
 * @param handle the SDK handle.
 * @return const char* the installation identifier.
 */
appcenterAPI const char *
APPCENTER_API_GET_INSTALL_ID(AppCenterAPIHandle *handle);

/**
 * @brief Set the SQLite storage size.
 * @note Returns true if the operation succeeded. If the new size
 * is smaller than the previous size (database is shrinking) and the capacity is
 * greater than the new size, then the operation will fail and a warning will be
 * emitted. Can only be called once per app lifetime and only before
 * AppCenter.start(...)
 *
 * @param handle the SDK handle.
 * @param maxStorageSize New size for the SQLite db in bytes
 * @return int 1 if the operation succeeded, 0 otherwise
 */
appcenterAPI int
APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE(AppCenterAPIHandle *handle,
                                            int maxStorageSize);

/**
 * @brief Same as APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE but is
 * asynchronous.
 *
 * @param handle the SDK handle.
 * @param callback the callback to be called when the operation is done.
 */
appcenterAPI int APPCENTER_API_ASYNC_GET_MAX_STORAGE_SIZE(
    AppCenterAPIHandle *handle,
    void (*callback)(AppCenterAPIHandle *handle, int result));

// TODO: Add an interface for wrappers SDK, if it is in pimpl pattern is better.

/**
 * @brief returns a new AppCenter API handle, this handle is used to call
 * AppCenter API functions.
 *
 * @return appcenterAPI* handle to the new AppCenter API handle.
 */
appcenterAPI AppCenterAPIHandle *APPCENTER_API_CREATE_HANDLE();
/**
 * @brief Destroys the AppCenter API handle.
 *
 * @param handle the AppCenter API handle to destroy, if null does nothing.
 */
appcenterAPI void APPCENTER_API_DESTROY_HANDLE(AppCenterAPIHandle *handle);
}

} // namespace appcenter::api::bindings