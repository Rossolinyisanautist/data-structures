#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	char c;
	vector<int> counters(26, 0);

	while(cin >> c) {
		c = toupper(c);
		if(isalpha(c)) {
			counters[c - 'A']++;
		}
	}
	char letter = 'A';
	for(int i = 0; i < counters.size(); i++) {
		cout << letter++ << ": " << counters[i] << '\n';
	}

	auto maxCounter = max_element(counters.begin(), counters.end());

	cout << "max counter: " << *maxCounter << '\n';

	cout << "most common letter: " << char(int(maxCounter - counters.begin()) + 'A') << '\n';
}