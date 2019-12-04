#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<chrono>
#include<random>
#include<sstream>

const int defaultSize = 4;
const int minSize = 3;
const int maxSize = 6;

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

	vector<int> lowLim = {102, 1023, 10234, 102345 };
	vector<int> upLim = {987, 9876, 98765, 987654 };
	vector<string> res;

	for(int i = lowLim[n - minSize]; i <= upLim[n - maxSize]; i++) {
		string num = to_string(i);
		set<char> s(num.begin(), num.end());
		if(s.size() == num.length()) {
			res.push_back(num);
		}
	}
	return res;

}

string getUserNum(const vector<string>& numbers) {
	while(1) {
		cout << "Your guess: ";
		string line;
		getline(cin, line);
		istringstream sinp(line);
		int t;
		char c;
		if(sinp >> t and !(sinp >> c)) {
			string res = to_string(t);
			if(find(numbers.begin(), numbers.end(), res) != numbers.end()) {
				return res;
			}
		}
		cout << "Invalid number.\n";
	}
}

void analyze(const string& compNum, const string& userNum, int& dig, int& pos) {
	dig = pos = 0;

	for(int i = 0; i < compNum.length(); i++) {
		for(int j = 0; j < userNum.length(); j++) {
			if(compNum[i] == userNum[j]) {
				dig++;
				pos += i == j;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int size = parseCmdArgs(argc, argv);

	vector<string> numbers = fillNumbers(size);

	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(numbers.begin(), numbers.end(), rnd);

	string compNum = numbers.front();
	cout << compNum << '\n';
	int dig = 0, pos = 0, moves = 0;

	while( !(dig == size and pos == size) ) {
		string userNum = getUserNum(numbers);
		analyze(compNum, userNum, dig, pos);		

		cout << "digits:    " << dig << '\n';
		cout << "positions: " << pos << '\n';
 
		moves++;
	}
	cout << "You won.\n";
	cout << "You result is " << moves << (moves == 1 ? " move." : " moves.") << '\n'; 
}









