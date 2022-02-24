// appcenter SDK linux specific implementation
#include <appcenter/sdk/impl/platformInfo.hpp>
#include <locale>
#include <memory>
#include <string>
#include <string_view>
#include <sys/utsname.h>
#include <unistd.h>

namespace appcenter::sdk::impl {
namespace linux {
std::unique_ptr<utsname> getSystenNameStructure() {
	std::unique_ptr<utsname> name(new utsname());
	uname(name.get());
	return name;
}
} // namespace linux
namespace platform {

struct PlatformInfo::platformImplData {
	utsname data;
    // ISO 639 language code
    std::string locale;
};

PlatformInfo::PlatformInfo() = default;
PlatformInfo::PlatformInfo(const PlatformInfo &other) {
	if (other.impl_info) {
		impl_info = std::make_unique<platformImplData>();
		impl_info->data = other.impl_info->data;
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
	// TODO: add distro name at the end
	return impl_info ? std::string_view(impl_info->data.sysname)
	                 : constants::unknown_value;
}
const std::string_view PlatformInfo::getOsVersion() const {
	// return the kernel name version
	return impl_info ? std::string_view(impl_info->data.release)
	                 : constants::unknown_value;
}
const std::string_view PlatformInfo::getOsBuild() const {
	// return the version
	return impl_info ? std::string_view(impl_info->data.version)
	                 : constants::unknown_value;
}
const std::string_view PlatformInfo::getLocale() const {
    return impl_info ? std::string_view(impl_info->locale)
                     : constants::unknown_value;
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getScreenResolution() const {
	// TODO: implement
	return constants::unknown_value;
}
const std::string_view PlatformInfo::getCPUArchitecture() const {
	// return the CPU architecture, e.g. x86_64.
	return impl_info ? std::string_view(impl_info->data.machine)
	                 : constants::unknown_value;
}

PlatformInfo &PlatformInfo::operator=(const PlatformInfo &other) {
	if (other.impl_info) {
		impl_info = std::make_unique<platformImplData>();
		impl_info->data = other.impl_info->data;
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
