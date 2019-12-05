#include<iostream>

using namespace std;

int main() {
	long n, p, r, f;

	cin >> n;

	while(n--) {
		cin >> p >> r >> f;
		long i = 0;

		while(p != 0 && p <= f) {
			p *= r;
			i++;
		}

		cout << i << endl;
	}
}