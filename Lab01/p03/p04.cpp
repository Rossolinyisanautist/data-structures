#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int main() {
	cout << "size of double: " << sizeof(double) << "\n";
	cout << "max dobule: " << numeric_limits<double>::max() << "\n";
	cout << "min double: " << numeric_limits<double>::min() << "\n";

	double x, y;
	cout << "1st double: ";
	cin >> x;
	cout << "2nd dobule: ";
	cin >> y;

	// cout << "distande between " << x << " and " << y << " is " << abs(x - y) << "\n";

	double sum, diff, prod, qtn, rem;
	sum = x + y;
	diff = x - y;
	prod = x * y;
	qtn = x / y;


	cout << x << " + " << y << " = " << sum << "\n";
	cout << x << " - " << y << " = " << diff << "\n";
	cout << x << " * " << y << " = " << prod << "\n";
	cout << x << " / " << y << " = " << qtn << "\n";
	

}