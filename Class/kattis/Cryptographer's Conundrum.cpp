#include<iostream>

using namespace std;

int main() {
	string cipher;

	getline(cin, cipher);

	int days = 0;
	for(int i = 0; i < cipher.length(); i += 3) {
		char c1 = cipher.at(i);
		char c2 = cipher.at(i + 1);
		char c3 = cipher.at(i + 2);

		if(c1 != 'P') days++;
		if(c2 != 'E') days++;
		if(c3 != 'R') days++;
	}
	cout << days << '\n';
}