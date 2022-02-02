#pragma once

#include <appcenter/constants.hpp>
#include <chrono>
#include <string>

namespace appcenter::core::ingestion {
/**
 * Contains the Device information.
 *
 * @note this class does not contain the app secret and install ID.
 *
 */
class Device {
	// required data
	std::string sdkName{constants::sdkName};
    // sdk version
	std::string sdkVersion{constants::sdkVersion};
    // OS name, ex: "Windows-UWP", "Linux", "MacOSX""
	std::string osName;
    // OS version, ex: "Ubuntu (kernel 4.4.0-53-generic), 64-bit", "Windows 10", "Mac OSX 10.12.6"
	std::string osVersion;
    // system locale, ex: "en-US"
	std::string locale;
	std::chrono::time_point<std::chrono::system_clock> timeZoneOffset;
	std::string appVersion;
	std::string appBuild;
	// non required data for ingestion
	std::string timestamp;
	std::string sid;
	std::string userID;
	std::string wrapperSdkVersion {constants::wrapperSdkVersion};
	std::string wrapperSdkName {constants::wrapperSdkName};
	std::string model;
	std::string oemName;
	std::string osBuild;
    // -1 means unknown
	int osApiLevel = -1;
	std::string screenSize;
	std::string appNamespace;
};
} // namespace appcenter::core::ingestion