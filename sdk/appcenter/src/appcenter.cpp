#include <appcenter/service/services.hpp>
#include <appcenter/private/services.hpp>
#include <iostream>

namespace appcenter {
namespace services {
static bool configured = false;
std::string appSecret = "";
void configure() {
	std::cout << "configuring AppCenter SDK.\n";
	if (configured) {
		std::cerr << "AppCenter services already configured" << std::endl;
		return;
	} else {
		configured = true;
		std::cout << "platform:  " << getPlatform() << "\n";
	}
}
void configure(std::string appSecret) {
	std::cout << "configure AppCenter SDK with appSecret.\n";
	if (!configured) {
		configure();
		if (configured) {
			services::appSecret = appSecret;
			std::cout << "appSecret: " << appSecret << "\n";
		}
	}
}
bool isConfigured() { return configured; }
void start(std::string appSecret, Services_t services) {
	std::cout << "Attempting to start AppCenter SDK.\n";
	if (!configured) {
		std::cout << "AppCenter Powered.\n";
		configure(appSecret);
		start(services);
	} else {
		std::cerr << "AppCenter services already started." << std::endl;
	}
}
void start(Services_t services) {
	std::cout << "starting AppCenter service(s).\n";
	if (configured) {
		std::cout << "services:\n";
		if (services & Services_t::analytics) {
			std::cout << " - analytics.\n";
		}
		if (services & Services_t::crash) {
			std::cout << " - crash.\n";
		}
		if (services & Services_t::distribute) {
			std::cout << " - distribute.\n";
		}
	} else {
		std::cerr << "AppCenter services not configured" << std::endl;
	}
}
} // namespace services

} // namespace appcenter
