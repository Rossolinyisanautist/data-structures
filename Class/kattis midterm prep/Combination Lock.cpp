#include<iostream>

using namespace std;

int main() {

	while(true) {
		int currPos, a, b, c, degrees = 120;
		cin >> currPos >> a >> b >> c;
		if(currPos + a + b + c == 0) break;

		degrees += (currPos < a) ? abs(40 - a + currPos) : (currPos - a);
		degrees += (a > b) ? abs(40 - a + b) : (b - a);
		degrees += (b < c) ? abs(40 - c + b) : (b - c);

		cout << degrees * 9 << '\n';
	}

}