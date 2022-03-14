#include <appcenter/sdk/constants.hpp>
#include <appcenter/sdk/storage/storageService.hpp>

namespace appcenter::sdk::storage {
bool StorageService::init(const std::string_view path) {
	if (!hasStarted()) {
		// TODO: start the database
	}
	return false;
}
bool StorageService::hasStarted() { return started; }
} // namespace appcenter::sdk::storage