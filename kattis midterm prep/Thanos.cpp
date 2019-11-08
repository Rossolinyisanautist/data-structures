#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		long p, r, f, years = 0;
		cin >> p >> r >> f;

		while(p != 0 && p <= f) {
			p *= r;
			years++;
		}
		cout << years << '\n';
	}
}