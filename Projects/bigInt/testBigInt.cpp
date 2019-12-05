#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>
#include "BigInt.hpp"

using namespace std;

TEST_CASE("Constructors", "[ctors]") {

	SECTION("Successful initializtions") {
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
	}
	
	SECTION("Fails") {
		REQUIRE_THROWS_AS(BigInt("10 hello")  , runtime_error);
		REQUIRE_THROWS_AS(BigInt(" 10 hello") , runtime_error);
		REQUIRE_THROWS_AS(BigInt(" -10 hello"), runtime_error);
		REQUIRE_THROWS_AS(BigInt(" +10 hello"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("hello10"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
	}
	
}

TEST_CASE("Check << operator", "[output]") {
	ostringstream out;

	SECTION("Case 1") {
		out << BigInt();
		REQUIRE(out.str() == "0");	
	}
	SECTION("Case 2") {
		out << BigInt("-12345");
		REQUIRE(out.str() == "-12345");	
	}
	SECTION("Case 3") {
		out << BigInt("    -12345");
		REQUIRE(out.str() == "-12345");	
	}
	SECTION("Case 4") {
		out << BigInt("000000000");
		REQUIRE(out.str() == "0");	
	}
	SECTION("Case 5") {
		out << BigInt("     -0");
		REQUIRE(out.str() == "0");	
	}
}

TEST_CASE("Check >> operator", "[input]")
{
    BigInt b;

    SECTION("Read Number")
    {
        SECTION("Case 1")
        {
            istringstream sinp("200");
            bool succ = sinp >> b && sinp.eof() && b == 200;
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

TEST_CASE("Check + operator", "[addition]") { 
	BigInt b1, b2;

    SECTION("Case 1")
    {
        b1 = 12341234;
        b2 = 87654321;
        bool succ = b1 + b2 == BigInt("99995555");
        REQUIRE(succ);
    }
    SECTION("Case 2")
    {
        b1 = 1;
        b2 = BigInt("999999999999999999999999999999");
        bool succ = b1 + b2 == BigInt("1000000000000000000000000000000");
        REQUIRE(succ);
    }
    SECTION("Case 3")
    {
        b1 = BigInt();
        b2 = BigInt("999999999999999999999999999999");
        bool succ = b1 + b2 == b2;
        REQUIRE(succ);
    }
    SECTION("Case 4")
    {
        b1 = BigInt("123456789");
        b2 = BigInt("123456789");
        bool succ = b1 + b2 == BigInt("246913578");
        REQUIRE(succ);
    }
}

TEST_CASE("Check > operator", "[greater than]") {

	BigInt b1, b2;

    SECTION("Case 1")
    {
        b1 = 1234;
        b2 = -1234;
        REQUIRE(b1 > b2);
    }
    SECTION("Case 2")
    {
        b1 = -1234;
        b2 = 1234;
        REQUIRE_FALSE(b1 > b2);
    }
    SECTION("Case 3")
    {
        b1 = -1234;
        b2 = -1345;
        REQUIRE(b1 > b2);
    }
    SECTION("Case 4")
    {
        b1 = -1334;
        b2 = -1234;
        REQUIRE_FALSE(b1 > b2);
    }
    SECTION("Case 4")
    {
        b1 = 0;
        b2 = 0;
        REQUIRE_FALSE(b1 > b2);
    }
    SECTION("Case 5")
    {
        b1 = 0;
        b2 = -1234;
        REQUIRE(b1 > b2);
    }
    SECTION("Case 6")
    {
        b1 = BigInt("123456789123456789123456789213456789");
        b2 = BigInt("123456789123456789123456789213456780");
        REQUIRE(b1 > b2);
    }
    SECTION("Case 7")
    {
        b1 = BigInt("1234567891234567891234567892134567890");
        b2 = BigInt("123456789123456789123456789213456780");
        REQUIRE(b1 > b2);
    }
}
