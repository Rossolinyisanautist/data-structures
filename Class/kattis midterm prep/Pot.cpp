#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n, number, X = 0;
	cin >> n;

	while(n--) {
		cin >> number;
		int power = number % 10;
		number /= 10;

		X += pow(number, power);
	}
	cout << X << '\n';
}