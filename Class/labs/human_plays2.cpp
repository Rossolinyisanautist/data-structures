#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<chrono>
#include<random>
#include<algorithm>

const int defaultSize = 4;
const int maxSize = 6;
const int minSize = 3;

using namespace std;

int parseCmdArgs(int argc, char* argv[]) {
	int res = defaultSize;

	if(argc == 2) {
		istringstream sinp(argv[1]);
		int t;
		char c;
		if(sinp >> t and !(sinp >> c)) {
			t = abs(t);
			res = minSize <= t and t <= maxSize ? t : defaultSize;
		}
	}

	return res;
}

vector<string> fillNumbers(int n) {
	vector<int> lowLim = { 102, 1023, 10234, 102345 };
	vector<int> upLim = { 987, 9876, 98765, 987654 };
	vector<string> res;

	for(int i = lowLim[n - minSize]; i <= upLim[n - maxSize]; i++) {
		string number = to_string(i);
		set<char> s(number.begin(), number.end());
		if(number.length() == s.size()) {
			res.push_back(number);
		}
	}
	return res;
}
string getUserNum(const vector<string>& nums) {
	string res;
	while(1) {
		cout << "Your guess: ";
		string line;
		getline(cin, line);
		istringstream sinp(line);
		int t;
		char c;
		if(sinp >> t and !(sinp >> c)) {
			string res = to_string(t);
			if(find(begin(nums), end(nums), res) != nums.end()) {
				return res;
			}
		}
		cout << "Invalid number\n";
	}
}
	
void analyze(const string& compNum, const string& userNum, int& digits, int& positions) {
	digits = positions = 0;

	for (int i = 0; i < compNum.length(); ++i) {
		for(int j = 0; j < userNum.length(); j++) {
			if(compNum[i] == userNum[j]) {
				digits++;
				positions += i == j;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int size = parseCmdArgs(argc, argv);

	vector<string> nums = fillNumbers(size);

	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(begin(nums), end(nums), rnd);

	string compNum = nums.front();
	int moves = 0, positions = 0, digits = 0;

	while(digits != size and positions != size) {
		string userNum = getUserNum(nums);
		analyze(compNum, userNum, digits, positions);
		cout << "digits:    " << digits << '\n';
		cout << "positions: " << positions << '\n';
		moves++;
	}
	cout << "You won.\n";
	cout << "Your result is " << moves << (moves == 1 ? " move." : " moves") << '\n';
}
// vector<string> fillNumbers(int n) {

// }

