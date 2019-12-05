#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	string bin;

	while(n != 0) {
		bin += to_string(n % 2);
		n /= 2;
	}
	reverse(bin.begin(), bin.end());

	n = 0;
	for(int i = 0; i < bin.length(); i++) {
		if(bin[i] == '1') {
			n += pow(2, i);		
		}
	}

	// cout << bin << '\n';
	cout << n << '\n';
}