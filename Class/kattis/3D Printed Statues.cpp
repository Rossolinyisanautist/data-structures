#include<iostream>

using namespace std;

int main() {
	int n, printers = 1, statues = 0, day = 1;

	cin >> n;

	while(true) {
		statues = printers;		
		if (statues >= n) {
			break;
		}
		printers *= 2;
		day++;
	}
	cout << day << endl;
}