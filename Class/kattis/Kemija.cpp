#include <iostream>
#include <string>
using namespace std;

int main() {
	string message, result;

	getline(cin, message);

	for (int i = 0; i < message.length(); ++i) {

		switch(message.at(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				i+=2;
				break;
		}
		result += message.at(i);
	}
	cout << result << '\n';
}