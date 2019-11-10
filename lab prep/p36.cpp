#include<iostream>
#include<limits>
#include<stdexcept>

using namespace std;

uint64_t convertFromBase(const string& number, uint32_t base) {
	const static string digits = "0123456789ABCDEF";

	if(base < 2 || base > 16) {
		throw invalid_argument("Invalid base");
	}

	int result = 0;
	for(auto digit: number) {
		size_t pos = digits.find(digit);

		if(pos == string::npos || pos >= base) {
			throw invalid_argument("Invalid base");
		}
		result = base * result + pos;
	}
	return result;
}

int main() {
	string number;
	uint32_t base;

	while(cin >> number >> base) {
		try {
			uint64_t result = convertFromBase(number, base);
			cout << number << " in base 10 = " << result << '\n';
		}
		catch(invalid_argument& e) {
			cerr << e.what() << '\n';
		}
	}	
}