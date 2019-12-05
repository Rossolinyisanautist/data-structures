#include<iostream>

using namespace std;

int main() {
	int n, k = 0;
	cin >> n;

	while(n--) {
		string s;
		cin >> s;

		k += s.find("CD") == string::npos;
	}
	cout << k << '\n';
}