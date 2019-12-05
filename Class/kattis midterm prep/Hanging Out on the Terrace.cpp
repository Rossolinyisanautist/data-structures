#include<iostream>

using namespace std;

int main() {
	int maxPpl, ppl = 0, groupRejects = 0, events, group;

	cin >> maxPpl >> events;

	while(events--) {
		char ch;

		cin >> ch;
		cin.ignore(5) >> group;

		if(ch == 'e') {
			if(ppl + group > maxPpl) {
				groupRejects++;
			}
			else ppl += group;
		}
		else ppl -= group;
	}
	cout << groupRejects << '\n';
}