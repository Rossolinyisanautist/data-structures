#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> x;
	vector<int> y;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			char c;
			cin >> c;
			if(c == '*') {
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(i != j) {
				if(x[i] == x[j] or y[i] == y[j]) goto invalid;
				if(abs(x[i] - x[j]) == abs(y[i] - y[j])) goto invalid;
			}
		} 
	}
	cout << "valid\n";
	return 0;
	invalid:	
		cout << "invalid\n";
}