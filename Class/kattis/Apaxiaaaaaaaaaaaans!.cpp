#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string str, newStr = "";

	getline(cin, str);

	char prevC = str.at(0);
	newStr = prevC;

	for (char c : str) {
		if (c != prevC ) {
			newStr += c;
		}
		prevC = c;
	}
	cout << newStr << "\n";
}