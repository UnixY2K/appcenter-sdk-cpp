#pragma once
#include <appcenter/appcenter.hpp>

namespace appcenter {
std::string getPlatform();
void startAppCenter(std::string appSecret, Services_t services);
} // namespace appcenter
