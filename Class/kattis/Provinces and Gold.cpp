#include<iostream>

using namespace std;

int main() {
	int G, S, C, Power;
	string Dominion, Treasure;

	cin >> G >> S >> C;

	Power = G * 3 + S * 2 + C;

	if(Power >= 8) {
		Dominion = "Province";
	}
	else if(Power >= 5) {
		Dominion = "Duchy";
	}
	else if(Power >= 2) {
		Dominion = "Estate";
	}
	else {
		Dominion = "Nothing";
	}

	if(Power >= 6) {
		Treasure = "Gold";
	}
	else if(Power >= 3) {
		Treasure = "Silver";
	}
	else {
		Treasure = "Copper";
	}

	if(Dominion == "Nothing") {
		cout << Treasure << "\n";
	}
	else {
		cout << Dominion << " or " << Treasure << "\n";
	}
}