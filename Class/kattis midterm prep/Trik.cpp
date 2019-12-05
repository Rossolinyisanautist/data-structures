#include<iostream>

using namespace std;

int main() {
	int left = 1, mid = 0, right = 0;
	char c;
	while(cin >> c) {
		switch(c) {
			case 'A':
				swap(left, mid);
				break;
			case 'B':
				swap(right, mid);
				break;
			case 'C':
				swap(right, left);
				break;
		}
	}
	cout << ( left ? 1 : mid ? 2 : 3 ) << '\n';
}