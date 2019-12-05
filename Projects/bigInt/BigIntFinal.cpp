
#include<stdexcept>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>

using namespace std;
class BigInt {

	vector<int> mDigits;
	bool isNegative;

public:
	BigInt() : isNegative(false) {
		mDigits.push_back(0);
	}

	BigInt(const string& s);
	BigInt(const int64_t n);


	string toString() const;
};

inline ostream& operator<<(ostream& out, const BigInt& b) {
	return out << b.toString();
}

istream& operator>>(istream& inp, BigInt& b);

inline bool operator==(const BigInt& b1, const BigInt& b2) {
    return b1.toString() == b2.toString();
}

inline bool operator!=(const BigInt& b1, const BigInt& b2) {
    return !(b1 == b2);
}

inline BigInt operator+(const BigInt& b1, const BigInt& b2) {
	string a = b1.toString();
	string b = b2.toString();
	string res;

	if(a.length() < b.length()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int buff = 0;
    for(int i = 0; i < a.length(); i++) {
    	if( i >= b.length() ) {
    		b += "0";
    	}
    	int newDigit = (a[i] - '0') + (b[i] - '0') + buff;
		res += to_string(newDigit % 10);
		buff = newDigit / 10;
    }
    if(buff == 1) {
    	res += '1';
    }
    reverse(res.begin(), res.end());

    return BigInt(res);
}

BigInt::BigInt(const string& s) {
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
		throw runtime_error("Incorrect Representation of BigInt");
	}

	while( mDigits[0] == 0 && mDigits.size() > 1 ) {
		mDigits.erase(mDigits.begin());
	}

}

BigInt::BigInt(const int64_t n) {
	string str = to_string(n);
	*this = BigInt(str);
}

istream& operator>>(istream& inp, BigInt& b) {
	string str;

	inp >> str;

	b = BigInt(str);

	return inp;
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


	cin >> a;

	BigInt c = a + 1;
	// cout << a << " + " << b << " = " << c << '\n';
	cout << c << '\n';


}