#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	if(s.find("ss") != string::npos) {
		cout << "hiss\n";
	}
	else {
		cout << "no hiss\n";
	}
}