#include <appcenter/appcenter.hpp>
#include <example.hpp>

void initAppCenter() {
	// dummy init app center
	#ifdef APPCENTER_SAMPLE_APP_SECRET
	std::string appSecret = APPCENTER_SAMPLE_APP_SECRET;
	#else
	// if not using meson, you can setup your own app secret here
	std::string appSecret = "YOUR_APP_SECRET";
	#endif
	appcenter::Services_t services =
	    appcenter::Services_t::analytics | appcenter::Services_t::crash | appcenter::Services_t::distribute;
	appcenter::start(appSecret, services);
}