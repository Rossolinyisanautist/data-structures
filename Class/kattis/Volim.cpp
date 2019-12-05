#include <iostream>

using namespace std;

int main() {
	int k, n, seconds = 0;

	cin >> k >> n;

	while(n--) {
		int t;
		char answer;
		cin >> t >> answer;
		seconds += t;
		// cout << k << ": " << seconds << " " << answer << '\n';
		if(answer == 'T' && seconds < 210) {
			k++;
			if(k > 8) k = 1;
		}
	}
	cout << k << '\n';
}

