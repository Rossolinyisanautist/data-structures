#include<iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int a1, a2, a3;
	int b1, b2, b3;

	a3 = a % 10;
	a2 = a / 10 % 10;
	a1 = a / 100 % 10;
	
	b3 = b % 10;
	b2 = b / 10 % 10;
	b1 = b / 100 % 10;

	int newA = 100 * a3 + 10 * a2 + a1;
	int newB = 100 * b3 + 10 * b2 + b1;

	if(newA > newB) {
		cout << newA << '\n';
	}
	else {
		cout << newB << '\n';
	}
}