#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double engMiles, romanPaces;

	cin >> engMiles;

	romanPaces = engMiles * (1000 * (5280 / 4854.0));

	cout << (int) round(romanPaces);
} 