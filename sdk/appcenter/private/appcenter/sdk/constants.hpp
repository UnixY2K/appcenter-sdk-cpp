#pragma once
#include <appcenter/sdk/utils/macros.hpp>
#include <cstddef>
#include <string_view>

namespace appcenter::sdk::constants {
constexpr std::string_view unknown_value = "Unknown";
constexpr std::string_view undefined_value = "Undefined";
constexpr std::string_view sdkName = "appcenter.native";
#ifdef APPCENTER_SDK_VERSION
constexpr std::string_view sdkVersion = APPCENTER_SDK_VERSION;
#else
constexpr std::string_view sdkVersion = unknown_value;
#endif
constexpr std::string_view platform = macros::APPCENTER_PLATFORM;
constexpr bool isUnix = macros::APPCENTER_PLATFORM == "Linux" ||
                        macros::APPCENTER_PLATFORM == "MacOSX" ||
                        macros::APPCENTER_PLATFORM == "BSD";
// the native value of the wrapper SDK should be replaced by
// the detected platform, ex: "NativeCPP.Linux", or "NativeCPP.Windows"
constexpr std::string_view wrapperSdkVersion = "NativeCPP.Unknown/Generic";
constexpr std::string_view wrapperSdkName = "appcenter.NativeCPP";
constexpr std::string_view unknown_locale_iso_code = "xx_XX";
// the default value of the storage size is 10MB, this value cannot be set to
// less than 20KB and is rounded my multiples of 4KB
constexpr std::size_t maxDBStorageSize{10 * 1024 * 1024};
// paths
// appcenter config of the app
constexpr std::string_view appconfig_path{"appcenter/native"};
// appcenter path where the internal data such install id is stored
constexpr std::string_view appcenter_config_path{"appcenter/config"};
} // namespace appcenter::sdk::constants