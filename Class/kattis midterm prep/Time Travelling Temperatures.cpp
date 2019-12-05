#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if(a == 0 && b == 1) {
		cout << "ALL GOOD\n";
	}
	else if(a != 0 && b == 1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << fixed << setprecision(6) << a / (1.0 - b) << '\n';
	}
}