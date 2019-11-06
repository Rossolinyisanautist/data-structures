#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long number;
	cin >> number;

	string binary = "";
	long decimal = 0;

	while(number > 0) {
		binary.insert(0, to_string(number % 2));
		number /= 2;
	}

	for (int i = 0; i < binary.length(); ++i) {
		decimal += binary[i] == '1' ? pow(2, i): 0;
	}
	cout << decimal << '\n';

}