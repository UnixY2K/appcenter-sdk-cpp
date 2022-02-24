// appcenter SDK linux specific implementation
#include <appcenter/sdk/impl/platformInfo.hpp>
#include <memory>
#include <string>

namespace appcenter::sdk::impl {
namespace windows {} // namespace windows
namespace platform {

struct PlatformInfo::platformImplData {};

PlatformInfo::PlatformInfo() = default;
PlatformInfo::PlatformInfo(const PlatformInfo &other) {
	if (other.impl_info) {
		impl_info = std::make_unique<platformImplData>();
		// copy the impl_info
	} else {
		impl_info = nullptr;
	}
}
// we just move the impl_info
PlatformInfo::PlatformInfo(PlatformInfo &&other) noexcept = default;

const std::string_view PlatformInfo::getModel() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getOemName() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getOsName() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getOsVersion() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getOsBuild() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getLocale() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getScreenResolution() const {
	// TODO: implement
	return constants::unknown_value;
}

PlatformInfo &PlatformInfo::operator=(const PlatformInfo &other) {
	if (other.impl_info) {
		impl_info = std::make_unique<platformImplData>();
		// copy the impl_info
	} else {
		impl_info = nullptr;
	}
	return *this;
}
// same as move constructor
PlatformInfo &PlatformInfo::operator=(PlatformInfo &&other) noexcept = default;
PlatformInfo::~PlatformInfo() = default;
} // namespace platform
} // namespace appcenter::sdk::impl
