#pragma once
#include <string_view>
#include <appcenter/sdk/utils/macros.hpp>

namespace appcenter::sdk::constants{
    constexpr std::string_view unknown_value = "Unknown";
    constexpr std::string_view sdkName = "appcenter.native";
    #ifdef APPCENTER_SDK_VERSION
    constexpr std::string_view sdkVersion = APPCENTER_SDK_VERSION;
    #else
    constexpr std::string_view sdkVersion = unknown_value;
    #endif
    constexpr std::string_view platform = APPCENTER_PLATFORM;
    // the native value of the wrapper SDK should be replaced by
    // the detected platform, ex: "NativeCPP.Linux", or "NativeCPP.Windows"
    constexpr std::string_view wrapperSdkVersion = "NativeCPP.Unknown/Generic";
    constexpr std::string_view wrapperSdkName = "appcenter.NativeCPP";
    constexpr std::string_view unknown_locale_iso_code = "xx_XX";
}