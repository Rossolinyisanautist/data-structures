#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int x, y;
	double answer = 666;
	cin >> x >> y;

	if(x == 0 && y == 1) {
		cout << "ALL GOOD\n";
	}
	else if(y == 1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << fixed << setprecision(8) << x / (1.0 - y) << "\n";
	}
}