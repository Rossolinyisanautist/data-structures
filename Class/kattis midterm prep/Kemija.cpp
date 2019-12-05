#include<iostream>

using namespace std;

int main() {
	string s, res, v = "aeiou";
	getline(cin, s);

	for (int i = 0; i < s.length(); ++i) {
		char ch = s[i];
		res += ch;
		
		if(v.find(ch) != string:: npos) {
			i += 2;
		}
	}
	cout << res << '\n';
}