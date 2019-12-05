#include <iostream>

using namespace std;

int main() {
	string str, newStr = "";

	cin >> str;

	for (int i = 0; i < str.length(); ++i) {
		char ch = str.at(i);
		
		if(ch == '<') newStr.pop_back();
		else newStr += ch;
	}
	cout << newStr << '\n';
}