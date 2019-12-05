#include <iostream>

using namespace std;

int main() {
	int n, isFailed = 0;
	cin >> n;
	string a, b;
	cin >> a;
	cin >> b;
	if(n % 2 != 0) {
		//they must not be equal
		for (int i = 0; i < a.length(); ++i) {
			if(a.at(i) == b.at(i)) {
				isFailed = 1;
				break;
			}
		}
	}
	else {
		//they must be equal
		for (int i = 0; i < a.length(); ++i) {
			if(a.at(i) != b.at(i)) {
				isFailed = 1;
				break;
			}
		}
	}
	cout << (isFailed ? "Deletion failed\n" : "Deletion succeeded\n");
}

