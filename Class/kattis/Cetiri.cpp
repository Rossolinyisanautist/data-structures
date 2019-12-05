#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int inp[3], d1, d2, answer;

	for(int i = 0; i < 3; i++) {
		cin >> inp[i];
	}

	if(inp[0] > inp[1]) { swap(inp[0], inp[1]); }
	if(inp[1] > inp[2]) { swap(inp[1], inp[2]); }
	if(inp[0] > inp[1]) { swap(inp[0], inp[1]); }

	d1 = inp[1] - inp[0];
	d2 = inp[2] - inp[1];

	if(d1 == d2) {
		answer = inp[2] + d1;
	}	
	else if(d1 < d2) {
		answer = inp[1] + d1;
	}
	else if(d1 > d2) {
		answer = inp[0] + d2;
	}

	cout << answer;

} 