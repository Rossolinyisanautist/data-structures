#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 10; ++i) {
		int tmp;
		cin >> tmp;
		if( find(v.begin(), v.end(), tmp % 42) == v.end()) {
			v.push_back(tmp % 42);	
		}
	}
	cout << v.size() << '\n';

}