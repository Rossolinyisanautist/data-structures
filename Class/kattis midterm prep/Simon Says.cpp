#include<iostream>

using namespace std;

int main() {
	int n;
	string s;
	getline(cin, s);
	n = stoi(s);

	while(n--) {
		getline(cin, s);
		if(s.find("Simon says ") != string::npos) {
			cout << s.substr(11) << '\n';
		}
	}
}