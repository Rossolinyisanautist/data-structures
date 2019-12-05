#include<iostream>

using namespace std;

int main () {
	int a, b, c, d, p, m, g;
	cin >> a >> b >> c >> d >> p >> m >> g;

	int countP = 0;
	int countM = 0;
	int countG = 0;

	p--;
	m--;
	g--;

	if(p % (a + b) < a) {	
		countP++;
	}
	if(p % (c + d) < c) {
		countP++;
	}
	switch(countP) {
		case 0:
			cout << "none\n";
			break;
		case 1:
			cout << "one\n";
			break;
		case 2:
			cout << "both\n";
			break;
	}

	if(m % (a + b) < a) {	
		countM++;
	}
	if(m % (c + d) < c) {
		countM++;
	}
	switch(countM) {
		case 0:
			cout << "none\n";
			break;
		case 1:
			cout << "one\n";
			break;
		case 2:
			cout << "both\n";
			break;
	}

	if(g % (a + b) < a) {	
		countG++;
	}
	if(g % (c + d) < c) {
		countG++;
	}
	switch(countG) {
		case 0:
			cout << "none\n";
			break;
		case 1:
			cout << "one\n";
			break;
		case 2:
			cout << "both\n";
			break;
	}

}