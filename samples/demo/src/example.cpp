#include <appcenter/appcenter.hpp>
#include <example.hpp>

void initAppCenter() {
	// dummy init app center
	std::string appSecret = "YOUR_APP_SECRET";
	appcenter::Services_t services =
	    appcenter::Services_t::analytics | appcenter::Services_t::crash | appcenter::Services_t::distribute;
	appcenter::start(appSecret, services);
}