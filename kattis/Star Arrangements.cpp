#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> output;

	int sum;

	int i = ( n % 2 == 0) ? (n / 2) : (n / 2 + 1), 
		j = n / 2, 
		timesI = 1, 
		timesJ = 1;

	while(i > 1) {
		sum = i * timesI + j * timesJ;

		if (sum == n) {
			output.push_back(to_string(i) + "," + to_string(j));
			timesI = 1;
			timesJ = 1;
			if (j == i) {
				j--;
			}
			else if(i > j) {
				i--;
			}
		}

		if (sum > n) {
			if (j == i) {
				j--;
			}
			else if(i > j) {
				i--;
			}
		}
		if (sum < n) {
			if (timesI == timesJ) {
				timesI++;
			}
			else if(timesI > timesJ) {
				timesJ++;
			}
		}
	}
	cout << n << ":" << endl;
	for (auto i = output.rbegin(); i != output.rend(); ++i)	{
		cout << *i << endl;
	}

}