
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
	// May be use subtraction
	bool negativeComparison = false;
	std::string a = b1.toString(),
				b = b2.toString();
	
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

	if(a.length() != b.length()) {
		return negativeComparison 
			? a.length() < b.length()
			: a.length() > b.length();
	} 

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

	res.resize(a.length() + b.length(), '0'); // calculate len more precisely

	int i = a.length() - 1,
		j = b.length() - 1,
		k = res.length() - 1;
		
    for(; i >= 0; i--, j--) {
    	int newDigit, bDigit;
		bDigit = j < 0 ? 0 : b[j] - '0';
		
    	if(negAddition) {
			newDigit = (a[i] - '0') - bDigit - buff;
			buff = newDigit < 0 ? 1 : 0;
			newDigit += newDigit < 0 ? 10 : 0;
    	}
    	else {
	    	newDigit = (a[i] - '0') + bDigit + buff;
			buff = newDigit / 10;
			newDigit %= 10;
		}
		res[k--] = char('0' + newDigit);
    }
    if( !negAddition && buff) {
    	res[k--] = '1';
    }
    if(isNegative) res[0] = '-';
	
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


inline BigInt operator*(const BigInt& b1, const BigInt& b2) {
	if(b1 == 0 || b2 == 0) return BigInt("0");

	bool isNegative = false;
	std::string a = b1.toString(),
				b = b2.toString();

	if(b1 < 0 && b2 > 0) {
		isNegative = true;
		a.erase(a.begin());
	}
	if(b1 > 0 && b2 < 0) {
		isNegative = true;
		b.erase(b.begin());
	}
	if(b1 < 0 && b2 < 0) {
		a.erase(a.begin());
		b.erase(b.begin());	
	}

	int len = std::min(a.length(), b.length());
	std::vector<std::string> tmp;

	if(a.length() < b.length()) swap(a, b);

	int buff = 0, insertTimes = 0;
	for(int i = a.length() - 1; i >= 0 ; i--) {
		std::string tempRes(len, '0');
		int k = len - 1;
		for(int j = b.length() - 1; j >= 0; j--) {
			int newDigit = (a[i] - '0') * (b[j] - '0') + buff;
			// std::cout << (a[i] - '0') << " * " << (b[j] - '0') << " + " << buff << " = " << newDigit << '\n';
			buff = newDigit / 10;
			newDigit %= 10;
			tempRes[k--] = char('0' + newDigit);
			
			// std::cout << "buff: " << buff << " | newDigit = " << newDigit << '\n';
			// std::cout << "STR_NUM: " << tempRes << '\n';
		}
		if(buff) {
			// std::cout << "Test buff int : " << buff << '\n';
			// std::cout << "Test buff char: " << char('0' + buff) << '\n';
			tempRes.insert(0, 1, char('0' + buff)); 
			buff = 0;
		}
		// std::cout << "STR_NUM: " << tempRes << '\n';
		tempRes.insert(tempRes.length(), insertTimes++, '0');
		// reverse(tempRes.begin(), tempRes.end());
		tmp.push_back(tempRes);
	}
	BigInt res = 0;
	// std::cout << "RES:\n";
	for(auto e : tmp) {
		// std::cout << e << '\n';
		// std::cout << res << " + " << e << " = " << (res + BigInt(e)) << '\n';
		res = res + BigInt(e);
	}
	// std::cout << "\nRES: " << res << '\n';
	return isNegative ? -res : res;
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









BigInt factorial(int n) {
	if(n == 0) {
		return BigInt(1);
	}
	return factorial(n - 1) * n;
}





int main() {
	BigInt a;
	BigInt b;
	int n ;
	cin >> a >> b;


	cout << a * b << '\n';

	// while(cin >> a >> b) {
	// 	cout << a << " - " << b << " = " <<  (a - b) << '\n';	
	// }
}