#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << "sec: ";
	int sec;
	cin >> sec;


	int hour = sec / 3600 % 24;

	sec %= 3600;

	int min = sec / 60;
	sec %= 60;

	cout << setfill('0')
		 << setw(2) << hour << ":"
		 << setw(2) << min << ":"
		 << setw(2) << sec << "\n";	

}