#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	string result  = "";
	for (int i = 0; i < a; ++i) {
		string tempLine = "";
		for (int j = 0; j < b; ++j) {
			char ch;
			cin >> ch;
			for (int k = 0; k < d; ++k) {
				tempLine += ch;
			}
		}
		for (int l = 0; l < c; ++l) {
			result += tempLine + '\n';	
		}	
	}
	cout << result;
}