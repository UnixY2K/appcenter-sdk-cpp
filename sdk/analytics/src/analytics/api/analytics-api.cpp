#define appcenterLIBRARY_EXPORT
#include <appcenter/analytics/api/analytics-api.hpp>
#include <appcenter/sdk/analytics/analytics.hpp>

namespace appcenter::analytics::api::bindings {
extern "C" {
appcenterAPI sdk::service::Service *APPCENTER_API_ANALYTICS_GET_SERVICE() {
	static sdk::analytics::Analytics service;
	return &service;
}
}
} // namespace appcenter::analytics::api::bindings