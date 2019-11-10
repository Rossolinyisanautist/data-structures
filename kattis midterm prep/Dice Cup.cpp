#include<iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	if(a > b) swap(a, b);

	for (int i = a + 1; i <= b + 1; i++) {
		cout << i << '\n';
	}
}