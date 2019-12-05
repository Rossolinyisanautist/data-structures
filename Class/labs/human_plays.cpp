#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<algorithm>
#include<chrono>
#include<random>

using namespace std;

const int defaultSize = 4;
const int maxSize = 6;
const int minSize = 3;


int parseCmdArgs(int argc, char* argv[]) {
	int res = defaultSize;

	if(argc == 2) {
		int t;
		istringstream sinp(argv[1]);
		if(sinp >> t and sinp.eof()) {
			t = abs(t);
			res = minSize <= t and t <= maxSize ? t : defaultSize;
		}
	}
	return res;
}

vector<string> fillNumbers(int n) {
	vector<int> lowBounds = { 102, 1023, 10234, 102345 };
	vector<int> upBound = { 987, 9876, 98765, 987654 };
	vector<string> res;

	for(int i = lowBounds[n - minSize]; i <= upBound[n - maxSize]; i++) {
		string number = to_string(i);
		set<char> s(number.begin(), number.end());
		if(s.size() == number.length()) {
			res.push_back(number);
		}
	}

	return res;
}

void analyze(const string& compNum, const string& userNum, int& d, int& p) {
	d = p = 0;
	for(int i = 0; i < userNum.length(); i++) {
		for(int j = 0; j < compNum.length(); j++) {
			if(compNum[i] == userNum[j]) {
				d++;
				p += i == j;
			}
		}
	}
}

string getUserNumber(const vector<string>& numbers) {
	while(true) {
		cout << "your guess: ";
		string line;
		getline(cin, line);
		istringstream sinp(line);
		int t;
		char c;
		if(sinp >> t and !(sinp >> c)) {
			string res = to_string(t);
			if((find(begin(numbers), end(numbers), res) != numbers.end())) {
				return res;
			}
		}
		cout << "invalid number\n";
	}
}

int main(int argc, char* argv[]) {
	int n = parseCmdArgs(argc, argv);

	vector<string> numbers = fillNumbers(n);

	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(begin(numbers), end(numbers), rnd);

	string compNum = numbers.front();

	int moves = 0;
	int dig = 0;
	int pos = 0;

	while(dig != n and pos != n) {
		string userNum = getUserNumber(numbers);
		analyze(compNum, userNum, dig, pos);

		cout << "digits:    " << dig << '\n';
		cout << "positions: " << pos << '\n';
		moves++;
	}

	cout << "You'r winner!!!\n";
	cout << "Your result is " << moves << (moves == 1 ? " move." : " moves.") << '\n';
}











