#include<iostream>

using namespace std;

int main() {
	int n;
	double a, b, c;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;

		double sum, dif, dif2, quot, quot2, prod;

		sum = a + b;
		prod = a * b;

		dif = a - b;
		dif2 = b - a;
		quot = a / b;
		quot2 = b /a;

		if (sum == c || dif == c || 
			dif2 == c || quot == c ||
			quot2 == c ||prod == c) {
			cout << "possible";
		}
		else {
			cout << "impossible";
		}
		cout << endl;
	}
}