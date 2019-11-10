#include<iostream>
#include<algorithm>
using namespace std;

int getNewDigit(int a, int b, int& vUme);

int main() {
	string a, b, c;
	cin >> a >> b;

	if(a.length() < b.length()) swap(a, b);
	int len = a.length();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int vUme = 0;
	for (int i = 0; i < len; i++) {
		int digitA = a[i] - '0';
		int digitB;

		if(i < b.length()) {
			digitB = b[i] - '0';

			int newDigit = getNewDigit(digitA, digitB, vUme);
			c += to_string(newDigit);
		}
		else {
			int newDigit = getNewDigit(digitA, 0, vUme);
			c += to_string(newDigit);
		}
	}
	if(vUme == 1) { 
		c += '1';
	}
	reverse(c.begin(), c.end());
	cout << c << '\n';
}

int getNewDigit(int a, int b, int& vUme) {
	int newDigit = a + b + vUme;
	vUme = 0;

	if(newDigit > 9) {
		vUme = newDigit / 10;
		newDigit %= 10;	
	}
	return newDigit;
}

