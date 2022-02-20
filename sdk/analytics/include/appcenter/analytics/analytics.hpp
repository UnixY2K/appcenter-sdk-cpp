#pragma once
#include <appcenter/service/IService.hpp>
#include <appcenter/util/mixin/singleton.hpp>

namespace appcenter::analytics {

class Analytics : public service::IService,
                  public util::mixin::Singleton<Analytics> {
	friend class util::mixin::Singleton<Analytics>;

  protected:
	Analytics() = default;

  public:
  private:
};
} // namespace appcenter::analytics