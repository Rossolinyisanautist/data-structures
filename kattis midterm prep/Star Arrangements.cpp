#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n << ":\n";
	for(int i = 2; i <= (n / 2) + 1; i++) {
		for(int j = 1; j <= n / 2; j++) {
			if(i * j + (i - 1) * j == n) cout << i << "," << (i - 1) << '\n';
			if(i * j + (i - 1) * (j - 1) == n) cout << i << "," << (i - 1) << '\n';
			if(i * j == n) cout << i << "," << i << '\n';
 		}
	}
}