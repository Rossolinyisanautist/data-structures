#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main() {
	char c;

	while(cin >> c) {
		if (isupper(c)) {
			cout << c;
		}
	}
	cout << endl;
}