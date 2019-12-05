#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	if(a > b) swap(a, b);

	int n = 3;
	while(n--) {
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
	cout << '\n';
}