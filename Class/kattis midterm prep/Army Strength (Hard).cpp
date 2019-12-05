#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		int godzSize, mechaGodzSize;
		cin >> godzSize >> mechaGodzSize;

		int godzMax = -1;
		int mechaGodzMax = -1;
		while(godzSize--) {
			int temp;
			cin >> temp;
			godzMax = max(temp, godzMax);
		}
		while(mechaGodzSize--) {
			int temp;
			cin >> temp;
			mechaGodzMax = max(temp, mechaGodzMax);
		}
		if(mechaGodzMax <= godzMax) {
			cout << "Godzilla\n";
		}
		else {
			cout << "MechaGodzilla\n";
		}

	}
}