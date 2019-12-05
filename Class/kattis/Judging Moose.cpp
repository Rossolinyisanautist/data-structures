#include <iostream>

using namespace std;

int main() {
	int a, b;


	cin >> a >> b;

	if (a + b == 0) {
		cout << "Not a moose\n";
	}
	else if(a == b) {
		cout << "Even " << a + b << "\n";
	}
	else if (a > b) {
		cout << "Odd " << a * 2 << "\n";
	}
	else {
		cout << "Odd " << b * 2 << "\n";
	}
}