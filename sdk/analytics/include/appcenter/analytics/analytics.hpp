#pragma once
#include <appcenter/analytics/api/analytics-api.hpp>
#include <appcenter/service/IService.hpp>
#include <appcenter/util/mixin/singleton.hpp>

namespace appcenter::sdk::service {
class Service;
}

namespace appcenter::analytics {

class Analytics : public service::IService,
                  public util::mixin::Singleton<Analytics> {
	friend class util::mixin::Singleton<Analytics>;

  protected:
	Analytics() = default;

  public:
	/**
	 * @brief Get the internal service instance.
	 *
	 * @return appcenter::sdk::service::Service* the service instance.
	 */
	appcenter::sdk::service::Service *getService() const override {
		return appcenter::analytics::api::bindings::
		    APPCENTER_API_ANALYTICS_GET_SERVICE();
	}

	~Analytics() = default;
};
} // namespace appcenter::analytics