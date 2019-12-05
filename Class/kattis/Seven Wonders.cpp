#include <iostream>

using namespace std;

int main() {
	char c;

	int T = 0, C = 0, G = 0;
	while(cin >> c) {
		T += (c == 'T');
		C += (c == 'C');
		G += (c == 'G');
	}
	int sum = T*T + C*C + G*G;

	int counter = 0;
	while(T != 0 && C != 0 && G != 0) {
		T--;
		C--;
		G--;
		counter++;
	}
	sum += 7 * counter;

	cout << sum << '\n';

}