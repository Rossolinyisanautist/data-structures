#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int gnomes, prevID, currID, kingID;
		bool isFound = false;
		cin >> gnomes >> prevID;

		for (int i = 2; i <= gnomes; ++i) {
			cin >> currID;
			if(currID - prevID != 1 && !isFound) {
				kingID = i;
				isFound = true;
			}
			prevID = currID;
		}
		cout << kingID << '\n';
	}
}