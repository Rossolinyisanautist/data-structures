#include<iostream>

using namespace std;

int main() {
	int list[10];

	for (int i = 0; i < 10; ++i) {
		int x;

		cin >> x;

		x %= 42;

		list[i] = x;
	}
	
	int count = 0;

	for (int i = 0; i < 10; ++i) {
		int j = 0;
		for (j = 0; j < i; ++j) {
			if(list[i] == list[j]) {
				break;
			}
		}
		if(i == j) {
			count++;
		}
	}
	cout << (count == 0 ? 1 : count) << '\n';

}