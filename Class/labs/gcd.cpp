#include <iostream>
#include <ctime>
#include <algorithm>
#include <stdexcept>

using namespace std;

int gcdSlow(int a, int b);
int gcdFast(int a, int b);

int gcdFastRecur(int a, int b);

int main() {
	int a;
	int b;

	while(cin >> a >> b) {
		try {
			clock_t start = clock();
			int gcdSlowResult = gcdSlow(a, b);
			clock_t end = clock();
			cout << "Slow:  " << "Answer = " << gcdSlowResult << ", Time spent = " << (end - start) / CLOCKS_PER_SEC << " seconds\n";

			start = clock();
			int gcdFastResult = gcdFast(a, b);
			end = clock();
			cout << "Fast:  " << "Answer = " << gcdFastResult << ", Time spent = " << (end - start) / CLOCKS_PER_SEC  << " seconds\n";

			start = clock();
			int gcdFastRecurResult = gcdFastRecur(a, b);
			end = clock();
			cout << "Recur: " << "Answer = " << gcdFastRecurResult << ", Time spent = " << (end - start) / CLOCKS_PER_SEC  << " seconds\n";

		} catch(invalid_argument& e) {
			e.what();
		}
	}
}

int gcdFastRecur(int a, int b) {
	if(a == 0 && b == 0) {
		throw new invalid_argument("gcd for 0 and 0 is not defined");
	}
	a = abs(a);
	b = abs(b);

	if(a == 0 || b == 0) {
		return max(a, b); 
	}

	if(b != 0) {
		return gcdFast(b, a % b);
	}
	return a;
}

int gcdSlow(int a, int b) {
	if(a == 0 && b == 0) {
		throw new invalid_argument("gcd for 0 and 0 is not defined");
	}

	if(a == 0 || b == 0) { 
		return max(a, b); 
	}

	int m = min(a, b);
	while(a % m != 0 || b % m != 0) {
		m--;
	}
	return m;

}

int gcdFast(int a, int b) {
	if(a == 0 && b == 0) {
		throw new invalid_argument("gcd for 0 and 0 is not defined");
	}
	if(a == 0 || b == 0) { 
		return max(a, b); 
	}

	a = abs(a);
	b = abs(b);

	while(b != 0) {
		int remain = a % b;
		a = b;
		b = remain;
	}
	return a;
}







