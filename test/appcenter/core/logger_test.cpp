#include <appcenter/core/logger.hpp>
#include <catch2/catch.hpp>

using namespace appcenter::core::logging;

// TODO: implement proper tests
TEST_CASE("AppCenter::core::logging", "[Logger]") {
	SECTION("generate verbose") {
		Logger &logger = Logger::getInstance();
		logger.setLogLevel(LogLevel::Verbose);
		logger.verbose("Tests", "verbose");
	}
}