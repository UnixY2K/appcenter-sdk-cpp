#pragma once
#include <appcenter/api/appcenter-api.hpp>
#include <appcenter/api/memory.hpp>
#include <appcenter/core/LogLevel.hpp>
#include <appcenter/private/exportAPI.hpp>
#include <appcenter/service/IService.hpp>
#include <appcenter/util/mixin/singleton.hpp>
#include <future>
#include <initializer_list>
#include <string>


namespace appcenter {
class AppCenter : public util::mixin::Singleton<AppCenter> {
	friend class util::mixin::Singleton<AppCenter>;

  protected:
	AppCenter() { startSDK(); }

  public:
	/**
	 * @brief Get the Log Level object
	 *
	 * @return core::logging::LogLevel
	 */
	core::logging::LogLevel getLogLevel() const {
		int logLevel = appcenter::api::bindings::APPCENTER_API_GET_LOG_LEVEL();
		// check bounds
		if (logLevel < 0 ||
		    logLevel > static_cast<int>(core::logging::LogLevel::None)) {
			logLevel = 0;
		}
		return static_cast<core::logging::LogLevel>(logLevel);
	}

	/**
	 * @brief Set the Log level of the SDK.
	 *
	 * @param logLevel the log level.
	 */
	void setLogLevel(core::logging::LogLevel level) {
		appcenter::api::bindings::APPCENTER_API_SET_LOG_LEVEL(
		    static_cast<int>(level));
	}

	/**
	 * @brief Change the base URL used to send logs
	 *
	 * @param logUrl the new log URL.
	 */
	void setLogUrl(const std::string_view logUrl) {
		if (!logUrl.empty()) {
			appcenter::api::bindings::APPCENTER_API_SET_LOG_URL(logUrl.data());
		}
	}

	/**
	 * @brief Set the two-letter ISO country code.
	 *
	 * @param countryCode the two-letter ISO country code. See
	 * <code>https://www.iso.org/obp/ui/#search</code> for more information.
	 */
	void setCountryCode(const std::string_view countryCode) {
		if (!countryCode.empty()) {
			appcenter::api::bindings::APPCENTER_API_SET_COUNTRY_CODE(
			    countryCode.data());
		}
	}

	/**
	 * @brief Get the current version of App Center SDK.
	 *
	 * @return The current version of App Center SDK.
	 */
	const std::string getSdkVersion() const {
		return api::memory::makeString(
		    appcenter::api::bindings::APPCENTER_API_GET_SDK_VERSION());
	}

	/**
	 * @brief Check whether SDK has already been configured.
	 *
	 * @return int 1 if configured, 0 otherwise
	 */
	const bool isConfigured() const {
		return appcenter::api::bindings::APPCENTER_API_IS_CONFIGURED() != 0;
	}

	/**
	 * @brief Configure the SDK with an app secret.
	 * @note This may be called only once per application process/handle
	 * lifetime.
	 *
	 * @param appSecret the app secret, empty if none.
	 */
	void configure(const std::string_view appSecret = "") {
		if (appSecret.empty()) {
			appcenter::api::bindings::APPCENTER_API_CONFIGURE(nullptr);
		} else {
			appcenter::api::bindings::APPCENTER_API_CONFIGURE(appSecret.data());
		}
	}

	/**
	 * @brief start the App Center SDK.
	 *
	 * @param appSecret the app secret.
	 * @param services the services to start.
	 */
	void start(const std::string_view appSecret,
	           std::initializer_list<service::IService *> services) {
		// setup the memory::Array_t first
		api::memory::Array_t *servicesArray = api::memory::makeArray(services);
		// start the SDK, the array is freed by the SDK
		const char *appSecretCStr =
		    appSecret.empty() ? nullptr : appSecret.data();
		appcenter::api::bindings::APPCENTER_API_START(appSecretCStr,
		                                              servicesArray);
	}

	/**
	 * @brief start the App Center SDK.
	 *
	 * @param service the service to start.
	 */
	void start(service::IService *service) {
		if (service) {
			appcenter::api::bindings::APPCENTER_API_START_SERVICE(service);
		}
	}

	/**
	 * @brief Check whether the SDK is enabled or not as a whole.
	 *
	 * @return int 1 if enabled, 0 otherwise
	 */
	const bool isEnabled() const {
		return appcenter::api::bindings::APPCENTER_API_IS_ENABLED() != 0;
	}

	/**
	 * @brief Enable/Disable the SDK as a whole.
	 *
	 * @param enabled 1 to enable, 0 to disable
	 */
	void setEnabled(bool enabled) {
		appcenter::api::bindings::APPCENTER_API_SET_ENABLED(enabled);
	}

	/**
	 * @brief Get the unique installation identifier.
	 *
	 * @return const char* the installation identifier.
	 */
	const std::string getInstallId() const {
		return api::memory::makeString(
		    appcenter::api::bindings::APPCENTER_API_GET_INSTALL_ID());
	}

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
	const bool setMaxStorageSize(int maxStorageSize) {
		return appcenter::api::bindings::
		           APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE(
		               maxStorageSize) != 0;
	}

	/**
	 * @brief Same as APPCENTER_API_BLOCKING_SET_MAX_STORAGE_SIZE but is
	 * asynchronous.
	 *
	 * @param callback the callback to be called when the operation is done.
	 */
	std::future<bool> getMaxStorageSize() {
		return std::async(std::launch::async, []() {
			return api::bindings::
			           APPCENTER_API_BLOCKING_GET_MAX_STORAGE_SIZE() != 0;
		});
	}

  private:
	/**
	 * @brief start the SDK core services.
	 *
	 * @return appcenterAPI* handle to the new AppCenter API handle.
	 */
	static void startSDK() {
		appcenter::api::bindings::APPCENTER_API_INIT_SDK();
	}

	/**
	 * @brief Stop the SDK services.
	 *
	 */
	static void stopSDK() {
		appcenter::api::bindings::APPCENTER_API_STOP_SDK();
	}
};
} // namespace appcenter
