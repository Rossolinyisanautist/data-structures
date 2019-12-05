#include <iostream>

using namespace std;

int main() {
	int set = 1;
	while(true) {
		int n, i = 0;
		cin >> n;
		if(!n) break;
		string list[n];

		while(i < n) 
			cin >> list[i++];

		cout << "SET " << set << '\n';

		for (int i = 0; i < n; i += 2) 
			cout << list[i] << '\n';

		for (int i = n - 1 - (n % 2 == 1); i > 0; i -= 2) 
			cout << list[i] << '\n';
		
		set++;
	}
}