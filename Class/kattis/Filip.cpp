#include<iostream>

using namespace std;

int main() {
	int a, b, isFirstBigger;

	cin >> a >> b;

	int c1, c2, c3;
	int d1, d2, d3;

	c1 = a % 10;
	c2 = a / 10 % 10;
	c3 = a / 100 % 10;

	d1 = b % 10;
	d2 = b / 10 % 10;
	d3 = b / 100 % 10;

	if (c1 > d1) {
		cout << c1 << c2 << c3 << '\n';
	}
	else if(c1 < d1) {
		cout << d1 << d2 << d3 << '\n';
	}
	else {
		if(c2 > d2) {
			cout << c1 << c2 << c3 << '\n';			
		}
		else if(c2 < d2) {
			cout << d1 << d2 << d3 << '\n';
		}
		else {
			if(c3 > d3) {
				cout << c1 << c2 << c3 << '\n';
			}
			else if(c3 < d3) {
				cout << d1 << d2 << d3 << '\n';
			}
		}
	}
}







