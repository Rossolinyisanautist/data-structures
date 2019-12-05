#include<iostream>

using namespace std;

int main() {
	int sweet, sour;
	while(cin >> sweet >> sour) {
		if(sweet + sour == 0) break;
		
		if(sweet + sour == 13) {
			cout << "Never speak again.\n";
		}
		else if(sweet < sour) {
			cout << "Left beehind.\n";
		}
		else if(sweet > sour) {
			cout << "To the convention.\n";
		}
		else if(sweet == sour) {
			cout << "Undecided.\n";
		}
	}
}