#include<iostream>

using namespace std;

int main() {
	int m, p, l, e, r, s, n;

	while(cin >> m >> p >> l >> e >> r >> s >> n) {

		for (int i = 0; i < n; ++i) {
			int newL, newP, newM;
			newL = e * m;
			newP = l / r;
			newM = p / s;

			m = newM;
			l = newL;
			p = newP;
		}
		cout << m << endl;
	}
		
} 