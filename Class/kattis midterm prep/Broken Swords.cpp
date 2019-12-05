#include<iostream>

using namespace std;

int main() {
	int n, tb = 0, lr = 0;;
	cin >> n;
	while(n--) {
		char ch;
		
		for (int i = 0; i < 2; ++i) {
			cin >> ch;
			tb += ch == '0';
		}
		for (int i = 0; i < 2; ++i) {
			cin >> ch;
			lr += ch == '0';
		}
	}
	int count = 0;
	while(tb >= 2 && lr >= 2) {
		tb -= 2;
		lr -= 2;
		count++;
	}
	cout << count << ' ' << tb << ' ' << lr << '\n';
}