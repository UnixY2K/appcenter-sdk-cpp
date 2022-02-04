#pragma once

// macros definitions for constants


#define APPCENTER_GENERIC_PLATFORM "Unknown/Generic"
// check if is uwp, windows, linux, macosx
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
// Windows Store or Universal Windows Platform
#define APPCENTER_PLATFORM "UWP"
#elif defined(_WIN32)
// Windows Desktop
#define APPCENTER_PLATFORM "Windows"
#elif defined(__linux__)
// linux
#define APPCENTER_PLATFORM "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
// Mac OSX
#define APPCENTER_PLATFORM "MacOSX"
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) ||   \
    defined(__bsdi__) || defined(__DragonFly__)
// bsd
#define APPCENTER_PLATFORM "BSD"
#else
// unknown
#define APPCENTER_PLATFORM APPCENTER_GENERIC_PLATFORM
#endif
