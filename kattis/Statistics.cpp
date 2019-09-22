#include<iostream>

using namespace std;

int main() {
	long n, x, 
		max,
		min, 
		range,
		count = 1;

	while(cin >> n && count <= 10) {
		max = -1000000000;
		min = 1000000000;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x > max) {
				max = x;
			}
			if (x < min) {
				min = x;
			}
		}
		range = max - min;
		cout << "Case " << count++ << ": " << min << " " << max << " " << range << endl;
	}
}