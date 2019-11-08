#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int prevPopulation, expectedPopulation, actualPopulation, imigrants = 0;
		cin >> prevPopulation;

		do{
			expectedPopulation = 2 * prevPopulation;

			cin >> actualPopulation;

			if(actualPopulation > expectedPopulation) {
				imigrants += actualPopulation - expectedPopulation;
			}
			prevPopulation = actualPopulation;
		}while(actualPopulation != 0);
		cout << imigrants << '\n';
	}
}
