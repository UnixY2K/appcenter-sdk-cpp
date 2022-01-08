#define appcenterLIBRARY_EXPORT
#include <appcenter/appcenter.hpp>
#include <appcenter/private/services.hpp>
#include <iostream>

namespace appcenter {

extern "C" {
appcenterAPI void start(std::string appSecret, Services_t services) {
	startAppCenter(appSecret, services);
}
}

} // namespace appcenter
