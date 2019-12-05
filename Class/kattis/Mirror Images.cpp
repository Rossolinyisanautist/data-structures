#include <iostream>

using namespace std;

int main() {
	int n, test = 1;
	cin >> n;

	while(test <= n) {
		int x, y;
		cin >> x >> y;

		char mtrx[x][y];

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j)	{
				cin >> mtrx[i][j];
			}
		}

		cout << "Test " << test << '\n';
		for (int i = x - 1; i >= 0; i--) {
			for (int j = y - 1; j >= 0; j--)	{
				cout << mtrx[i][j];
			}
			cout << '\n';
		}
		test++;
	}

}