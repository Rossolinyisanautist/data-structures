#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

int main() {
	cout << "size of int: " << sizeof(int) << "\n";
	cout << "max int: " << numeric_limits<int>::max() << "\n";
	cout << "min int: " << numeric_limits<int>::min() << "\n";

	int x, y;
	cout << "1st number: ";
	cin >> x;
	cout << "2nd number: ";
	cin >> y;

	cout << "distande between " << x << " and " << y << " is " << abs(x - y) << "\n";


	// int sum, diff, prod, qtn, rem;
	// sum = x + y;
	// diff = x - y;
	// prod = x * y;
	// qtn = x / y;
	// rem = x % y;

	// cout << x << " + " << y << " = " << sum << "\n";
	// cout << x << " - " << y << " = " << diff << "\n";
	// cout << x << " * " << y << " = " << prod << "\n";
	// cout << x << " / " << y << " = " << qtn << "\n";
	// cout << x << " % " << y << " = " << rem << "\n";

}