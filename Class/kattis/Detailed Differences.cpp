#include<iostream>

using namespace std;

int main() {
	int n;
	string first, second, result;

	getline(cin, first);
	n = stoi(first);

	while(n--) {
		getline(cin, first);
		getline(cin, second);
		result = "";

		for(int i = 0; i < first.length(); i++){
			int c1 = first.at(i);
			int c2 = second.at(i);
			result += c1 != c2 ? '*' : '.';
		}
		cout << first << '\n' << second << '\n' << result << '\n';
	}
}