#include<iostream>

using namespace std;

int main() {
	long days,
	 	junks,
	 	minJunks = 1000000000, 
	 	currentDay = 0,
	 	daysToWait = 0;

	cin >> days;


	while(days--) {
		cin >> junks;
		if (junks < minJunks) {
			minJunks = junks;
			daysToWait = currentDay;
		}
		currentDay++;
	}
	cout << daysToWait << endl;
}