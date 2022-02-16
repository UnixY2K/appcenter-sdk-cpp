#include <appcenter/appcenter.hpp>
#include <iostream>
#include <string_view>

int main(int, char **) {
// get the enviroment variable
#ifdef APPCENTER_SAMPLE_APP_SECRET
	const std::string_view appSecret = APPCENTER_SAMPLE_APP_SECRET;
#else
	// if not using meson, you can setup your own app secret here
	//* NOTE: it is not recommended to have the app secret directly in the
	//* source code
	constexpr std::string_view appSecret = "YOUR_APP_SECRET";
#endif
	// we can control the SDK log level
	appcenter::AppCenter::getInstance().setLogLevel(
	    appcenter::core::logging::LogLevel::Verbose);
	// or configure the SDK with an app secret
	appcenter::AppCenter::getInstance().configure(appSecret);
}
