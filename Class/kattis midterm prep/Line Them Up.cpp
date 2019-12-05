#include<iostream>

using namespace std;

int main() {
	int n, incr = 0, decr = 0;
	string prev, s;
	cin >> n >> prev;

	while(n-- > 1) {
		cin >> s;
		incr += s > prev;
		decr += s < prev;
		prev = s;
	}
	cout << ( (incr && decr) ? "NEITHER" : incr ? "INCREASING" : "DECREASING" ) << '\n';
}