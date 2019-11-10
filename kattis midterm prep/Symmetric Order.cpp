#include<iostream>
#include<vector>

using namespace std;

int main() {
	int setCount = 1;
	while(true) {
		int n;
		cin >> n;
		if(!n) break;

		vector<string> v;
		while(n--) {
			string temp;
			cin >> temp;
			v.push_back(temp);
		}
		cout << "SET " << setCount++ << '\n';
		for (int i = 0; i < v.size(); i += 2) {
			cout << v[i] << '\n';
		}
		for(int i = v.size() - 1 - (v.size() % 2 != 0); i >= 0; i -= 2) {
			cout << v[i] << '\n';
		}
	}
}