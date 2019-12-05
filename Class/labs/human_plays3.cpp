#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<vector>
#include<chrono>
#include<random>

using namespace std;

const int defSize = 4;
const int maxSize = 6;
const int minSize = 3;

string getHumanGuess(const vector<string>& nums) {
	while(1) {
		cout << "Your gues: ";
		string line;
		getline(cin, line);
		istringstream sinp(line);
		int t;
		char c;
		if(sinp >> t and !(sinp >> c)) {
			string res = to_string(t);
			if(find(nums.begin(), nums.end(), res) != nums.end()){
				return res;
			}
		}
		cout << "Invalid number.\n";
	}
}

vector<string> fillNumbers(int size) {
	vector<int> lowLim = {102, 1023, 10234, 102345};
	vector<int> upLim = {987, 9876, 98765 ,987654};
	vector<string> res;

	for(int i = lowLim[size - minSize]; i <= upLim[size - maxSize]; i++) {
		string num = to_string(i);
		set<char> s(num.begin(), num.end());
		if(s.size() == num.length()) {
			res.push_back(num);
		}
	}
	return res;
}

int parseCmdLineArgs(int argc, char* argv[]) {
	int res = defSize;

	if(argc == 2) {
		istringstream sinp(argv[1]);
		int t;
		char c;
		if(sinp >> t and !(sinp >> c)) {
			t = abs(t);
			res = minSize <= t and t <= maxSize ? t : defSize;
		}
	}
	return res;
}

void analyze(const string& compNum, const string& userNum, int& d, int& p) {
	d = p = 0;

	for(int i = 0; i < compNum.length(); i++ ) {
		for(int j = 0; j < userNum.length(); j++) {
			if(compNum[i] == userNum[j]) {
				d++;
				p += i == j;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int size = parseCmdLineArgs(argc, argv);

	vector<string> nums = fillNumbers(size);
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(nums.begin(), nums.end(), rnd);

	string compNum = nums.front();
	int moves = 0, dig = 0, pos = 0;

	while( !(dig == size and pos == size)) {
		string userNum = getHumanGuess(nums);
		analyze(compNum, userNum, dig, pos);
		cout << "digits:    " << dig << '\n';
		cout << "positions: " << pos << '\n';
		moves++;
	}
	cout << "You won.\n";
	cout << "Your result is " << moves << (moves == 1 ? " move." : " moves.\n");
}

















