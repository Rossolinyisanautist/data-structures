#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		string s;
		vector<string> v;
		cin >> s;

		int len = sqrt(s.length());
		int start = 0;

		for (int i = 0; i < len; ++i) {
			string temp = s.substr(start, len);
			v.push_back(temp);
			start += len;
		}

		for (int i = len - 1; i >= 0; i--) {
			for(int j = 0; j < len; j++) {
				cout << v[j][i];	
			}
		}
		cout << '\n';
	}
}

// RosesAreRedVioletsAreBlue