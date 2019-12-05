#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int input,
			prevPopulation, 
			imigrants = 0;

		cin >> input;
		prevPopulation = input;

		do {
			int actualTotalPopulation, expectedTotalPopulation = 2 * prevPopulation;
			cin >> input;
			actualTotalPopulation = input;

			if (actualTotalPopulation > expectedTotalPopulation) {
				imigrants += actualTotalPopulation - expectedTotalPopulation;
			}
			prevPopulation = actualTotalPopulation;
		}while(input != 0);
		cout << imigrants << endl;
	}
}