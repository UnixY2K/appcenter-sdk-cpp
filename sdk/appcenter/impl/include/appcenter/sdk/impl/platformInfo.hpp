#pragma once
#include <appcenter/sdk/constants.hpp>
#include <memory>
#include <string_view>

namespace appcenter::sdk::impl {
namespace platform {
namespace constants {
constexpr std::string_view unknown_value = sdk::constants::unknown_value;
constexpr std::string_view undefined_value = sdk::constants::undefined_value;
} // namespace constants

class PlatformInfo {
	struct platformImplData;
	// Pimpl
	std::unique_ptr<platformImplData> impl_info = nullptr;

  public:
	PlatformInfo();
	PlatformInfo(const PlatformInfo &other);
	PlatformInfo(PlatformInfo &&other) noexcept;

	const std::string_view getModel() const;
	const std::string_view getOemName() const;
	const std::string_view getOsName() const;
	const std::string_view getOsVersion() const;
	const std::string_view getOsBuild() const;
	const std::string_view getLocale() const;
	const std::string_view getScreenResolution() const;

	PlatformInfo &operator=(const PlatformInfo &other);
	PlatformInfo &operator=(PlatformInfo &&other) noexcept;
	~PlatformInfo();
	static PlatformInfo getPlatformInfo();
};
} // namespace platform

} // namespace appcenter::sdk::impl