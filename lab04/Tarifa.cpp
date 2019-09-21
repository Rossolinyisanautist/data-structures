#include<iostream>

using namespace std;

int main() {
	int x, n;
	cin >> x;
	cin >> n;

	int p[n];
	int numOfMonths = sizeof(p) / sizeof(p[0]);
	int totalUsed = 0;
	int total = x * (n + 1);

	for (int i = 0; i < numOfMonths; ++i) {
		cin >> p[i];
		totalUsed += p[i];
	}

	int remaining = (total - totalUsed);
	cout << remaining << endl;
}