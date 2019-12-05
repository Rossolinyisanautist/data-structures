#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<cctype>

class BigInt {

	std::vector<int> mDigits;
	bool isNegative;

public:
	BigInt() : isNegative(false) {
		mDigits.push_back(0);
	}

	BigInt(const std::string& s);
	BigInt(const int64_t n);


	std::string toString() const;
};

inline std::ostream& operator<<(std::ostream& out, const BigInt& b) {
	return out << b.toString();
}

std::istream& operator>>(std::istream& inp, BigInt& b);

inline bool operator==(const BigInt& b1, const BigInt& b2)
{
    return b1.toString() == b2.toString();
}

inline bool operator!=(const BigInt& b1, const BigInt& b2)
{
    return !(b1 == b2);
}

