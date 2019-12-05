#include<iostream>

using namespace std;

int main() {
	string s;

	char c;

	while(cin >> c) {
		if(c == '<') {
			s.pop_back();
		}
		else {
			s += c;	
		}
	}
	cout << s << '\n';
}