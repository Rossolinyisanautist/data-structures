#include<iostream>

using namespace std;

int main() {
	int g1, g2, g3, g4;
	int e1, e2, e3, e4;
	
	cin >> g1 >> g2 >> g3 >> g4;
	cin >> e1 >> e2 >> e3 >> e4;

	int gunnar = g1 + g2 + g3 + g4;
	int emma = e1 + e2 + e3 + e4;

	if(gunnar > emma) { cout << "Gunnar\n"; }
	else if(gunnar < emma) { cout << "Emma\n"; }
	else if(gunnar == emma) { cout << "Tie\n"; }
} 