#include <appcenter/util/UUID.hpp>
#include <regex>
#include <stdexcept>
#include <string_view>

namespace appcenter {
namespace util {
namespace impl {
std::string generateUUID();
} // namespace impl

UUID::UUID(const std::string &uuid) : m_uuid(uuid) {}

bool UUID::is_valid(const std::string &uuid) {
	// version 4 uuid regex
	// ^[0-9a-f]{8}-[0-9a-f]{4}-[0-5][0-9a-f]{3}-[089ab][0-9a-f]{3}-[0-9a-f]{12}$
	static const std::regex regex("^[0-9a-f]{8}-[0-9a-f]{4}-[0-5][0-9a-f]{3}-["
	                              "089ab][0-9a-f]{3}-[0-9a-f]{12}$",
	                              std::regex_constants::icase);
	return std::regex_match(uuid, regex);
}

UUID UUID::generate() {
	UUID uuid;
	// use the platform specific implementation
	uuid.m_uuid = impl::generateUUID();
	return uuid;
}
UUID UUID::from_string(const std::string &uuid) {
	UUID uuid_;
	uuid_.m_uuid = uuid;
	// to lower case
	std::transform(uuid_.m_uuid.begin(), uuid_.m_uuid.end(),
	               uuid_.m_uuid.begin(), ::tolower);
	if (!is_valid(uuid_.m_uuid)) {
		throw std::invalid_argument("invalid uuid");
	}
	return uuid_;
}
const std::string &UUID::to_string() const { return m_uuid; }
} // namespace util
} // namespace appcenter