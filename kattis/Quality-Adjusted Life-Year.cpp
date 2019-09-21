#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int n;
	double q, y, result;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> q >> y;
		result += q * y;
	}
	cout << fixed << setprecision(3) << result << endl;
}