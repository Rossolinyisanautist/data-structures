#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		string message;
		cin >> message;

		int size = sqrt(message.length());
		char mtr[size][size];
		for (int i = 0, k = 0; k < message.length() && i < size; i++) {
			for(int j = size - 1; j >= 0; j--) {
				mtr[i][j] = message[k];
				k++;
			}
		}


		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				cout << mtr[j][i];
			}
		}
		cout << '\n';
	}
}