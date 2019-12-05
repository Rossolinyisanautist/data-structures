#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "BigInt.hpp"


TEST_CASE("Constructors", "[ctors]") {

	REQUIRE(BigInt().toString() == "0");

	// REQUERE("Data Structures And Algorithms" == "Test Driven Development");
}

TEST_CASE("operator<<") {
	std::ostringstream out;
	out << BigInt();
	REQUIRE(out.str() == "0");
}








