#include "BigInt.hpp"

using namespace std;

string BigInt::toString() const {
	string r;

	if(isNegative) {
		r += "-";
	}
	for(auto d : digits_) {
		r += char(d + '0');
	}
}