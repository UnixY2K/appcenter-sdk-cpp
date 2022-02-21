#pragma once
#include <appcenter/private/exportAPI.hpp>

namespace appcenter::sdk::service {
class Service;
}

namespace appcenter::analytics::api::bindings {
extern "C" {
appcenterAPI appcenter::sdk::service::Service *APPCENTER_API_ANALYTICS_GET_SERVICE();
}
} // namespace appcenter::analytics::api::bindings