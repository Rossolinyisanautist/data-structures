#include<iostream>

using namespace std;

int main() {
	int numOfGroups, numberOfGnomes, gnomeId, prevGnomeId, index;
	cin >> numOfGroups;

	while(numOfGroups--) {
		cin >> numberOfGnomes >> prevGnomeId;
		index = -1;
		for (int i = 2; i <= numberOfGnomes; ++i) {

			cin >> gnomeId;
			if (index == -1 && gnomeId != prevGnomeId + 1) {
				// cout << "DB: " << "gnomeId: " << gnomeId << ", prevGnomeId: " << prevGnomeId << ", i: " << i << endl;
				index = i;
			}
			prevGnomeId = gnomeId;
		}
		cout << index << endl;
	}
}