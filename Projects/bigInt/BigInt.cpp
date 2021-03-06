#include<cctype>
#include<stdexcept>
#include<vector>

#include "BigInt.hpp"

using namespace std;


BigInt::BigInt(const std::string& s) : isNeg(false) {
	int i = 0;
	
	while( i < s.size() && isspace(s[i]) ) {
		i++;
	}

	if( s[i] == '-' || s[i] == '+' ) {
		isNeg = s[i] == '-';
		i++;
	}
	
	while( i < s.size() && isdigit(s[i]) ) {
		mDigits.push_back(s[i] - '0');
		i++;
	}

	if( i != s.size() ) {
		throw runtime_error("Incorrect Representation of BigInt: " + s);
	}

	eraseLeadingZeroes();
}

BigInt::BigInt(const std::vector<int> v) : isNeg(false) {
	// dangerous if object s is destroyed
	mDigits = v;
	eraseLeadingZeroes();
}

void BigInt::eraseLeadingZeroes() {
	while( mDigits[0] == 0 && mDigits.size() > 1 ) {
		mDigits.erase(mDigits.begin());
	}
}

BigInt::BigInt(const int64_t n) {
	string str = to_string(n);
	*this = BigInt(str);
}

BigInt::BigInt(const BigInt& b1) {
	string str = b1.toString();
	*this = BigInt(str);
}

istream& operator>>(istream& inp, BigInt& b) {
	string str;

	inp >> str;

	b = BigInt(str);

	return inp;
}

BigInt BigInt::operator++() {
	*this += 1;
	return *this;
}

BigInt BigInt::operator++(int) {
	BigInt prev = BigInt(*this);
	operator++();
	return prev;
}

BigInt BigInt::operator--() {
	*this -= 1;
	return *this;
}

BigInt BigInt::operator--(int) {
	BigInt prev = BigInt(*this);
	operator--();
	return prev;
}


string BigInt::toString() const {
	string r;

	if(isNeg) {
		r += "-";
	}

	for(auto d : mDigits) {
		r += char(d + '0');
	}
	if(r == "-0") {
		isNeg = false;
	}

	return r == "-0" ? "0" : r ;
}

