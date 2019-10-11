#include <iostream>

using namespace std;

int main() {
	int n, m, k;

	cin >> n >> m >> k;

	int matrix[n + 2][m + 2];

	for (int x = 0; x < n + 2; x++) {
		for (int y = 0; y < m + 2; y++) {
			matrix[x][y] = 0;
		}
	}

	int count = 0;
	while(count++ < k) {
		int x, y;
		cin >> x >> y;

		matrix[x][y]++;
	}

	// cout << '\n';

	count = 0;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			if ( ( matrix[x][y] && matrix[x - 1][y + 1] && matrix[x][y + 1] && matrix[x - 1][y] ) || 
				 ( matrix[x][y] && matrix[x + 1][y] && matrix[x][y - 1] && matrix[x + 1][y - 1] ) ||
				 ( matrix[x][y] && matrix[x - 1][y] && matrix[x - 1][y - 1] && matrix[x][y - 1] ) ||
				 ( matrix[x][y] && matrix[x][y + 1] && matrix[x + 1][y + 1] && matrix[x + 1][y] ) ) {
				count += matrix[x][y];
			}
			cout << matrix[x][y] << ' ';
		}
		cout  << '\n';
	}
	cout << count << '\n';
}	