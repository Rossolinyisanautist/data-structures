#include<iostream>

using namespace std;

int main() {
	int n, input, i = 1;

	while(cin >> n) {
		int minimum = 1000001, maximum = -1000001;

		while(n--) {
			cin >> input;
			minimum = min(minimum, input);
			maximum = max(maximum, input);	
		}
		cout << "Case " << i++ << ": " << minimum << " " << maximum << " " << (maximum - minimum) << '\n';
	}	
}