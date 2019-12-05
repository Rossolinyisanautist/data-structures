#include<iostream>

using namespace std;

int main() {
	string name;
	cout << "Name: ";
	cin >> name;

	string border(name.length() + 4, '*');

	cout << border << '\n';
	cout << "* " << string(name.length(), ' ') << " *" << '\n';
	cout << "* " << name << " *" << '\n';
	cout << "* " << string(name.length(), ' ') << " *" << '\n';
	cout << border << '\n';
}