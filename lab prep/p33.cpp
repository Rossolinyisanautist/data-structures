#include<iostream>

using namespace std;

int gcdSlow(int a, int b) {
	if(a == 0 and b == 0)
		throw invalid_argument("gcd for 0, 0 is not defined");
	if(a == 0 or b == 0) {
		return max(a, b);
	}
	int res = min(a, b);
	while( not(a % res == 0 and b % res == 0)) {
		res--;
	}
	return res;
}

int gcdFast(int a, int b) {
	if(a == 0 and b == 0)
		throw invalid_argument("gcd for 0, 0 is not defined");

	while(b != 0) {
		int rem = a % b;
		a = b;
		b = rem;
	}
	return rem;
}

// int gcd(int a, int b) {
// 	return b == 0 ? a : gcd(b, a % b);
// }