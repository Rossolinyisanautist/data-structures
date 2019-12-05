#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s, alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	int n, alphaIndex, alphaLen = alpha.length();

	while(true) {
		cin >> n;
		if(!n) break;
		
		cin >> s;

		reverse(s.begin(), s.end());

		for (int i = 0; i < s.length(); ++i) {
			alphaIndex = (alpha.find(s[i]) + n) % alphaLen;
			s[i] = alpha[alphaIndex];
		}
		cout << s << '\n';
	}
}