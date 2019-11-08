#include<iostream>

using namespace std;

int main() {
	int r, l;

	cin >> r >> l;

	if(l + r == 0) {
		cout << "Not a moose\n";
	}
	else if(r > l) {
		cout << "Odd " << r*2 << '\n';
	}
	else if(r < l) {
		cout << "Odd " << l*2 << '\n';
	}
	else {
		cout << "Even " << r*2 << '\n';
	}
}