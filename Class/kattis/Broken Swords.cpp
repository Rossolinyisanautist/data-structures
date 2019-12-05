#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int tb = 0, lr = 0, i;

	while(n--) {
		i = 0;
		while(i < 4) {
			char ch;
			cin >> ch;
			if(i < 2) {
				tb += (ch == '0');
			}
			else {
				lr += (ch == '0');	
			}
			i++;
		}
	}
	int count = 0;
	while(tb >= 2 && lr >= 2) {
		tb -= 2;
		lr -= 2;
		count++;
	}
	cout << count << ' ' << tb << ' ' << lr << '\n';
}