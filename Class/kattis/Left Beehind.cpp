#include<iostream>

using namespace std;

int main() {
	int sweet, sour;

	for (int i = 0; i < 15; ++i) {
		cin >> sweet >> sour;
		
		if (sweet + sour == 0) {
			break;
		}

		if (sweet + sour == 13) {
			cout << "Never speak again.";
		}
		else if(sweet > sour) {
			cout << "To the convention.";
		}
		else if(sweet < sour) {
			cout << "Left beehind.";
		}
		else {
			cout << "Undecided.";	
		}
		cout << endl;
	}

}