#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> buses;
	
	while(n--) {
		int temp;
		cin >> temp;
		buses.push_back(temp);
	}
	sort(buses.begin(), buses.end());

	int len = 0;
	int first = buses.front();

	string result;
	for(int i = 0; i < buses.size(); i++) {
		if(buses[i + 1] - buses[i] == 1) {
			len++;
		}
		else {
			if(len == 1) {
				result += to_string(first) + " " + to_string(first + len) + " ";
			}
			else if(len > 1) {
				result += to_string(first) + "-" + to_string(first + len) + " ";
			}
			else {
				result += to_string(first) + " ";
			}
			len = 0;
			first = buses[i + 1];
		}
	}

	cout << result << '\n';
}

// 180 141 174 143 142 175
// 141 142 143 174 175 180





