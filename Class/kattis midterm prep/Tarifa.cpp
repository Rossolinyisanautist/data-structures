#include<iostream>

using namespace std;

int main() {
	int x, n;
	cin >> x >> n;
	int mb = x * (n + 1);

	while(n--) {
		int temp;
		cin >> temp;
		mb -= temp;
	}
	cout << mb << '\n';
}