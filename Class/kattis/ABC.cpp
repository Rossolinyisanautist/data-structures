#include<iostream>

using namespace std;

int main() {
	int a, b, c, temp;

	cin >> a >> b >> c;

	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	for (int i = 0; i < 3; ++i) {
		char ch;
		cin >> ch;
		switch(ch) {
			case 'A': 
				cout << a;
				break;
			case 'B': 
				cout << b;
				break;
			case 'C': 
				cout << c;
				break;
		}
		cout << " ";
	}
	cout << endl;
}