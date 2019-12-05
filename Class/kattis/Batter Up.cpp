#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	double sum = 0;
	int div = 0;

	while(n--) {
		int input;
		cin >> input;
		if(input != -1) {
			sum += input;
			div++;
		}
	}

	cout << (double) sum / div << '\n';
}