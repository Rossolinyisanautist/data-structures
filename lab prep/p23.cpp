#include<iostream>

using namespace std;

int main() {
	string str;
	getline(cin, str);

	string buff;
	for(char c : str) {
		if(isalpha(c))
			buff += tolower(c);
	}

	string rev = buff;
	reverse(rev.begin(), rev.end());

	cout << ( rev == buff ? "palindrome" : "not a palindrome") << '\n';
}