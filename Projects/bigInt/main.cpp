
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>


using namespace std;

class BigInt {

private:
	std::vector<int> mDigits;
	mutable bool isNeg;

	void eraseLeadingZeroes();
	void setNeg(bool val) const {
		isNeg = val;
	}
	
	friend BigInt operator-(const BigInt& b1);

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
	BigInt abs(const BigInt& b1);
	
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
	
	std::vector<int> a = b1.getDigits(),
					 b = b2.getDigits();

	if(b1.isNegative() && !b2.isNegative()) {
		return false;
	}
	else if( !b1.isNegative() && b2.isNegative()) {
		return true;
	}

	bool negativeComparison = b1.isNegative() && b2.isNegative();

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
	BigInt temp = BigInt(b1);
	temp.setNeg(!b1.isNegative());

	return temp;
}

inline BigInt abs(const BigInt& b1) {
	return b1.isNegative() ? -b1 : b1;
}

inline BigInt operator+(const BigInt& b1) {
	return b1;
}

inline BigInt operator+(const BigInt& b1, const BigInt& b2) {
	std::vector<int> a = b1.getDigits(),
					 b = b2.getDigits();

	int buff = 0;
	bool isNegative = false,
		 negAddition = false;

		 // Find sign of resulting number
	if(b1.isNegative() && !b2.isNegative()) {
		isNegative = (-b1) > b2;
	 	negAddition = true;
	}
	else if( !b1.isNegative() && b2.isNegative()) {
		isNegative = (-b2) > b1;
		negAddition = true;
	}
	else if(b1.isNegative() && b2.isNegative()) {
		isNegative = true;	
	}

	if(abs(b1) < abs(b2)) swap(a, b);

	std::vector<int> res(a.size() + 1, 0); // calculate len more precisely

	int i = a.size() - 1,
		j = b.size() - 1,
		k = res.size() - 1;

    for(; i >= 0; i--, j--) {
    	int newDigit, bDigit;
		bDigit = j < 0 ? 0 : b[j];
		
    	if(negAddition) {
			newDigit = a[i] - bDigit - buff;
			buff = 0;
			if(newDigit < 0) {
				newDigit += 10;
				buff = 1;
			}
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

inline BigInt multSmall(const BigInt& b1, long long b2) {
	bool isNegative = b1.isNegative() ^ (b2 < 0);
	std::vector<int> a = b1.getDigits();
	b2 = abs(b2);

	std::vector<int> res(a.size() + std::to_string(b2).length());
	int carry = 0;
	int k = res.size();
	for (int i = a.size() - 1; i >= 0 || carry; i--) {
		int aDigit = i < 0 ? 0 : a[i];

		long long cur = carry + aDigit * 1ll * b2;

		res[--k] = int (cur % 10);

		carry = int (cur / 10);
	}
	return isNegative ? -BigInt(res) : BigInt(res);
}

inline std::vector<int> addVectors(std::vector<int> a, std::vector<int> b) {

	if(a.size() < b.size()) swap(a, b);
	std::vector<int> res(a.size() + 1, 0); // calculate len more precisely

	int i = a.size() - 1,
		j = b.size() - 1,
		k = res.size() - 1,
		buff = 0;

    for(; i >= 0; i--, j--) {
    	int newDigit, bDigit;
		bDigit = j < 0 ? 0 : b[j];

		newDigit = a[i] + bDigit + buff;
		buff = newDigit / 10;
		newDigit %= 10;
		res[k--] = newDigit;
    }
    if(buff) {
    	res[k--] = buff;	
    }
	
    return res;
}

inline BigInt operator*(const BigInt& b1, const BigInt& b2) {
	// TODO: Improve efficiency, too slow.

	if(b1 == 0 || b2 == 0) return 0;
	if(abs(b2) < std::numeric_limits<long long>::max() / 10) {
		return multSmall(b1, std::stoll(b2.toString()));
	}
	if(abs(b1) < std::numeric_limits<long long>::max() / 10) {
		return multSmall(b2, std::stoll(b1.toString()));	
	}

	bool isNegative = b1.isNegative() ^ b2.isNegative();
	std::vector<int> a = b1.getDigits(),
					 b = b2.getDigits(), 
					 resVector;

	int len = std::max(a.size(), b.size());
	if(a.size() > b.size()) swap(a, b); // to make less additions 

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
		resVector = addVectors(resVector, tempResVec);
	}
	
	BigInt result(resVector);
	return isNegative ? -result : result;
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
}

BigInt::BigInt(const std::vector<int>& s) : isNeg(false) {
	// dangerous if object s is destroyed
	mDigits = s;
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

	return r == "-0" ? "0" : r ;
}




























BigInt factorialNEW(int n) {
	if(n == 0) {
		return 1;
	}
	return factorialNEW(n - 1) * n;
}

int main() {
	BigInt a("100");
	BigInt b("99");

	int n;
	cin >> n;
	cout <<  factorialNEW(n) << '\n';
	// while(cin >> a >> b) {
		// cout << a << " - " << b << " = " <<  (a - b) << '\n';	
	// }
}






