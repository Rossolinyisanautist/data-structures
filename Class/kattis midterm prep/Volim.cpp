#include<iostream>

using namespace std;

int main() {
	int player, n, time = 0;
	cin >> player >> n;

	while(n--) {
		int secs;
		cin >> secs;
		char ans;

		cin >> ans;
		time += secs;

		if(time >= 210) {
			break;
		}
		if(ans == 'T') {
			player++;
		}
		if(player == 9) player = 1;
	}
	cout << player << '\n';
}