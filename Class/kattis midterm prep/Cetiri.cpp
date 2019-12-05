#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	if(a > b) swap(a, b);

	int d1 = abs(b - a);
	int d2 = abs(c - b);

	if(d1 > d2) {
		cout << a + d2 << '\n';
	}
	else if (d1 < d2){
		cout << b + d1 << '\n';
	}
	else {
		cout << c + d2 << '\n';
	}
}

// 1 4 10
//  3 6