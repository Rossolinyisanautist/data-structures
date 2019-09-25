#include<iostream>

using namespace std;

int main() {
	int a, b, c, temp;

	cin >> a >> b >> c;

	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	string order;

	cin >> order;

	if (order == "ABC") cout << a << " " << b << " " << c << endl;
	if (order == "CBA")	cout << c << " " << b << " " << a << endl;
	if (order == "ACB")	cout << a << " " << c << " " << b << endl;
	if (order == "CAB")	cout << c << " " << a << " " << b << endl;
	if (order == "BAC")	cout << b << " " << a << " " << c << endl;
	if (order == "BCA") cout << b << " " << c << " " << a << endl;

}