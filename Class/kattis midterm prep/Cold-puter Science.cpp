#include<iostream>

using namespace std;

int main() {
	int n, count = 0, tmp;
	cin >> n;
	while(n--) {
		cin >> tmp;
		count += tmp < 0;
	}
	cout << count << '\n';
}