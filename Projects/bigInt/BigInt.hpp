#pragma once
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>

class BigInt {

	std::vector<int> mDigits;
	bool isNeg;

public:
	BigInt() : isNeg(false) {
		mDigits.push_back(0);
	}

	BigInt(const std::string& s);
	BigInt(const int64_t n);
	BigInt(const BigInt& b1);
	BigInt(const std::vector<int>& s);
	BigInt operator++();
	BigInt operator++(int);	
	BigInt operator--();
	BigInt operator--(int);
	std::vector<int> getDigits() const {
		return mDigits;
	}
	bool isNegative() const {
		return isNeg;
	}

	std::string toString() const;
};

inline std::ostream& operator<<(std::ostream& out, const BigInt& b) {
	return out << b.toString();
}

std::istream& operator>>(std::istream& inp, BigInt& b);

inline bool operator>(const BigInt& b1, const BigInt& b2) {
	// May be use subtraction
	bool negativeComparison = false;
	std::vector<int> a = b1.getDigits(),
					 b = b2.getDigits();
	
	if(b1.isNegative() && b2.isNegative()) {
		negativeComparison = true;
		a.erase(a.begin());
		b.erase(b.begin());
	} 
	else if(b1.isNegative()) {
		return false;
	}
	else if(b2.isNegative()) {
		return true;
	}

	if(a.size() != b.size()) {
		return negativeComparison 
			? a.size() < b.size()
			: a.size() > b.size();
	} 

	for(int i = 0; i < a.size(); i++) {
		if( a[i] != b[i] ) {
			return negativeComparison 
				? a[i] < b[i] 
				: a[i] > b[i];
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

inline BigInt operator-(const BigInt& b1) {
	// negation
	std::string str = b1.toString();

	if(b1.isNegative()) {
		str[0] = '0';
	}
	else {
		str = '-' + str;
	}

	return BigInt(str);
}

inline BigInt operator+(const BigInt& b1) {
	return b1;
}

inline BigInt operator+(const BigInt& b1, const BigInt& b2) {
	std::vector<int> res, 
					 a = b1.getDigits(),
					 b = b2.getDigits();

	int buff = 0;
	bool isNegative = false,
		 negAddition = false;

	if(b1 < 0 && b2 >= 0) {
		isNegative = (-b1) > b2;
	 	negAddition = true;
	}
	else if(b2 < 0 && b1 >= 0) {
		isNegative = (-b2) > b1;
		negAddition = true;
	}
	else if(b1 < 0 && b2 < 0) {
		isNegative = true;	
	}

	if(BigInt(a) < BigInt(b)) swap(a, b);

	res.resize(a.size() + b.size(), 0); // calculate len more precisely

	int i = a.size() - 1,
		j = b.size() - 1,
		k = res.size() - 1;

    for(; i >= 0; i--, j--) {
    	int newDigit, bDigit;
		bDigit = j < 0 ? 0 : b[j];
		
    	if(negAddition) {
			newDigit = a[i] - bDigit - buff;
			buff = newDigit < 0 ? 1 : 0;
			newDigit += newDigit < 0 ? 10 : 0;
    	}
    	else {
	    	newDigit = a[i] + bDigit + buff;
			buff = newDigit / 10;
			newDigit %= 10;
		}
		res[k--] = newDigit;
    }
    if( !negAddition && buff) {
    	res[k--] = 1;
    }
	
	return isNegative ? -BigInt(res) : BigInt(res);
}

inline BigInt operator+=(BigInt& b1, const BigInt& b2) {
	b1 = b1 + b2;
	return b1;
}

inline BigInt operator-(const BigInt& b1, const BigInt& b2) {
	return b1 + (-b2);
}

inline BigInt operator-=(BigInt& b1, const BigInt& b2) {
	b1 = b1 - b2;
	return b1;
}


inline BigInt operator*(const BigInt& b1, const BigInt& b2) {
	// TODO: Improve efficiency, too slow.

	if(b1 == 0 || b2 == 0) return 0;

	BigInt res = 0;
	bool isNegative = (b1 < 0 && b2 > 0) || (b1 > 0 && b2 < 0);
	std::vector<int> a = b1.getDigits(),
					 b = b2.getDigits();

	int len = std::min(a.size(), b.size());
	int insertTimes = 0;

	if(a.size() < b.size()) swap(a, b);


	for(int i = a.size() - 1; i >= 0 ; i--) {
		std::vector<int> tempRes(len, 0);

		int k = len - 1;
		int buff = 0;
		for(int j = b.size() - 1; j >= 0; j--) {

			int newDigit = a[i] * b[j] + buff;
			buff = newDigit / 10;
			newDigit %= 10;
			tempRes[k--] = newDigit;
		}

		if(buff) {
			tempRes.insert(tempRes.begin(), buff); 
		}

		tempRes.insert(tempRes.end(), insertTimes++, 0);
		res += BigInt(tempRes);
	}
	
	return isNegative ? -res : res;
}

















































