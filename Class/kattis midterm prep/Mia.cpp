#include<iostream>

using namespace std;

void p1wins() {
	cout << "Player 1 wins.\n";
}
void p2wins() {
	cout << "Player 2 wins.\n";
}
void tie() {
	cout << "Tie.\n";	
}

int main() {
	int a1, a2, b1, b2;

	while(cin >> a1 >> a2 >> b1 >> b2) {
		if(a1 + a2 + b1 + b2 == 0) break;

		if((a1 == 1 && a2 == 2) || (a1 == 2 && a2 == 1)) {
			if((b1 == 1 && b2 == 2) || (b1 == 2 && b2 == 1)) {
				tie();
				continue;
			}
			p1wins();
		}
		else if((b1 == 1 && b2 == 2) || (b1 == 2 && b2 == 1)) {
			p2wins();
		}
		else if(a1 == a2) {
			if(b1 == b2) {
				if(b1 < a1) {
					p1wins();
				}
				else if(b1 > a2){
					p2wins();
				}
				else {
					tie();
				}
				continue;
			}
			p1wins();
		}
		else if(b1 == b2) {
			p2wins();
		}
		else {
			if(a1 < a2) swap(a1, a2);
			if(b1 < b2) swap(b1, b2);

			int p1 = a1 * 10 + a2;
			int p2 = b1 * 10 + b2;

			if(p1 > p2) {
				p1wins();
			}
			else if(p1 < p2) {
				p2wins();
			}
			else {
				tie();
			}
		}
	}
}

