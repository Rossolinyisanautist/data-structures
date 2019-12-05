#include <iostream>

using namespace std;

int main() {
	double a, b, c;

	cin >> a >> b >> c;

	if(a == b + c) {
		cout << a << "=" << b << "+" << c << '\n';
	}
	else if(a == b - c) {
		cout << a << "=" << b << "-" << c << '\n';
	}
	else if(a == b * c) {
		cout << a << "=" << b << "*" << c << '\n';
	}
	else if(c != 0 && a == b / c) {
		cout << a << "=" << b << "/" << c << '\n';
	}

	else if(a + b == c) {
		cout << a << "+" << b << "=" << c << '\n';
	}
	else if(a - b == c) {
		cout << a << "-" << b << "=" << c << '\n';
	}
	else if(a * b == c) {
		cout << a << "*" << b << "=" << c << '\n';
	}
	else if(b != 0 && a / b == c) {
		cout << a << "/" << b << "=" << c << '\n';
	}
}