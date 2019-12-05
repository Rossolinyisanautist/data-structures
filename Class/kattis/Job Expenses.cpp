#include<iostream>

using namespace std;

int main() {
	int n, x = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;

		if(temp < 0) {
			x -= temp;
		}
	}
	cout << x << endl;
}