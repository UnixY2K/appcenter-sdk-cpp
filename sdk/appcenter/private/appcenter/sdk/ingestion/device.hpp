#pragma once

#include <appcenter/sdk/constants.hpp>
#include <chrono>
#include <string>
#include <string_view>

namespace appcenter::sdk::ingestion {
/**
 * Contains the Device information.
 *
 * @note this class does not contain the app secret and install ID.
 *
 */
using Timestamp = std::chrono::time_point<std::chrono::system_clock>;
class Device {
	// required data
	/**
	 * @brief Name of the SDK.
	 * @details Consists of the name of the SDK and the platform, e.g.
	 * "mobilecenter.ios", "mobilecenter.android".
	 */
	std::string sdkName{constants::sdkName};
	/**
	 * @brief Version of the SDK.
	 * @details Consists of the version of the SDK in semver format, e.g.
	 * "1.2.0" or "0.12.3-alpha.1".
	 */
	std::string sdkVersion{constants::sdkVersion};
	/**
	 * @brief Name of the OS.
	 * @details Os name, ex: "Windows-UWP", "Linux", "MacOSX".
	 */
	std::string osName{constants::platform};
	/**
	 * @brief Os version.
	 * @details Os version ex: "Ubuntu, 64-bit",
	 * "Windows 10".
	 */
	std::string osVersion{constants::unknown_value};
	/**
	 * @brief System Locale.
	 * @details Language code (example: en_US).
	 */
	std::string locale{constants::unknown_locale_iso_code};
	/**
	 * @brief System time zone offset.
	 * @details The offset in minutes from UTC for the device time zone,
	 * including daylight savings time.
	 */
	Timestamp timeZoneOffset;
	//# /**
	//#  * @brief Application version.
	//#  * @details Application version name, e.g. "1.2.0".
	//#  */
	// std::string appVersion;  // SDK instantiation specific
	// #/**
	// # * @brief App build.
	// # * @details App Build number (example: 42).
	// # */
	// std::string appBuild;	// SDK instantiation specific
	// non required data for ingestion
	// std::string sid;		   // log/session specific
	// std::string userID;	   // log/session specific
	std::string wrapperSdkVersion{constants::wrapperSdkVersion};
	std::string wrapperSdkName{constants::wrapperSdkName};
	/**
	 * @brief Device model.
	 * @details Device model (example: iPad2,3).
	 */
	std::string model{constants::unknown_value};
	/**
	 * @brief Name of the manufacturer.
	 * @details Name of the manufacturer (example: HTC).
	 */
	std::string oemName{constants::unknown_value};
	/**
	 * @brief Os build.
	 * @details Os build (example: Linux 4.4.0-53-generic).
	 */
	std::string osBuild{constants::unknown_value};
	/**
	 * @brief OS API level.
	 * @details API Level when applicable (example: 21), unknown is -1.
	 */
	int osApiLevel = -1;
	/**
	 * @brief Size of the screen;
	 * @details Scren size of the device in pixels (example: 1920x1080).
	 */
	std::string screenSize{constants::unknown_value};
	// /**
	//  * @brief App Namespace.
	//  * @details The bundle identifier, package identifier, or namespace,
	//  * depending on the individual platforms use, e.g. com.microsoft.example.
	//  */
	// std::string appNamespace; // SDK instantiation specific

  public:
	const std::string_view getSdkName() const;
	void setSdkName(const std::string &sdkName);

	const std::string_view getSdkVersion() const;
	void setSdkVersion(const std::string &sdkVersion);

	const std::string_view getOsName() const;
	void setOsName(const std::string &osName);

	const std::string_view getOsVersion() const;
	void setOsVersion(const std::string &OsVersion);

	const std::string_view getLocale() const;
	void setLocale(const std::string &locale);

	const Timestamp &getTimeZoneOffset() const;
	void setTimeZoneOffset(const Timestamp &timeZoneOffset);

	const std::string_view getAppVersion() const;
	void setAppVersion(const std::string &appVersion);

	const std::string_view getWrapperSdkVersion() const;
	void setWrapperSdkVersion(const std::string &wrapperSdkVersion);

	const std::string_view getWrapperSdkName() const;
	void setWrapperSdkName(const std::string &wrapperSdkName);

	const std::string_view getModel() const;
	void setModel(const std::string &model);

	const std::string_view getOemName() const;
	void setOemName(const std::string &oemName);

	const std::string_view getOsBuild() const;
	void setOsBuild(const std::string &osBuild);

	const int getOsApiLevel() const;
	void setOsApiLevel(const int osApiLevel);

	const std::string_view getScreenSize() const;
	void setScreenSize(const std::string &screenSize);
};
} // namespace appcenter::sdk::ingestion