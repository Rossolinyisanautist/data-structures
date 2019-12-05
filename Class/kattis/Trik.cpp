#include <iostream>

using namespace std;

int main() {
	int cup1 = 1, cup2 = 0, cup3 = 0;

	char a;
	while(cin >> a) {
		switch(a) {
			case 'A':
				swap(cup1, cup2);
				break;
			case 'B':
				swap(cup3, cup2);
				break;
			case 'C':
				swap(cup1, cup3);
				break;
		}
	}
	
	cout << (cup1 ? 1 : cup2 ? 2 : 3) << '\n';
}