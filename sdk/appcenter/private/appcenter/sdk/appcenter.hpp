#pragma once
#include <appcenter/core/LogLevel.hpp>
#include <appcenter/sdk/service/service.hpp>
#include <appcenter/util/mixin/singleton.hpp>
#include <initializer_list>
#include <string>
#include <string_view>
#include <vector>

namespace appcenter::sdk {
class AppCenter : public util::mixin::Singleton<AppCenter> {
  public:
	/**
	 * @brief Get the Log Level object
	 *
	 * @return core::logging::LogLevel
	 */
	core::logging::LogLevel getLogLevel() const;

	/**
	 * @brief Set the Log level of the SDK.
	 *
	 * @param logLevel the log level.
	 */
	void setLogLevel(core::logging::LogLevel level);

	/**
	 * @brief Change the base URL used to send logs
	 *
	 * @param logUrl the new log URL.
	 */
	void setLogUrl(const std::string_view logUrl);

	/**
	 * @brief Set the two-letter ISO country code.
	 *
	 * @param countryCode the two-letter ISO country code. See
	 * <code>https://www.iso.org/obp/ui/#search</code> for more information.
	 */
	void setCountryCode(const std::string_view countryCode);

	/**
	 * @brief Get the current version of App Center SDK.
	 *
	 * @return The current version of App Center SDK.
	 */
	const std::string_view getSdkVersion() const;

	/**
	 * @brief Check whether SDK has already been configured.
	 *
	 * @return int 1 if configured, 0 otherwise
	 */
	const bool isConfigured() const;

	/**
	 * @brief Configure the SDK with an app secret.
	 * @note This may be called only once per application process/handle
	 * lifetime.
	 *
	 * @param appSecret the app secret, empty if none.
	 */
	void configure(const std::string_view appSecret = "");

	/**
	 * @brief start the App Center SDK.
	 *
	 * @param appSecret the app secret.
	 * @param services the services to start.
	 */
	void start(const std::string_view appSecret,
	           std::vector<sdk::service::Service *> services);
	/**
	 * @brief start the App Center SDK.
	 *
	 * @param service the service to start.
	 */
	void start(sdk::service::Service *service);

	/**
	 * @brief Check whether the SDK is enabled or not as a whole.
	 *
	 * @return int 1 if enabled, 0 otherwise
	 */
	const bool isEnabled() const;

	/**
	 * @brief Enable/Disable the SDK as a whole.
	 *
	 * @param enabled 1 to enable, 0 to disable
	 */
	void setEnabled(bool enabled);

	/**
	 * @brief Get the unique installation identifier.
	 *
	 * @return const char* the installation identifier.
	 */
	const std::string_view getInstallId() const;

	/**
	 * @brief Set the SQLite storage size.
	 * @note Returns true if the operation succeeded. If the new size
	 * is smaller than the previous size (database is shrinking) and the
	 * capacity is greater than the new size, then the operation will fail and a
	 * warning will be emitted. Can only be called once per app lifetime and
	 * only before AppCenter.start(...)
	 *
	 * @param maxStorageSize New size for the SQLite db in bytes
	 * @return int 1 if the operation succeeded, 0 otherwise
	 */
	const bool setMaxStorageSize(int maxStorageSize);

	/**
	 * @brief Same as APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE but is
	 * asynchronous.
	 *
	 * @return int the nax storage size in bytes
	 */
	const int getMaxStorageSize();

	/**
	 * @brief start the SDK core services.
	 *
	 * @return appcenterAPI* handle to the new AppCenter API handle.
	 */
	static void startSDK();

	/**
	 * @brief Stop the SDK services.
	 *
	 */
	static void stopSDK();

  private:
	// TODO: move this to the logger
	std::string logUrl;
	std::string countryCode;
	bool configured{false};
	std::string appSecret;
	std::vector<sdk::service::Service *> services;
	bool enabled{false};
	std::string installId;
};
} // namespace appcenter::sdk