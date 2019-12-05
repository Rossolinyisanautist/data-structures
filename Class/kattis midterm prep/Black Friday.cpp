#include<iostream>
#include<vector>

using namespace std;

int count(const vector<int>& v, int n) {
	int res = 0;
	for (int i = 0; i < v.size(); ++i) {
		res += v[i] == n;
	}
	return res;
}

int main() {
	int n, inp uniqueMax = -1, index = -1;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; ++i) {
		cin >> inp;
		v.push_back(inp);
	}

	for (int i = 0; i < n; ++i) {
		if(v[i] > uniqueMax and count(v, v[i]) == 1) {
			uniqueMax = v[i];
			index = i;
		}
	}
	if(index == -1) {
		cout << "none" << '\n';
	}
	else { 
		cout << (index + 1) << '\n';
	}
}

