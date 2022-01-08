#include <appcenter/private/services.hpp>
#include <iostream>

namespace appcenter {


void startAppCenter(std::string appSecret, Services_t services) {
	std::cout << "platform:  " << getPlatform() << "\n";
	std::cout << "appSecret: " << appSecret << "\n";
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
}

} // namespace appcenter
