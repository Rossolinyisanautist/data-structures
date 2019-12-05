#include<iostream>

using namespace std;

int sumOfDigits(int n) {
	int sum = 0;
	while(n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int l, d, x;
	cin >> l >> d >> x;
	int minimum = d + 1;
	int maximum = l - 1;
	for(int i = l; i <= d; i++) {
		if(sumOfDigits(i) == x) {
			minimum = min(i, minimum);
			maximum = max(i, maximum);
		}
	}

	cout << minimum << '\n';
	cout << maximum << '\n';
}