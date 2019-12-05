#include<iostream>
#include<sstream>
using namespace std;

int main() {
	string s;

	while(getline(cin, s)) {
		istringstream isso(s);
		int n;
		if(isso >> n >> ws and isso.eof()) {
			cout << "next: " << n + 1 << '\n';
		}
		else {
			cout << "invalid int: " << s << '\n'; 
		}
	}
}