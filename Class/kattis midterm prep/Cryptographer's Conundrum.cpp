#include<iostream>

using namespace std;

int main() {

	char c;
	int i = 0, count = 0;
	while(cin >> c) {
		i++;
		if(i >= 4) i = 1;
		if(c == 'P' && i == 1) continue;
		if(c == 'E' && i == 2) continue;
		if(c == 'R' && i == 3) continue;
		count++;
	}
	cout << count << '\n';
}