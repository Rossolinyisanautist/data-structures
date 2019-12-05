#include<iostream>
#include "BigInt.hpp"


using namespace std;

int main() {
	BigInt a;
	BigInt b;

	cin >> a;

	cout << ++a << '\n';
	cout << a++ << '\n';
	cout << a << '\n';
	// while(cin >> a >> b) {
		// cout << a << " - " << b << " = " <<  (a - b) << '\n';	
	// }
}