#include<iostream>

using namespace std;

int main() {
	int points = 0, t = 0, c = 0, g = 0;
	char ch;

	while(cin >> ch) {
		t += ch == 'T';
		c += ch == 'C';
		g += ch == 'G';
	}
	points = t * t + c * c + g * g;
	while(t && c && g) {
		t--;
		c--;
		g--;
		points += 7;
	}
	cout << points << '\n';
}