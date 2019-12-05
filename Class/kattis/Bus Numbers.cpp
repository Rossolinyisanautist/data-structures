#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int buses[n];
	int i = 0;

	while(i < n) {
		cin >> buses[i];
		i++;
	}
	for (int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < n - i - 1; j++) {
			if(buses[j] > buses[j + 1]) swap(buses[j], buses[j + 1]);
		}
	}

	int first = buses[0];
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if(buses[i] == buses[i + 1] - 1) {
			count++;
		}
		else {
			if(count == 1) {
				cout << buses[i - 1] << ' ' << buses[i] << ' ';
			}
			else if (count > 1){
				cout << first << '-' << first + count << ' ';	
			}
			else {
				cout << buses[i] << ' ';
			}
			first = buses[i + 1];
			count = 0;
		}	
	}
	cout << '\n';
}


// 141 142 143 174 175 180 181 182
// 141 142 143 174 175 180 182 184 186 187 188



