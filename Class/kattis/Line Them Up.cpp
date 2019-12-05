#include<iostream>
#include<string>

using namespace std;

int main () {
	int n;
	bool asc, desc;
	asc = desc = false;
	string current, next;

	getline(cin, current);
	n = stoi(current);

	getline(cin, current);
	n--;
	while(n--) {
		getline(cin, next);

		if(next > current) {
			asc = true;
		}
		else if(next < current) {
			desc = true;
		}
		current = next;
	}
	cout << (asc && desc ? "NEITHER" : asc ? "INCREASING" : "DECREASING") << '\n';
}