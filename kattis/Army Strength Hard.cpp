#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int g, m;

		long maxG = -1;
		long maxM = -1;

		cin >> g >> m;

		while(g--) {
			long inp;
			cin >> inp;
			maxG = max(maxG, inp);
		}
		while(m--) {
			long inp;
			cin >> inp;
			maxM = max(maxM, inp);
		}
		cout << ( (maxG >= maxM) ? "Godzilla" : "MechaGodzilla" ) << '\n';
	}
}