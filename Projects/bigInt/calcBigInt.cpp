#include<iostream>
#include "BigInt.hpp"


using namespace std;

int main() {
	BigInt a;
	BigInt b;

	cin >> a;
	b = 200;

	BigInt c = a + b;
	cout << a << " + " << b << " = " << c << '\n';
	// cout << c << '\n';


}