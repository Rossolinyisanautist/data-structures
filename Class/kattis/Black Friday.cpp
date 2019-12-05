#include <iostream>
#include <vector>
using namespace std;

int findNum(vector<int> arr, int size, int number) {
	int count = 0;
	for (int i = 0; i < size; ++i) {
		if(arr[i] == number) {
			count++;
		} 
	}
	return count;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr;
	arr.resize(n, -1);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int max = -1;
	int index = -1;

	for (int i = 0; i < n; ++i) {
		int num = arr[i];

		if (num > max && findNum(arr, n, num) == 1) {
			max = num;
			index = i;
		}
	}
	if(index == -1) {
		cout << "none\n";
	}
	else {
		cout << ++index << '\n';
	}
}

