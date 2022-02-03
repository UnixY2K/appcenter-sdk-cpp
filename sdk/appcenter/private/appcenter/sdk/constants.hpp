#pragma once
#include <string_view>

namespace appcenter::sdk::constants{
    constexpr std::string_view sdkName = "appcenter.native";
    #ifdef APPCENTER_SDK_VERSION
    constexpr std::string_view sdkVersion = APPCENTER_SDK_VERSION;
    #else
    constexpr std::string_view sdkVersion = "unknown";
    #endif
    // the native value of the wrapper SDK should be replaced by
    // the detected platform, ex: "NativeCPP.Linux", or "NativeCPP.Windows"
    constexpr std::string_view wrapperSdkVersion = "NativeCPP.Unknown/Generic";
    constexpr std::string_view wrapperSdkName = "appcenter.NativeCPP";
}