#include<iostream>

using namespace std;

int main() {
	int length;

	cin >> length;

	int result = 0;

	for (int i = 0; i < length; ++i) {
		int temp;
		cin >> temp;
		result += temp < 0 ? 1 : 0;
	}

	cout << result << endl;
}