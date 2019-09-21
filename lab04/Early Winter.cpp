#include<iostream>

using namespace std;

int main() {
	int n, d, count = 0;

	cin >> n >> d;

	std::vector<char> v;;
	int max = d;

	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		if (temp <= d) {
			break;
		}

	}

	cout << count + 1 << endl;
}