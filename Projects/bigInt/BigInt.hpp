
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>

const long long LIM = std::numeric_limits<long long>::max() / 10;

using namespace std;

class BigInt {

private:
	std::vector<int> mDigits;
	bool isNeg;

	void eraseLeadingZeroes();
	void checkZeroSign();
	
	static std::vector<int> sumAbs(const std::vector<int>&, const std::vector<int>&);
	static std::vector<int> diffAbs(const std::vector<int>&, const std::vector<int>&);
	static BigInt multSmall(const BigInt&, long long b2);
	static std::vector<int> mult(const std::vector<int>&, const std::vector<int>&);

	friend inline BigInt operator+(const BigInt&, const BigInt&);
	friend inline BigInt operator*(const BigInt&, const BigInt&);
	friend inline bool operator>(const BigInt&, const BigInt&);

public:
	BigInt() : isNeg(false) {
		mDigits.push_back(0);
	}

	BigInt(const std::string&);
	BigInt(const int64_t);
	BigInt(const BigInt&);
	BigInt(const std::vector<int>);
	
	BigInt& operator+=(const BigInt&);
	BigInt& operator-=(const BigInt&);

	BigInt& operator++() {
		*this += 1;
		return *this;
	}

	BigInt operator++(int) {
		BigInt prev = BigInt(*this);
		operator++();
		return prev;
	}

	BigInt& operator--() {
		*this -= 1;
		return *this;
	}

	BigInt operator--(int) {
		BigInt prev = BigInt(*this);
		operator--();
		return prev;
	}

	std::string toString() const;

	inline BigInt operator-() const {
		BigInt temp = BigInt(*this);
		temp.isNeg = !isNeg;

		return temp;
	}

	inline BigInt operator+() const {
		return *this;
	}
	
	std::vector<int> getDigits() const {
		return mDigits;
	}
	bool isNegative() const {
		return isNeg;
	}

};

inline std::ostream& operator<<(std::ostream& out, const BigInt& b) {
	return out << b.toString();
}

std::istream& operator>>(std::istream& inp, BigInt& b);

inline bool operator>(const BigInt& b1, const BigInt& b2) {
	// May be use subtraction
	
	std::vector<int> a = b1.mDigits,
					 b = b2.mDigits;

	if(b1.isNeg && !b2.isNeg) {
		return false;
	}
	else if( !b1.isNeg && b2.isNeg) {
		return true;
	}

	bool negativeComparison = b1.isNeg && b2.isNeg;

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

inline BigInt abs(const BigInt& b1) {
	return b1.isNegative() ? -b1 : b1;
}

inline BigInt operator+(const BigInt& b1, const BigInt& b2) {
	BigInt temp(b1);
	temp += b2;
	return temp;
}

inline BigInt operator-(const BigInt& b1, const BigInt& b2) {
	BigInt temp(b1);
	temp -= b2;
	return temp;
}

inline BigInt operator*(const BigInt& b1, const BigInt& b2) {
	
	if(b1 == 0 || b2 == 0) return 0;

	if(abs(b2) < LIM) {
		return BigInt::multSmall(b1, std::stoll(b2.toString()));
	}
	if(abs(b1) < LIM) {
		return BigInt::multSmall(b2, std::stoll(b1.toString()));	
	}
	BigInt res;
	bool isNegative = b1.isNegative() ^ b2.isNegative();

	if(b1.mDigits.size() > b2.mDigits.size()) {
		res = BigInt(BigInt::mult(b2.mDigits, b1.mDigits));	
	}
	else {
		res = BigInt(BigInt::mult(b1.mDigits, b2.mDigits));			
	}

	res.isNeg = isNegative;
	return res;
}
