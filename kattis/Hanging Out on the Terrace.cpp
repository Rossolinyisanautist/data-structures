#include <iostream>

using namespace std;

int main() {
	int L, x, current = 0, denies = 0;

	cin >> L >> x;

	while(x--) {
		string action;
		int people;
		cin >> action;
		cin >> people;

		if(action == "enter") {
			if(current + people <= L) {
				current += people;
			}
			else {
				denies++;
			}
		}
		else {
			current -= people;
		}
	}
	cout << denies << '\n';
}