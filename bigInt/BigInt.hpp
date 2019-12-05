#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<cctype>

class BigInt {

	std::vector<int> digits_;
	bool isNegative;
public:
	BigInt() {
		isNegative = false;
		digits_.push_back(0);
	}

	std::string toString() const;
};

inline std::ostream& operator<<(std::ostream& out, const BigInt& b) {
	return out << b.toString();
}