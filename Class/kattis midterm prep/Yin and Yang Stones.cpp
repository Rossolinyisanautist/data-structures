#include<iostream>

using namespace std;

int main() {
	char ch;
	int W = 0, B = 0;
	while(cin >> ch) {
		W += ch == 'W';
		B += ch == 'B';
	}
	cout << (W == B) << '\n';
}