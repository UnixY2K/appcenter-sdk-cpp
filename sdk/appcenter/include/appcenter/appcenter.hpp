#pragma once
#include <appcenter/private/exportAPI.hpp>
#include <appcenter/service/services.hpp>
#include <string>

namespace appcenter {

extern "C" {
appcenterAPI void start(std::string appSecret, Services_t services);
}

} // namespace appcenter
