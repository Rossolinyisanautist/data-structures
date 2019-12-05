#include<iostream>

using namespace std;

int main() {
	string s, a, b, alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> s;

	a = s.substr(0, s.length() / 2);
	b = s.substr(s.length() / 2);

	int sumA = 0, sumB = 0;

	for (int i = 0; i < s.length() / 2; ++i) {
		sumA += a[i] - 'A';
		sumB += b[i] - 'A';
	}

	for (int i = 0; i < s.length() / 2; ++i) {
		int indA = (alpha.find(a[i]) + sumA) % 26; 
		int indB = (alpha.find(b[i]) + sumB) % 26;

		indA = (indA + indB) % 26;
		a[i] = alpha[indA];
	}
	cout << a << '\n';

}