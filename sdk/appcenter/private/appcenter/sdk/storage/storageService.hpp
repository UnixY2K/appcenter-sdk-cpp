#pragma once
#include <appcenter/sdk/service/internalService.hpp>
#include <appcenter/util/mixin/singleton.hpp>
#include <string_view>

namespace appcenter::sdk::storage {
class StorageService : public util::mixin::Singleton<StorageService>,
                       public service::InternalService<StorageService> {
	friend class util::mixin::Singleton<StorageService>;
	StorageService() : InternalService("AppCenter") {}

  public:
	bool init(const std::string_view path);
	bool hasStarted();

  private:
	bool started = false;
};
} // namespace appcenter::sdk::storage