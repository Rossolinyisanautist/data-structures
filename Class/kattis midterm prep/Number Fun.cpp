#include<iostream>

using namespace std;

int main() {
	int n;
	double a, b, c;

	cin >> n;

	while(n--) {
		cin >> a >> b >> c;

		const double sum = a + b;
		const double diff = a - b;
		const double diff2 = b - a;
		const double prod = a * b;
		const double quot = a / b;
		const double quot2 = b / a;

		if( c == sum ||
			c == diff ||
			c == diff2 ||
			c == prod ||
			c == quot ||
			c == quot2) {
			cout << "Possible\n";
		}			
		else {
			cout << "Impossible\n";
		}
	}
}