#pragma once
#include <string>

namespace appcenter {
namespace common {
class Device {
  public:
	/**
	 * @brief Name of the SDK.
	 * @details Consists of the name of the SDK and the platform, e.g.
	 * "mobilecenter.ios", "mobilecenter.android".
	 */
	std::string SdkName;

	/**
	 * @brief Version of the SDK.
	 * @details Consists of the version of the SDK in semver format, e.g.
	 * "1.2.0" or "0.12.3-alpha.1".
	 */
	const std::string SdkVersion;

	/**
	 * @brief Device model.
	 * @details Device model (example: iPad2,3).
	 */
	const std::string Model;

	/**
	 * @brief Name of the manufacturer.
	 * @details Name of the manufacturer (example: HTC).
	 */
	const std::string OemName;

	/**
	 * @brief Name of the OS.
	 * @details Os name (example: iOS).
	 */
	const std::string OsName;

	/**
	 * @brief Os version.
	 * @details Os version (example: 9.3.0).
	 */
	const std::string OsVersion;

	/**
	 * @brief Os build.
	 * @details Os build (example: LMY47X).
	 */
	const std::string OsBuild;

	/**
	 * @brief OS API level.
	 * @details API Level when applicable (example: 21).
	 */
	const std::string OsApiLevel;

	/**
	 * @brief System Locale.
	 * @details Language code (example: en_US).
	 */
	const std::string Locale;

	/**
	 * @brief System time zone offset.
	 * @details The offset in minutes from UTC for the device time zone,
	 * including daylight savings time.
	 */
	const int TimeZoneOffset;

	/**
	 * @brief Size of the screen;
	 * @details Scren size of the device in pixels (example: 1920x1080).
	 */
	const std::string ScreenSize;

	/**
	 * @brief Application version.
	 * @details Application version name, e.g. "1.2.0".
	 */
	const std::string AppVersion;

	/**
	 * @brief Carrier Name.
	 * @details name of the carrier[mobile devices] (example: Verizon).
	 */
	const std::string CarrierName;

	/**
	 * @brief Carrier country code.
	 * @details Carrier country code[mobile devices] (example: +506).
	 */
	const std::string CarrierCountry;

	/**
	 * @brief App build.
	 * @details App Build number (example: 42).
	 */
	const std::string AppBuild;

	/**
	 * @brief App Namespace.
	 * @details The bundle identifier, package identifier, or namespace,
	 * depending on the individual platforms use, e.g. com.microsoft.example.
	 */
	const std::string AppNamespace;
};
} // namespace common
} // namespace appcenter