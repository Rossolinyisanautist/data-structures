

#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>

using namespace std; 

class BigInt {

	std::vector<int> mDigits;
	bool isNegative;

public:
	BigInt() : isNegative(false) {
		mDigits.push_back(0);
	}

	BigInt(const std::string& s);
	BigInt(const int64_t n);
	BigInt(const BigInt& b1);
	BigInt operator++();
	BigInt operator++(int);	
	BigInt operator--();
	BigInt operator--(int);

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

inline BigInt operator-(const BigInt& b1) {
	// negation
	std::string str = b1.toString();
	bool isNegative = str[0] == '-';

	if(isNegative) {
		str.erase(str.begin());
	}
	else {
		str.insert(str.begin(), '-');
	}

	return BigInt(str);
}

inline BigInt operator+(const BigInt& b1) {
	return b1;
}

inline BigInt operator+(const BigInt& b1, const BigInt& b2) {
	std::string res, 
				a = b1.toString(),
				b = b2.toString();

	int buff = 0;
	bool isNegative = false,
		 negAddition = false;

	if(b1 < 0 && b2 >= 0) {
		isNegative = (-b1) > b2;
	 	negAddition = true;
	 	a.erase(a.begin());
	}
	else if(b2 < 0 && b1 >= 0) {
		isNegative = (-b2) > b1;
		negAddition = true;
		b.erase(b.begin());
	}
	else if(b1 < 0 && b2 < 0) {
		isNegative = true;
	 	a.erase(a.begin());
		b.erase(b.begin());		
	}

	if(BigInt(a) < BigInt(b)) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i < a.length(); i++) {
    	int newDigit;
    	if( i >= b.length() ) {
    		b += "0";
    	}
    	if(negAddition) {
			newDigit = (a[i] - '0') - (b[i] - '0') - buff;
			
			buff = newDigit < 0 ? 1 : 0;
			newDigit += newDigit < 0 ? 10 : 0;
    	}
    	else {
	    	newDigit = (a[i] - '0') + (b[i] - '0') + buff;
			buff = newDigit / 10;
			newDigit %= 10;
		}
		res += std::to_string(newDigit);
    }
    if( !negAddition && buff == 1 ) {
    	res += '1';
    }
	if(isNegative) res += '-';
	reverse(res.begin(), res.end());
	return BigInt(res);
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






















BigInt::BigInt(const std::string& s) : isNegative(false) {
	int i = 0;
	
	while( i < s.size() && isspace(s[i]) ) {
		i++;
	}

	if( s[i] == '-' || s[i] == '+' ) {
		isNegative = s[i] == '-';
		i++;
	}
	
	while( i < s.size() && isdigit(s[i]) ) {
		mDigits.push_back(s[i] - '0');
		i++;
	}

	if( i != s.size() ) {
		throw runtime_error("Incorrect Representation of BigInt: " + s);
	}

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

	if(isNegative) {
		r += "-";
	}

	for(auto d : mDigits) {
		r += char(d + '0');
	}

	return r == "-0" ? "0" : r ;
}













int main() {
	BigInt a;
	BigInt b;
	cin >> a >> b;
	cout << a + b;
	// while(cin >> a >> b) {
		// cout << a << " - " << b << " = " <<  (a - b) << '\n';	
	// }
}