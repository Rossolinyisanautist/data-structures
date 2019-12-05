#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
	double inp;

	cin >> inp;

	inp = round(inp * (1000.0 * (5280 / 4854.0)));

	cout << (int) inp << '\n';
}