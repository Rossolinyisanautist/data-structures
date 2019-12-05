#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	int sec;
	cin >> sec;

	int hour, min;	

	sec %= (24 * 3600);

	hour = sec / 3600;
	sec %= 3600;

	min = sec / 60;
	sec %= 60;

	cout << setfill('0') 
		 << setw(2) << hour << ':' 
		 << setw(2) << min << ':' 
		 << setw(2) << sec << '\n';
}