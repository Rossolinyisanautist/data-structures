#include<iostream>

using namespace std;

int main() {
	char ch, prev;
	cin >> prev;
	while(cin >> ch) {
		if(ch == 's' && prev == 's') {
			cout << "hiss\n";
			return 0;
		}
		prev = ch;
	}
	cout << "no hiss\n";
}