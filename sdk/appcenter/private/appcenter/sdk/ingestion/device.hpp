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
	std::string sdkName{constants::sdkName};
	// sdk version
	std::string sdkVersion{constants::sdkVersion};
	// OS name, ex: "Windows-UWP", "Linux", "MacOSX"", overwrite if needed
	std::string osName{constants::platform};
	// OS version, ex: "Ubuntu (kernel 4.4.0-53-generic), 64-bit", "Windows 10",
	// "Mac OSX 10.12.6"
	std::string osVersion{constants::unknown_value};
	// system locale, ex: "en-US"
	std::string locale{constants::unknown_locale_iso_code};
	Timestamp timeZoneOffset;
	// std::string appVersion;  // SDK instantiation specific
	// std::string appBuild;	// SDK instantiation specific
	// non required data for ingestion
	// std::string sid;		   // log/session specific
	// std::string userID;	   // log/session specific
	std::string wrapperSdkVersion{constants::wrapperSdkVersion};
	std::string wrapperSdkName{constants::wrapperSdkName};
	std::string model{constants::unknown_value};
	std::string oemName{constants::unknown_value};
	std::string osBuild{constants::unknown_value};
	// -1 means unknown
	int osApiLevel = -1;
	std::string screenSize{constants::unknown_value};
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

	const std::string_view getAppBuild() const;
	void setAppBuild(const std::string &appBuild);

	const std::string_view getSid() const;
	void setSid(const std::string &sid);

	const std::string_view getUserId() const;
	void setUserID(const std::string &userID);

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

	const std::string_view getAppNamespace() const;
	void setAppNamespace(const std::string &appNamespace);
};
} // namespace appcenter::sdk::ingestion