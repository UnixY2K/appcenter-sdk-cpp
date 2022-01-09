#pragma once
#include <appcenter/appcenter.hpp>

namespace appcenter {
std::string getPlatform();
namespace services {
void configure();
void configure(std::string appSecret);
bool isConfigured();
void start(std::string appSecret, Services_t services);
void start(Services_t services);
} // namespace services
} // namespace appcenter
