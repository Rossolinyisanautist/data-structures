
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>
#include<stdexcept>

using namespace std;

const long long LIM = std::numeric_limits<long long>::max() / 10;

class BigInt {

private:
	std::vector<int> mDigits;
	bool isNeg;

	void eraseLeadingZeroes();
	void checkZeroSign();
	
	static int compareAbs(const std::vector<int>&, const std::vector<int>&);
	static std::vector<int> sumAbs(const std::vector<int>&, const std::vector<int>&);
	static std::vector<int> diffAbs(const std::vector<int>&, const std::vector<int>&);
	static BigInt multSmall(const BigInt&, long long b2);
	static std::vector<int> multAbs(const std::vector<int>&, const std::vector<int>&);
	static std::pair<std::vector<int>, std::vector<int>> divAbs(const std::vector<int>&, const std::vector<int>&);

	friend inline BigInt operator+(const BigInt&, const BigInt&);
	friend inline BigInt operator*(const BigInt&, const BigInt&);
	friend inline BigInt operator/(const BigInt&, const BigInt&);
	friend inline BigInt operator%(const BigInt&, const BigInt&);
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

	int compareRes = BigInt::compareAbs(a, b);
	if(compareRes > 0) {
		return negativeComparison ? false : true;
	}
	if(compareRes < 0) {
		return negativeComparison ? true : false;
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
		res = BigInt(BigInt::multAbs(b2.mDigits, b1.mDigits));	
	}
	else {
		res = BigInt(BigInt::multAbs(b1.mDigits, b2.mDigits));			
	}

	res.isNeg = isNegative;
	return res;
}

inline BigInt operator/(const BigInt& b1, const BigInt& b2) {
	if(b2 == 0) {
		throw runtime_error("Division by zero: " + b1.toString() + " / " + b2.toString());
	}
	if(b1 == 0) {
		return 0;
	}
	if(b2 == 1) {
		return b1;
	}
	if(b1 == b2) {
		return 1;
	}
	std::pair<std::vector<int>, std::vector<int>> temp = BigInt::divAbs(b1.mDigits, b2.mDigits);
	bool isNegative = b1.isNeg ^ b2.isNeg;

	BigInt result = temp.first;
	result.isNeg = isNegative;
	return result;
}

inline BigInt operator%(const BigInt& b1, const BigInt& b2) {
	std::pair<std::vector<int>, std::vector<int>> temp = BigInt::divAbs(b1.mDigits, b2.mDigits);
	if(b2 == 0) {
		throw runtime_error("Division by zero: " + b1.toString() + " / " + b2.toString());
	}
	if(b1 == 0) {
		return 0;
	}
	if(b2 == 1) {
		return 0;
	}
	if(b1 == b2) {
		return 0;
	}
	BigInt res = temp.second;
	res.isNeg = b1.isNeg;
	return res;
}















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

int BigInt::compareAbs(const std::vector<int>& a, const std::vector<int>& b) {
	if( a.size() < b.size() ) return -1;
	if( a.size() > b.size() ) return 1;

	for(int i = 0; i < a.size(); i++) {
		if( a[i] != b[i] ) {
			return a[i] - b[i];
		}
	}
	return 0;
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

std::vector<int> BigInt::multAbs(const std::vector<int>& a, const std::vector<int>& b) {
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

std::pair<std::vector<int>, std::vector<int>> BigInt::divAbs(const std::vector<int>& a, const std::vector<int>& b) {
	//assume a > b always;
	int len = a.size() + b.size();
	std::vector<int> quotient(len),
					 remainder(len),
					 temp;

	int idx = 0, countDigits = 0, k = 0;

	while(countDigits <= a.size()) {

		while (compareAbs(temp, b) < 0 && idx < a.size()) {
				
			quotient[k++] = 0;
			temp.emplace_back(a[idx++]);
			countDigits++;

			if(countDigits > a.size()) {
				break;
			}
		}
		
		int newDigit = 0;
		BigInt multRes = b;

		while( temp[0] == 0 && temp.size() > 1 ) {
			temp.erase(temp.begin());
		}

		while( compareAbs( multRes.mDigits, temp) <= 0)  {
			newDigit++;
			multRes = newDigit * b;
		}
		if(newDigit) newDigit -= 1;
		multRes -= b;

		quotient[k++] = newDigit;
		remainder = diffAbs(temp, multRes.mDigits);

		temp = remainder;
		temp.emplace_back(a[idx++]);

		countDigits++;
	}
	quotient.resize(k);

	return make_pair(quotient, remainder);
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












int main() {
	BigInt a, b;
	cin >> a >> b;

	cout << (a / b) << '\n';
	cout << (a % b) << '\n';
}



