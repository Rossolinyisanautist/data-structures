#include<iostream>

using namespace std;

int main() {
	int x, y, q;
	cin >> x >> y;

	if(x > 0 && y > 0) {
		q = 1;
	}
	else if (x < 0 && y > 0) {
		q = 2;
	}
	else if (x < 0 && y < 0) {
		q = 3;
	}
	else if (x > 0 && y < 0) {
		q = 4;
	}

	cout << q << "\n";
}