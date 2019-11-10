#include<iostream>

using namespace std;

int main() {
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;

	char m[r][c];

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> m[i][j];
		}
	}
	string s;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			for(int k = 0; k < zc; k++) {
				s += m[i][j];	
			}
		}

		for(int k = 0; k < zr; k++) {
			cout << s << '\n';
		}
		s = "";
	}
}