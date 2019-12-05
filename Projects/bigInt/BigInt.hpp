#pragma once
#include<vector>
#include<algorithm>
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

inline bool operator>(const BigInt& b1, const BigInt& b2) {
	std::string a = b1.toString();
	std::string b = b2.toString();
	bool negativeComparison = false;

	if(a[0] == '-' && b[0] == '-') {
		negativeComparison = true;
		a.erase(a.begin());
		b.erase(b.begin());
	} 
	else if(a[0] == '-') {
		return false;
	}
	else if(b[0] == '-') {
		return true;
	}

	if(a.length() != b.length()) return a.length() > b.length();

	for(int i = 0; i < a.length(); i++) {
		if( a[i] != b[i] ) {
			return negativeComparison 
				? (a[i] - '0') < (b[i] - '0') 
				: (a[i] - '0') > (b[i] - '0');
		}
	}
	return false;
}

inline bool operator<(const BigInt& b1, const BigInt& b2) {
	return b2 > b1;
}
inline bool operator>=(const BigInt& b1, const BigInt& b2) {
	return !(b1 < b2);
}
inline bool operator<=(const BigInt& b1, const BigInt& b2) {
	return !(b1 > b2);
}
inline bool operator==(const BigInt& b1, const BigInt& b2) {
    return b1.toString() == b2.toString();
}
inline bool operator!=(const BigInt& b1, const BigInt& b2) {
    return !(b1 == b2);
}

inline BigInt operator+(const BigInt& b1, const BigInt& b2) {
	std::string a = b1.toString();
	std::string b = b2.toString();
	std::string res;

	if(a.length() < b.length()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int buff = 0;
    for(int i = 0; i < a.length(); i++) {
    	if( i >= b.length() ) {
    		b += "0";
    	}
    	int newDigit = (a[i] - '0') + (b[i] - '0') + buff;
		res += std::to_string(newDigit % 10);
		buff = newDigit / 10;
    }
    if(buff == 1) {
    	res += '1';
    }
    reverse(res.begin(), res.end());
	
    return BigInt(res);
}




















