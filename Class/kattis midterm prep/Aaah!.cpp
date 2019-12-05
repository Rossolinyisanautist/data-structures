#include<iostream>
#include<string>

using namespace std;

int main() {
	string s, s2;
	cin >> s >> s2;

	if(s.length() >= s2.length()) {
		cout << "go\n";
	}
	else {
		cout << "no\n";
	}
}