#include<iostream>
#include<string>

using namespace std;

int main() {
	string actual, expected;
	getline(cin, actual);
	getline(cin, expected);

	if (expected.length() <= actual.length()) {
		cout << "go\n";
	}
	else {
		cout << "no\n";
	}
}