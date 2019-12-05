#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include<sstream>
#include<stdexcept>
#include<iomanip>

#include "Rational.hpp"

TEST_CASE("Check Rational's constructors", "[ctors]") {

	std::ostringstream sout;

	SECTION("Constructor wih no parameters") {
		sout << Rational();
		REQUIRE(sout.str() == "0/1");
	}

	SECTION("Constructor with int64_t numerator") {
		sout << Rational(-1234567891011);
		REQUIRE(sout.str() == "-1234567891011");
	}

	SECTION("Constructor with int64_t numerator, int64_t denominator") {

		SECTION("Denominator equals to zero") {
			REQUIRE_THROWS_AS(Rational(-34, 0), std::runtime_error);
		}
		SECTION("Fix denominator's sign") {
			SECTION("negative denominator") {
				sout << Rational(1, -2);
				REQUIRE(sout.str() == "-1/2");	
			}
			SECTION("Neg numerator, Neg denominator") {
				sout << Rational(-1, -2);
				REQUIRE(sout.str() == "1/2");	
			}
		}
		SECTION("Reducing") {
			SECTION("Case 1") {
				sout << Rational(13, 23);
				REQUIRE(sout.str() == "13/23");
			} 
			SECTION("Case 2") {
				sout << Rational(300, 100);
				REQUIRE(sout.str() == "3/1");
			}
			SECTION("Case 3") {
				sout << Rational(25, -55);
				REQUIRE(sout.str() == "-5/11");
			}
		}
	}
}

TEST_CASE("Check method toDouble()", "[toDouble]") {
	std::ostringstream sout;
	sout << std::fixed << std::showpoint << std::setprecision(4);

	SECTION("Case 1") {
		sout << Rational(1, 3).toDouble();
		REQUIRE(sout.str() == "0.3333");
	}
	SECTION("Case 2") {
		sout << Rational(1, 2).toDouble();
		REQUIRE(sout.str() == "0.5000");
	}
}

TEST_CASE("Check method toSchoolForm", "[toSchoolForm]") {
	REQUIRE( Rational(15, 3).toSchoolForm() == "5" 			);
	REQUIRE( Rational(-15, 3).toSchoolForm() == "-5" 		);
	REQUIRE( Rational(15, 15).toSchoolForm() == "1" 		);
	REQUIRE( Rational(15, -15).toSchoolForm() == "-1" 		);
	REQUIRE( Rational(15, -3).toSchoolForm() == "-5" 		);
	REQUIRE( Rational(25, 10).toSchoolForm() == "2(1/2)" 	);
	REQUIRE( Rational(25, -10).toSchoolForm() == "-2(1/2)" 	);
}

TEST_CASE("Check equality, inequality", "[equality]") {
	REQUIRE( Rational(1, 2) == Rational(-1, -2) );
	REQUIRE( Rational(10, 20) == Rational(1, 2) );
	REQUIRE( Rational(1, 2) != Rational(1, 3) 	);
	REQUIRE( Rational(-1, 2) != Rational(1, 2) 	);
}

TEST_CASE("Check comparison", "[comparisons]") {
	REQUIRE( Rational(1, 2) < Rational(1) 			);
	REQUIRE( Rational(-17, 24) < Rational() 		);
	REQUIRE( Rational(5, 4) > Rational(10, 10)	 	);
	REQUIRE( Rational(-5, 3) <= Rational(3, -5) 	);
	REQUIRE( Rational(4, 2) <= Rational(15, 3) 		);
	REQUIRE( Rational(7, 15) >= Rational(6, 15) 	);
	REQUIRE( Rational(7, 15) >= Rational(-7, -15) 	);
}

TEST_CASE("Check Arithmetic operators", "[arithmetic]") {	
	REQUIRE( Rational(1, 2) + Rational(1, 3) == Rational(5, 6) 	);
	REQUIRE( Rational(-1, 2) + Rational(1, 2) == 0 				);
	REQUIRE( Rational(5, 6) - Rational(1, 2) == Rational(1, 3)	);
	REQUIRE( Rational(1, 3) - Rational(2, 3) == Rational(-1, 3) );

	REQUIRE_THROWS_AS( Rational(7, 3) / 0, std::runtime_error);

	REQUIRE(-Rational(1, 5) == Rational(-1, 5));
	REQUIRE(+Rational(1, 10) == Rational(1, 10));
}

TEST_CASE("Check >> operators", "[input]") {
	Rational r;

	SECTION("Read Just a number") {
		SECTION("Case 1") {
			std::istringstream sinp("10101");
			bool succ = sinp >> r && sinp.eof() && r == 10101;
			REQUIRE(succ);
		}
		SECTION("Case 2") {
			std::istringstream sinp("-10101");
			bool succ = sinp >> r && sinp.eof() && r == -10101;
			REQUIRE(succ);
		}
		SECTION("Case 3") {
			std::istringstream sinp("0000");
			bool succ = sinp >> r && sinp.eof() && r == 0;
			REQUIRE(succ);
		}
		SECTION("Case 4") {
			std::istringstream sinp("fail");
			bool succ = bool(sinp >> r);
			REQUIRE_FALSE(succ);
		}
	}

	SECTION("Full form") {
		SECTION("Case 1")
        {
            std::istringstream sinp("  0/5");
            bool succ = sinp >> r && sinp.eof() && r == 0;
            REQUIRE(succ);
        }
		SECTION("Case 2") {
			std::istringstream sinp("   -45/-25");
			bool succ = sinp >> r && sinp.eof() && r == Rational(9, 5);
		}
		SECTION("Case 3") {
			std::istringstream sinp("   -45/+25");
			bool succ = sinp >> r && sinp.eof() && r == Rational(-9, 5);
		}
		SECTION("Case 4") {
			std::istringstream sinp("-45");
			bool succ = bool(sinp >> r);
			REQUIRE_FALSE(succ);
		}
		SECTION("Case 5") {
			std::istringstream sinp("-45/--5");
			bool succ = bool(sinp >> r);
			REQUIRE_FALSE(succ);
		}
		SECTION("Case 6") {
			std::istringstream sinp("-45/hello");
			bool succ = bool(sinp >> r);
			REQUIRE_FALSE(succ);
		}
	}
}


















