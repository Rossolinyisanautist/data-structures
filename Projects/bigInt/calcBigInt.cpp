#include<iostream>
#include "BigInt.hpp"


using namespace std;

int main() {
	BigInt a;
	BigInt b;

	while(cin >> a >> b) {
		cout << a << " - " << b << " = " <<  (a - b) << '\n';	
	}
}