#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	while(N--) {
		int n;
		cin >> n;
		vector<string> numbers;

		for (int i = 0; i < n; ++i) {
			string temp;
			cin >> temp;
			numbers.push_back(temp);
		}
		sort(numbers.begin(), numbers.end());

		for (int i = 0; i < n - 1; ++i) {
			string number = numbers[i];
			string nextNumber = numbers[i + 1];

			if(nextNumber.substr(0, number.length()) == number) {
				goto notConsistent;
			}
		}
		cout << "YES\n"; 
			continue;
		notConsistent:
			cout << "NO\n";
	}
}