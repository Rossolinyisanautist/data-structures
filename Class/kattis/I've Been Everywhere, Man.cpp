#include <iostream>

using namespace std;

int main() {
	int tests;
	cin >> tests;

	while(tests--) {
		int n, counter = 0;
		cin >> n;
		string cities[n];

		for (int i = 0; i < n; ++i) {
			string input;
			cin >> input;

			int j = 0;
			for(; j < i; ++j) {
				if(input == cities[j]) {
					break;
				}
			}
			cities[i] = input;
			counter += j == i;
		}
		cout << counter << '\n';
	}
}