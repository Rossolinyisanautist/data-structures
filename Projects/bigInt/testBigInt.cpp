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
        REQUIRE(b1 + b2 == BigInt("99995555"));
    }
    SECTION("Case 2")
    {
        b1 = 1;
        b2 = BigInt("999999999999999999999999999999");
        REQUIRE(b1 + b2 == BigInt("1000000000000000000000000000000"));
    }
    SECTION("Case 3")
    {
        b1 = BigInt();
        b2 = BigInt("999999999999999999999999999999");
        REQUIRE(b1 + b2 == b2);
    }
    SECTION("Case 4")
    {
        b1 = BigInt("123456789");
        b2 = BigInt("123456789");
        REQUIRE(b1 + b2 == BigInt("246913578"));
    }
    SECTION("Case 5")
    {
        b1 = BigInt("10000000000000000");
        b2 = BigInt("20000000000000000");
        REQUIRE(b1 + b2 == BigInt("30000000000000000"));
    }
    SECTION("Case 6")
    {
        b1 = BigInt("-10000000000000000");
        b2 = BigInt("-20000000000000000");
        REQUIRE(b1 + b2 == BigInt("-30000000000000000"));
    }
    SECTION("Case 7")
    {
        b1 = BigInt("-20000000000000000");
        b2 = BigInt("10000000000000000");
        REQUIRE(b1 + b2 == BigInt("-10000000000000000"));
    }
    SECTION("Case 8")
    {
        b1 = BigInt("-10000000000000000");
        b2 = BigInt("20000000000000000");
        REQUIRE(b1 + b2 == BigInt("10000000000000000"));
    }
    SECTION("Case 9")
    {
        b1 = BigInt("20000000000000000");
        b2 = BigInt("-10000000000000000");
        REQUIRE(b1 + b2 == BigInt("10000000000000000"));
    }
    SECTION("Case 10")
    {
        b1 = BigInt("10000000000000000");
        b2 = BigInt("-20000000000000000");
        REQUIRE(b1 + b2 == BigInt("-10000000000000000"));
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
    SECTION("Case 8")
    {
        b1 = BigInt("-1234567891234567891234567892134567890");
        b2 = BigInt("-123456789123456789123456789213456780");
        REQUIRE(b2 > b1);
    }
}

TEST_CASE("Check negation(-) operator", "[negation]") { 
	BigInt b1, b2;

	SECTION("Case 1")
    {
        b1 = BigInt("123456789");
        b2 = BigInt("-123456789");
        REQUIRE(-b1 == b2);
    }
    SECTION("Case 2")
    {
        b1 = -BigInt("-123456789");
        b2 = -BigInt("123456789");
        REQUIRE(b1 == -b2);
    }
    SECTION("Case 3")
    {
        b1 = -BigInt("123456789");
        b2 = BigInt("123456789");
        REQUIRE(-b1 == b2);
    }
}

TEST_CASE("Check - operator", "[subtraction]") { 
	BigInt b1, b2;
	
	SECTION("Case 1")
    {
        b1 = BigInt("123456789123456789123456789");
        b2 = BigInt("123456789123456789123456789");
        REQUIRE(b1 - b2 == 0);
    }
    SECTION("Case 2")
    {
        b1 = BigInt("-1000000000000");
        b2 = BigInt("-1000000000000");
        REQUIRE(b1 - b2 == 0);
    }
    SECTION("Case 3")
    {
        b1 = BigInt("1000000000000");
        b2 = BigInt("-1000000000000");
        REQUIRE(b1 - b2 == BigInt("2000000000000"));
    }
    SECTION("Case 4")
    {
        b1 = BigInt("-1000000000000");
        b2 = BigInt("1000000000000");
        REQUIRE(b1 - b2 == BigInt("-2000000000000"));
    }
    SECTION("Case 5")
    {
        b1 = BigInt("-235689");
        b2 = BigInt("-124578");
        REQUIRE(b1 - b2 == BigInt("-111111"));
    }
    SECTION("Case 6")
    {
        b1 = BigInt("-2000");
        b2 = BigInt("-1000");
        REQUIRE(b1 - b2 == BigInt("-1000"));
    }
    SECTION("Case 7")
    {
        b1 = BigInt("1000000000000000000000000000000");
        b2 = BigInt("1");
        REQUIRE(b1 - b2 == BigInt("999999999999999999999999999999"));
    }
	SECTION("Case 7")
    {
        b1 = BigInt("1000000000000000000000000000000");
        b2 = BigInt("999999999999999999999999999999");
        REQUIRE(b1 - b2 == BigInt("1"));
    }
}

TEST_CASE("Check -= operator", "[minus-equals]") { 
	BigInt b1, b2;
	
	SECTION("Case 1")
    {
        b1 = BigInt("123456789123456789123456789");
        b2 = BigInt("123456789123456789123456789");
        b1 -= b2;
        REQUIRE(b1 == 0);
    }
    SECTION("Case 2")
    {
        b1 = BigInt("-1000000000000");
        b2 = BigInt("-1000000000000");
        b1 -= b2;
        REQUIRE(b1 == 0);
    }
    SECTION("Case 3")
    {
        b1 = BigInt("1000000000000");
        b2 = BigInt("-1000000000000");
        b1 -= b2;
        REQUIRE(b1 == BigInt("2000000000000"));
    }
    SECTION("Case 4")
    {
        b1 = BigInt("-1000000000000");
        b2 = BigInt("1000000000000");
        b1 -= b2;
        REQUIRE(b1 == BigInt("-2000000000000"));
    }
    SECTION("Case 5")
    {
        b1 = BigInt("-235689");
        b2 = BigInt("-124578");
        b1 -= b2;
        REQUIRE(b1 == BigInt("-111111"));
    }
    SECTION("Case 6")
    {
        b1 = BigInt("-515984");
        b2 = BigInt("-235689");
        b1 -= b2;
        REQUIRE(b1 == BigInt("-280295"));
    }
    SECTION("Case 7")
    {
        b1 = BigInt("1000000000000000000000000000000");
        b2 = BigInt("1");
        b1 -= b2;
        REQUIRE(b1 == BigInt("999999999999999999999999999999"));
    }
	SECTION("Case 7")
    {
        b1 = BigInt("1000000000000000000000000000000");
        b2 = BigInt("999999999999999999999999999999");
        b1 -= b2;
        REQUIRE(b1 == BigInt("1"));
    }
}

TEST_CASE("Check -- operator", "[decrement]") { 
	BigInt b1, b2;
	
	SECTION("Case 1")
    {
        b1 = BigInt("1000");
        REQUIRE(--b1 == 999);
    }
    SECTION("Case 2")
    {
        b1 = BigInt("1000");
        REQUIRE(b1-- == 1000);
    }
    SECTION("Case 3")
    {
        b1 = BigInt("-1000");
        b1--;
        REQUIRE(b1 == -1001);
    }
}

TEST_CASE("Check ++ operator", "[increment]") { 
	BigInt b1;
	
	SECTION("Case 1")
    {
        b1 = BigInt("1000");
        REQUIRE(++b1 == 1001);
    }
    SECTION("Case 2")
    {
        b1 = BigInt("1000");
        REQUIRE(b1++ == 1000);
    }
    SECTION("Case 3")
    {
        b1 = BigInt("-1000");
        b1++;
        REQUIRE(b1 == -999);
    }
}


TEST_CASE("Check * operator", "[multiplication]") { 
	BigInt b1, b2;
	
	SECTION("Case 1")
    {
        b1 = BigInt("148675665300499903978121818227023611486756653004999039781218182270236114867566530049990397812181822702361");
        b2 = BigInt("148675665300499903978121818227023611486756653004999039781218182270236114867566530049990397812181822702361");
        REQUIRE(b1 * b2 == BigInt("22104453452546271203067005842684145772521113910083700397125796351115013239976932947046887635815342753885643338520362840025306869715534597920881908624243779264702241417421705653304320448591582763357856794974321"));
    }
    SECTION("Case 2")
    {
        b1 = BigInt("22104453452546271203067005842684145772521113910083700397125796351115013239976932947046887635815342753885643338520362840025306869715534597920881908624243779264702241417421705653304320448591582763357856794974321");
        b2 = BigInt("-22104453452546271203067005842684145772521113910083700397125796351115013239976932947046887635815342753885643338520362840025306869715534597920881908624243779264702241417421705653304320448591582763357856794974321");
        REQUIRE(b1 * b2 == BigInt("-488606862435784769065023752800547743867737770128588496673030164595270142965051017133125841157081312400189624140820089843327799695647849255572477631558681572967047140046612269532124965966761750746965731122913376892247882337591348198777535583840096024833383457648474395746773002264197886100256745087853455632048825501950947049024851591509518002718157277189223426612900427614232405308203022618144148167139215723049411041"));
    }
    SECTION("Case 3")
    {
        b1 = BigInt("-488606862435784769065023752800547743867737770128588496673030164595270142965051017133125841157081312400189624140820089843327799695647849255572477631558681572967047140046612269532124965966761750746965731122913376892247882337591348198777535583840096024833383457648474395746773002264197886100256745087853455632048825501950947049024851591509518002718157277189223426612900427614232405308203022618144148167139215723049411041");
        b2 = BigInt("743867737770128588496673030164595270142965051017133125841157081312400189624140820089843327799695647849255572477631558681572967047140046612269532124965966761750746965731122913376892247882337591348198777535583840096024833383457648474395746773002264197886100256745087853455632048825501950947049024851591509518002718157277189223426612900427614232405308203022618144148167139215723049411041488606862435784769065023752800547");
        REQUIRE(b1 * b2 == BigInt("-363458881419067637280925840644140465717796773053443454038239634803598250203770807612341391984888927320993350333864223672707526452521031655037643686512017739734699797185279292279109605693329017669889080243064812617697281348263048479846772184004170371320288142738768893048895741413352506002397975787006317990352416369936260675237865474458450228793929773349741133539202452360717157324178268339477206812475820978462500139204658806224063330612767376168807011183979056887773370173449893599118341286763328539865694912394813836197078831274158641038924389409343790573095934225388448003190993998735478324637263764289118827149413550247896994164883137588198200309309797961923636184006022437510224150241425296314697488874589013920847657041545718775566068983694301203601513997584304931707999056745370089546910074933960177203497097845716082692639427"));
    }
    SECTION("Case 4")
    {
        b1 = BigInt("-999039781218182270236114867530049990397812181822702361665300499903978121818227023611486756651486756653004");
        b2 = BigInt("-702361148675665300499903978121818227023610049990397812181822702148675665336114867566530049990397812181822");
        REQUIRE(b1 * b2 == BigInt("701686728309087851784425319424959716251506891533683636338321501350647964740884478933642243076721839307360584265658253211144924873968273420358793401387969518669895582984745690286168521642107521194229895410493288"));
    }
}
