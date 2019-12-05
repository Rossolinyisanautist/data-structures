#include<iostream>
#include<cmath>
#include<vector>


using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		int len = s.length();
		int root = sqrt(len);
		
		while(root * root < len) {
			root++;
		}

		s.insert(len, root * root - len, '*');
		vector<string> v;

		int start = 0;
		for (int i = 0; i < root; ++i) {
			string s2 = s.substr(start, root);
			v.push_back(s2);
			start += root;
		}
		for (int i = 0; i < root; ++i) {
			for(int j = root - 1; j >= 0; j--) {
				if(v[j][i] != '*') {
					cout << v[j][i] ;	
				}
			}
		}
		cout << '\n';
	}
}