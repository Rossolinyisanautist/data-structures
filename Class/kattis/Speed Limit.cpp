#include<iostream>

using namespace std;

int main() {
	int n, a, b, distance, prevB;

	while(true) {
		cin >> n;

		if(n == -1) {
			break;
		}

		distance = 0;
		prevB = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			distance += a * (b - prevB);
			prevB = b;
		}

		cout << distance << " miles" << endl;
	}
}

