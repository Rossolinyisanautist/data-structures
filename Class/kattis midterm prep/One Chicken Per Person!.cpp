#include<iostream>

using namespace std;

int main() {
	int ppl, chkn;

	cin >> ppl >> chkn;

	int diff = ppl - chkn;

	if(diff == -1) {
		cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
	}
	else if(diff == 1) {
		cout << "Dr. Chaz needs 1 more piece of chicken!\n";
	}
	else if(diff < 0) {
		cout << "Dr. Chaz will have " << -diff << " pieces of chicken left over!\n";
	}
	else if(diff > 0) {
		cout << "Dr. Chaz needs " << diff << " more pieces of chicken!\n";
	}
	
}