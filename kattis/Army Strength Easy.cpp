#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int g, m;

		cin >> g >> m;
		long G[g], M[m];

		for (int i = 0; i < g; ++i) {
			cin >> G[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> M[i];
		}

		int i = 0;
		int j = 0;
		while(g != 0 && m != 0) {
			if(G[i] == M[j]) {
				m--;
				j++;
			}
			else if(G[i] < M[j]) {
				g--;
				i++;
			}
			else {
				m--;
				j++;
			}
		}
		cout << ( (g > m) ? "Godzilla" : (g < m) ? "MechaGodzilla" : "uncertain" ) << '\n';
	}
}