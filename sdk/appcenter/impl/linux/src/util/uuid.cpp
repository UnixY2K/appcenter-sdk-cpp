#include <string>
#include <uuid/uuid.h>

namespace appcenter::util::impl {
std::string generateUUID() {
	uuid_t uuid;
	uuid_generate_random(uuid);
	char uuid_str[37];
	uuid_unparse_lower(uuid, uuid_str);
	return std::string(uuid_str);
}
} // namespace appcenter::util::impl