#include<iostream>
#include<string>

using namespace std;

int main() {
	string s = "";
	char c;
	while(cin >> c) {
		if(isupper(c)) {
			s += c;
		}
	}
	cout << s << '\n';
}