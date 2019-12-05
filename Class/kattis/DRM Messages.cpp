#include <iostream>

using namespace std;

int main() {
	string str, firstHalf, secondHalf, alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> str;

	firstHalf = str.substr(0,  str.length() / 2);
	secondHalf = str.substr(str.length() / 2);

	int rotation1 = 0;
	int rotation2 = 0;

	for (int i = 0; i < firstHalf.length(); ++i) {
		rotation1 += firstHalf.at(i) - 'A';
		rotation2 += secondHalf.at(i) - 'A';
	}
	str = "";

	for (int i = 0; i < firstHalf.length(); ++i) {
		int ch1 = alpha.find( firstHalf.at(i) );
		int ch2 = alpha.find( secondHalf.at(i) );

		ch1 = (ch1 + rotation1) % 26;
		ch2 = (ch2 + rotation2) % 26;

		int newIndex = (ch1 + ch2) % 26;
		str += alpha.at(newIndex);
	}
	cout << str << '\n';

}