#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;
	a++; 
	b++;
	if(a == b) {
		cout << a << '\n';
		return 0;
	}
	if(a > b) swap(a, b);

	for(int i = a; i <= b; i++) {
		cout << i << '\n';
	}
}