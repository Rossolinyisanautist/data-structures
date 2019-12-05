#include<iostream>

using namespace std;

int main() {
	int n;
	double q, y, sum;

	cin >> n;

	while(n--) {
		cin >> q >> y;
		sum += q * y;
	}
	cout << sum << '\n';
}