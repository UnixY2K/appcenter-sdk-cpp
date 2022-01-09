#include <appcenter/util/UUID.hpp>
#include <catch2/catch.hpp>

TEST_CASE("UUID", "[util]") {
	SECTION("generate") {
		auto uuid = appcenter::util::UUID::generate();
		REQUIRE(appcenter::util::UUID::is_valid(uuid.to_string()));
	}
}