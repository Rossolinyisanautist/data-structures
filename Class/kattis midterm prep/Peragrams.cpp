#include<iostream>
#include<vector>
using namespace std;

int main() {
	string s;
	vector<int> letterCount;	
	letterCount.resize(26, 0);

	char c;
	while(cin >> c) {
		letterCount[c - 'a']++;
	}
	int k = -1;
	for (int i = 0; i < 26; ++i) {
		k += letterCount[i] % 2 != 0;
	}
	cout << (k < 0 ? 0 : k) << '\n';
}