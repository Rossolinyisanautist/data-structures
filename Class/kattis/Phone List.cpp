#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int cases;
	cin >> cases;

	next: 
	while(cases--) {
		int n;
		cin >> n;
		vector<string> v;
		v.resize(n, "!");

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n - 1; ++i) {
			string s1 = v[i];
			string s2 = v[i + 1];
	
			if(s2.substr(0, s1.length()) == s1) {
				goto notConsistent;
			}
		}
		cout << "YES" << '\n';
		goto next;
		notConsistent: 
			cout << "NO" << '\n';
	}
}

