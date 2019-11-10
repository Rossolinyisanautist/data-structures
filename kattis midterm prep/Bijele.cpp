#include<iostream>

using namespace std;

int main() {
	int king, q, r, b, k, p;

	cin >> king >> q >> r >> b >> k >> p;

	cout << 1 - king << " " << 1 - q << " " << 2 - r << " " << 2 - b << " " << 2 - k << " " << 8 - p << '\n';
}