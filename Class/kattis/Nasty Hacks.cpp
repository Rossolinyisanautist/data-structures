#include<iostream>

using namespace std;

int main() {
	int n, x, y, z;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		y -= z;

		if(x < y) {
			cout << "advertise";
		}
		else if (x > y) {
			cout << "do not advertise";
		}
		else {
			cout << "does not matter";
		}
		cout << endl;
	}
}