#include<iostream>

using namespace std;

int main() {
	int arr[26];
	for (int i = 0; i < 26; ++i) {
		arr[i] = 0;
	}

	string str;
	cin >> str;

	for(char c : str) {
		int i = c - 'a';
		arr[i]++;
	}

	int count = -1;
	for(int n : arr) {
		count += (n % 2 != 0);
	}

	cout << (count < 0 ? 0 : count) << '\n';
}