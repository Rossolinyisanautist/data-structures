#include<iostream>

using namespace std;

int main() {
	int gold, silv, copp;

	cin >> gold >> silv >> copp;

	int buyPow = 3 * gold + 2 * silv + copp;

	if(buyPow >= 8) {
		cout << "Province or Gold";
	}
	else if(buyPow >= 6) {
		cout << "Duchy or Gold";
	}
	else if(buyPow >= 5) {
		cout << "Duchy or Silver";
	}
	else if(buyPow >= 3) {
		cout << "Estate or Silver";
	}
	else if(buyPow >= 2) {
		cout << "Estate or Copper";
	}
	else {
		cout << "Copper";
	}
	cout << endl;
}