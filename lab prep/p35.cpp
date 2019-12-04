#include<iostream>
#include<stdexcept>
#include<algorithm>
using namespace std;

string convertToBase(int num, int base) {

	const static string digits = "0123456789ABCDEF";

	if(base < 2 or base > 16) {
		throw invalid_argument("Invalid base.");
	}

	bool isNeg = 0;
	if(num < 0) {
		num = -num;
		isNeg = true;
	}

	string res = "";
	while(num != 0) {
		res += digits[num % base];
		num /= base;
	}

	if(isNeg) {
		res += "-";
	}

	reverse(res.begin(), res.end());

	return res;

}

int main() {
	int num, base;

	while(cin >> num >> base) {
		try {
			string res = convertToBase(num, base);
			cout << num << " in base " << base << " is equal to " << res << '\n';
		}
		catch(invalid_argument& e) {
			cerr << e.what() << '\n';
		}
	}

}











