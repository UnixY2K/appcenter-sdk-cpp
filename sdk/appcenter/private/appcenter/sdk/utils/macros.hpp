#pragma once
#include <string_view>

// macros definitions for constants

namespace appcenter::sdk::macros {
constexpr std::string_view APPCENTER_GENERIC_PLATFORM = "Unknown/Generic";
constexpr std::string_view APPCENTER_UWP_PLATFORM = "UWP";
constexpr std::string_view APPCENTER_WINDOWS_PLATFORM = "Windows";
constexpr std::string_view APPCENTER_LINUX_PLATFORM = "Linux";
constexpr std::string_view APPCENTER_MACOS_PLATFORM = "MacOSX";
// NOTE: BSD is not planned to be supported
constexpr std::string_view APPCENTER_BSD_PLATFORM = "BSD";
} // namespace appcenter::sdk::macros

// check if is uwp, windows, linux, macosx
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
// Windows Store or Universal Windows Platform
#define APPCENTER_MACRO_PLATFORM appcenter::sdk::macros::APPCENTER_UWP_PLATFORM
#elif defined(_WIN32)
// Windows Desktop
#define APPCENTER_MACRO_PLATFORM                                               \
	appcenter::sdk::macros::APPCENTER_WINDOWS_PLATFORM
#elif defined(__linux__)
// linux
#define APPCENTER_MACRO_PLATFORM                                               \
	appcenter::sdk::macros::APPCENTER_LINUX_PLATFORM
#elif defined(__APPLE__) && defined(__MACH__)
// Mac OSX
#define APPCENTER_MACRO_PLATFORM                                               \
	appcenter::sdk::macros::APPCENTER_MACOS_PLATFORM
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||   \
    defined(__bsdi__) || defined(__DragonFly__)
// bsd
#define APPCENTER_MACRO_PLATFORM appcenter::sdk::macros::APPCENTER_BSD_PLATFORM
#else
// unknown
#define APPCENTER_MACRO_PLATFORM                                               \
	appcenter::sdk::macros::APPCENTER_GENERIC_PLATFORM
#endif

namespace appcenter::sdk::macros {
constexpr std::string_view APPCENTER_PLATFORM = APPCENTER_MACRO_PLATFORM;
}