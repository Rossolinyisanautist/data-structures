#include<iostream>

using namespace std;

string encode(string str) {
	string newStr;
	char currentChar = str.front();
	int currentCount = 0;
	for (int i = 0; i < str.length(); i++) {
		if(str.at(i) == currentChar) {
			currentCount++;
		}
		else if(str.at(i) != currentChar) {
			newStr += currentChar + to_string(currentCount);
			currentCount = 1;
			currentChar = str.at(i);
		}
		if(i == str.length() - 1) {
			newStr += currentChar + to_string(currentCount);
		}
	}
	return newStr;
}

string decode(string str) {
	string newStr = "";
	for (int i = 0; i < str.length() - 1; i += 2) {
		int length = newStr.length();
		int number = str.at(i + 1) - '0';
		char ch = str.at(i);
		
		newStr.insert(length, number, ch);
	}
	return newStr;
}

int main() {
	char operation;
	string str, newStr;
	cin >> operation;
	cin >> str;

	if(operation == 'E') {
		cout << encode(str) << '\n';	
	}
	else{
		cout << decode(str) << '\n';
	}
}


// H3e2l3o1W1o3r4l2d1!2
// H4e2l3o1W1o3r4l2d1!2
