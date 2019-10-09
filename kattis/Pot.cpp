#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	int n, number, power, result;
	string str;
	
	getline(cin, str);
	n = stoi(str);

	while(n--) {
		getline(cin, str);
		power = str.back() - '0';

		number = stoi(str.substr(0, str.length() - 1));
		number = pow( (double) number, (double) power );
		
		result += number;
	}
	cout << result << '\n';
}