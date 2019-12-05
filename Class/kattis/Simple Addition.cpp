#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, sum = "";
	cin >> a >> b;

	if( a.length() < b.length() ) swap(a, b);
	int lenDiff = a.length() - b.length();
	int buffer = 0;

	for(int i = a.length() - 1; i >= 0; i--) {
		int digitA = a.at(i) - '0';

		if(i - lenDiff >= 0) {
			int digitB = b.at(i - lenDiff) - '0';

			int digitSum = digitA + digitB + buffer;

			if(digitSum > 9) {
				int secondSumDigit = digitSum % 10;
				buffer = 1;
				sum.insert(0, to_string(secondSumDigit));
			}
			else {
				sum.insert(0, to_string(digitSum));
				buffer = 0;
			}
		}
		else {
			digitA += buffer;

			if(digitA > 9) {
				int secondDigit = digitA % 10;
				buffer = 1;
				sum.insert(0, to_string(secondDigit));
			}
			else {
				sum.insert(0, to_string(digitA));
				buffer = 0;				
			}
		}
	}
	if(buffer == 1) sum.insert(0, to_string(buffer));

	cout << sum << '\n';
}



