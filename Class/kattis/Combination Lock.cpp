#include <iostream>

using namespace std;

int main() {

	while(true) {
		int pos, a, b, c, degrees = 120;

		cin >> pos >> a >> b >> c;

		if(pos + a + b + c == 0) break;

		degrees += pos < a ? (pos + 40 - a) : (pos - a);

		degrees += a > b ? (40 - a + b) : (b - a);

		degrees += b < c ? (b + 40 - c) : (b - c);

		cout << degrees * 9 << '\n';
	}	
}