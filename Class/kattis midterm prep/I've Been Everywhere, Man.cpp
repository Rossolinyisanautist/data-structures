#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int t;
		cin >> t;
		vector<string> cities;

		while(t--) {
			string city;
			cin >> city;
			if( find(cities.begin(), cities.end(), city) == cities.end() ) {
				cities.push_back(city);
			}
		}
		cout << cities.size() << '\n';
	}

}