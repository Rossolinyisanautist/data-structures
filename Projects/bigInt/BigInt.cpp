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
	checkZeroSign();
}

BigInt::BigInt(const std::vector<int> v) : isNeg(false) {
	// dangerous if object s is destroyed
	mDigits = v;
	for(int i = 0; i < mDigits.size(); i++) {
		if(mDigits[i] > 9 || mDigits[i] < 0) {
			throw runtime_error("Invalid digit for BigInt: " + to_string(mDigits[i]) + ".\n\tOne cell can only cantain value x such that 0 <= x <= 9.");
		}
	}
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

BigInt& BigInt::operator+=(const BigInt& b2) {
	BigInt res;
	if(isNeg == b2.isNeg) {
		
		if(abs(*this) >= abs(b2)) {
			res = BigInt::sumAbs(mDigits, b2.mDigits);	
		}
		else {
			res = BigInt::sumAbs(b2.mDigits, mDigits);	
		}
		res.isNeg = isNeg;
	}
	else {
		if(abs(*this) > abs(b2)) {
			res = BigInt::diffAbs(mDigits, b2.mDigits);
			res.isNeg = isNeg;
		}
		else if(abs(*this) < abs(b2)) {
			res = BigInt::diffAbs(b2.mDigits, mDigits);
			res.isNeg = b2.isNeg;
		}
	}
	*this = res;
	return *this;
}

BigInt& BigInt::operator-=(const BigInt& b2) {
	return (*this += -b2);
}

std::vector<int> BigInt::sumAbs(const std::vector<int>& a, const std::vector<int>& b) {
	//assume always b1 > b2;
	int buff = 0;

	std::vector<int> res(a.size() + 1, 0); // calculate len more precisely

	int i = a.size() - 1,
		j = b.size() - 1,
		k = res.size() - 1;

    for(; i >= 0; i--, j--) {
    	int newDigit, bDigit = j < 0 ? 0 : b[j];

    	newDigit = a[i] + bDigit + buff;
		buff = newDigit / 10;
		newDigit %= 10;

		res[k--] = newDigit;
    }
    if(buff) {
    	res[k--] = 1;
    }
	
	return (res);
}

std::vector<int> BigInt::diffAbs(const std::vector<int>& a, const std::vector<int>& b) {
	//assume always b1 > b2
	int buff = 0;

	std::vector<int> res(a.size() + 1, 0); // calculate len more precisely

	int i = a.size() - 1,
		j = b.size() - 1,
		k = res.size() - 1;

    for(; i >= 0; i--, j--) {
    	int newDigit, bDigit = j < 0 ? 0 : b[j];
		
		newDigit = a[i] - bDigit - buff;
		buff = 0;
		if(newDigit < 0) {
			newDigit += 10;
			buff = 1;
		}

		res[k--] = newDigit;
    }
	
	return (res);
}

BigInt BigInt::multSmall(const BigInt& b1, long long b2) {
	bool isNegative = b1.isNegative() ^ (b2 < 0);
	const std::vector<int> a = b1.mDigits;
	BigInt res;
	b2 = abs(b2);

	int i = 0;
	for (; i < a.size(); i++) {
		std::string tempRes = std::to_string(a[i] * b2);
		tempRes.insert(tempRes.end(), a.size() - 1 - i, '0');
		res += tempRes;
	}
	return isNegative ? -res : res;	
}

std::vector<int> BigInt::mult(const std::vector<int>& a, const std::vector<int>& b) {
	std::vector<int> resVector;

	int len = std::max(a.size(), b.size());

	for(int i = a.size() - 1; i >= 0 ; i--) {
		std::vector<int> tempResVec(len + 1, 0);

		int k = len;	// to not use push_back.
		int buff = 0;
		for(int j = b.size() - 1; j >= 0; j--) {

			int newDigit = a[i] * b[j] + buff;
			buff = newDigit / 10;
			newDigit %= 10;
			tempResVec[k--] = newDigit;
		}
		if(buff) {
			tempResVec[k--] = buff;
		}

		tempResVec.resize(tempResVec.size() + a.size() - i - 1); // concat zeroes;

		int cmp = resVector.size() >= tempResVec.size();
		resVector = cmp ? sumAbs(resVector, tempResVec) : sumAbs(tempResVec, resVector);
	}

	return resVector;
}

string BigInt::toString() const {
	string r;

	if(isNeg) {
		r += "-";
	}

	for(auto d : mDigits) {
		r += char(d + '0');
	}

	return r;
}

void BigInt::checkZeroSign() {
	if(mDigits.size() == 1 && mDigits[0] == 0) {
		isNeg = false;
	}
}
