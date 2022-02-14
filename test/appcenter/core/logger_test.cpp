#include <appcenter/sdk/core/logger.hpp>
#include <catch2/catch.hpp>
#include <sstream>
#include <string_view>

using namespace appcenter::sdk::core::logging;

TEST_CASE("AppCenter::core::logging", "[Logger]") {
	// do not output the timestamp
	Logger &logger = Logger::getInstance();
	logger.setLogFormat("[{tag}] {level}: {message}\n");
	SECTION("generate verbose") {
		std::stringstream ss;
		logger.setLogger(ss);

		logger.setLogLevel(LogLevel::Verbose);
		// this should not be logged
		// on verbose level all messages are logged
		// this should be logged
		logger.verbose("AppCenter-Test", "verbose message");
		logger.debug("AppCenter-Test", "debug message");
		logger.info("AppCenter-Test", "info message");
		logger.warn("AppCenter-Test", "warn message");
		logger.error("AppCenter-Test", "error message");
		// due to catch2, it includes the assert macro, so we cannot use the
		// assert method
		// logger.assert("AppCenter-Test", "assert message");

		// check the output
		constexpr std::string_view expected =
		    "[AppCenter-Test] VERBOSE: verbose message\n"
		    "[AppCenter-Test] DEBUG: debug message\n"
		    "[AppCenter-Test] INFO: info message\n"
		    "[AppCenter-Test] WARN: warn message\n"
		    "[AppCenter-Test] ERROR: error message\n";
		REQUIRE(ss.str() == expected);
	}
	SECTION("generate debug") {
		std::stringstream ss;
		logger.setLogger(ss);

		logger.setLogLevel(LogLevel::Debug);
		// this should not be logged
		// on debug, verbose messages aren't logged
		logger.verbose("AppCenter-Test", "verbose message");
		// this should be logged
		logger.debug("AppCenter-Test", "debug message");
		logger.info("AppCenter-Test", "info message");
		logger.warn("AppCenter-Test", "warn message");
		logger.error("AppCenter-Test", "error message");
		// due to catch2, it includes the assert macro, so we cannot use the
		// assert method
		// logger.assert("AppCenter-Test", "assert message");

		// check the output
		constexpr std::string_view expected =
		    "[AppCenter-Test] DEBUG: debug message\n"
		    "[AppCenter-Test] INFO: info message\n"
		    "[AppCenter-Test] WARN: warn message\n"
		    "[AppCenter-Test] ERROR: error message\n";
		REQUIRE(ss.str() == expected);
	}
	SECTION("generate info") {
		std::stringstream ss;
		logger.setLogger(ss);

		logger.setLogLevel(LogLevel::Info);
		// this should not be logged
		// on info, verbose and debug messages aren't logged
		logger.verbose("AppCenter-Test", "verbose message");
		logger.debug("AppCenter-Test", "debug message");
		// this should be logged
		logger.info("AppCenter-Test", "info message");
		logger.warn("AppCenter-Test", "warn message");
		logger.error("AppCenter-Test", "error message");
		// due to catch2, it includes the assert macro, so we cannot use the
		// assert method
		// logger.assert("AppCenter-Test", "assert message");

		// check the output
		constexpr std::string_view expected =
		    "[AppCenter-Test] INFO: info message\n"
		    "[AppCenter-Test] WARN: warn message\n"
		    "[AppCenter-Test] ERROR: error message\n";
		REQUIRE(ss.str() == expected);
	}
	SECTION("generate warn") {
		std::stringstream ss;
		logger.setLogger(ss);

		logger.setLogLevel(LogLevel::Warn);
		// this should not be logged
		// on warn, verbose, debug and info messages aren't logged
		logger.verbose("AppCenter-Test", "verbose message");
		logger.debug("AppCenter-Test", "debug message");
		logger.info("AppCenter-Test", "info message");
		// this should be logged
		logger.warn("AppCenter-Test", "warn message");
		logger.error("AppCenter-Test", "error message");
		// due to catch2, it includes the assert macro, so we cannot use the
		// assert method
		// logger.assert("AppCenter-Test", "assert message");

		// check the output
		constexpr std::string_view expected =
		    "[AppCenter-Test] WARN: warn message\n"
		    "[AppCenter-Test] ERROR: error message\n";
		REQUIRE(ss.str() == expected);
	}
	SECTION("generate error") {
		std::stringstream ss;
		logger.setLogger(ss);

		logger.setLogLevel(LogLevel::Error);
		// this should not be logged
		// on error, verbose, debug, info and warn messages aren't logged
		logger.verbose("AppCenter-Test", "verbose message");
		logger.debug("AppCenter-Test", "debug message");
		logger.info("AppCenter-Test", "info message");
		logger.warn("AppCenter-Test", "warn message");
		// this should be logged
		logger.error("AppCenter-Test", "error message");
		// due to catch2, it includes the assert macro, so we cannot use the
		// assert method
		// logger.assert("AppCenter-Test", "assert message");

		// check the output
		constexpr std::string_view expected =
		    "[AppCenter-Test] ERROR: error message\n";
		REQUIRE(ss.str() == expected);
	}
	// we cannot test the assert method, because catch2 includes the assert
	// macro and we cannot use the assert method
	SECTION("Generate None") {
		std::stringstream ss;
		logger.setLogger(ss);

		logger.setLogLevel(LogLevel::None);
		// this should not be logged
		logger.verbose("AppCenter-Test", "verbose message");
		logger.debug("AppCenter-Test", "debug message");
		logger.info("AppCenter-Test", "info message");
		logger.warn("AppCenter-Test", "warn message");
		logger.error("AppCenter-Test", "error message");
		// due to catch2, it includes the assert macro, so we cannot use the
		// assert method
		// logger.assert("AppCenter-Test", "assert message");
		// on None we cannot log anything

		// check the output
		constexpr std::string_view expected = "";
		REQUIRE(ss.str() == expected);
	}
}