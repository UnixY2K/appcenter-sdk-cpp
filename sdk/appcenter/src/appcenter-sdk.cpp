#define appcenterLIBRARY_EXPORT
#include <appcenter/appcenter.hpp>
#include <appcenter/private/services.hpp>
#include <iostream>

namespace appcenter {

extern "C" {
appcenterAPI void configure(std::string appSecret) {
	services::configure(appSecret);
}
appcenterAPI bool isConfigured() { return services::isConfigured(); }
appcenterAPI void start(std::string appSecret, Services_t services) {
	services::start(appSecret, services);
}
appcenterAPI void startServices(Services_t services) {
	services::start(services);
}
}

} // namespace appcenter
