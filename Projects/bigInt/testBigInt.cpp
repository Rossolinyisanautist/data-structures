#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "BigInt.hpp"

using namespace std;

TEST_CASE("Constructors", "[ctors]") {

	REQUIRE(BigInt().toString() == "0");
	REQUIRE(BigInt("0").toString() == "0");
	REQUIRE(BigInt("+0").toString() == "0");
	REQUIRE(BigInt("-0").toString() == "0");
	REQUIRE(BigInt(" -0").toString() == "0");
	REQUIRE(BigInt(" -00000").toString() == "0");
	REQUIRE(BigInt("000").toString() == "0");
	REQUIRE(BigInt("   000000").toString() == "0");
	REQUIRE(BigInt(" 0").toString() == "0");
	REQUIRE(BigInt(" +0").toString() == "0");
	REQUIRE(BigInt(" 10").toString() == "10");
	REQUIRE(BigInt("-10").toString() == "-10");
	REQUIRE(BigInt("+10").toString() == "10");
	REQUIRE(BigInt(" -10").toString() == "-10");
	REQUIRE(BigInt(" +10").toString() == "10");
	REQUIRE(BigInt("    -0010").toString() == "-10");
	REQUIRE(BigInt("    +0010").toString() == "10");

	REQUIRE_THROWS_AS(BigInt("10 hello")  , runtime_error);
	REQUIRE_THROWS_AS(BigInt(" 10 hello") , runtime_error);
	REQUIRE_THROWS_AS(BigInt(" -10 hello"), runtime_error);
	REQUIRE_THROWS_AS(BigInt(" +10 hello"), runtime_error);
	REQUIRE_THROWS_AS(BigInt("hello10"), runtime_error);
	REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
	
}

TEST_CASE("operator<<") {
	ostringstream out;
	out << BigInt();
	REQUIRE(out.str() == "0");
}

TEST_CASE("operator>>") { 
	istringstream inp("123");
	BigInt a;
	inp >> a;
	REQUIRE(a.toString() == "123");
}


TEST_CASE("Check >> operator", "[input]")
{
    BigInt b;

    SECTION("Read Number")
    {
        SECTION("Case 1")
        {
            istringstream sinp("2000000000");
            bool succ = sinp >> b && sinp.eof() && b == 2000000000;
            REQUIRE(succ);
        }
        SECTION("Case 2")
        {
            istringstream sinp("-123456");
            bool succ = sinp >> b && sinp.eof() && b == -123456;
            REQUIRE(succ);
        }
        SECTION("Case 3")
        {
            istringstream sinp("   -000000");
            bool succ = sinp >> b && sinp.eof() && b == 0;
            REQUIRE(succ);
        }
        SECTION("Case 4")
        {
            istringstream sinp("hello");
            REQUIRE_THROWS_AS(sinp >> b, runtime_error);
        }
    }

}



