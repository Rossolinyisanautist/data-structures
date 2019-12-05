#include<iostream>

using namespace std;

int main() {
	int n, d, di, count = 0;

	cin >> n >> d;

	while(n--) {
		cin >> di;

		if (di > d) {
			count++;
		}
		else {
			break;
		}
	}

	if (n == -1) {
		cout << "It had never snowed this early!" << endl;
	}
	else{
		cout << "It hadn't snowed this early in " << count << " years!" << endl;
	}
}