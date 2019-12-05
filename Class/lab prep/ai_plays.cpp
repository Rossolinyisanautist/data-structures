#include<iostream>
#include<set>
#include<vector>
#include<sstream>
#include<chrono>
#include<random>

using namespace std;

vector<string> fillGuesses() {
	vector<string> res;

	for(int i = 1000; i < 9999; i++) {
		string num = to_string(i);
		set<char> s(num.begin(), num.end());
		if(s.size() == num.length()) {
			res.push_back(num);
		}
	}
	return res;
}

bool parseInt(const string& str, int& num) {
	istringstream sinp(str);
	char c;
	return sinp >> num and !(sinp >> c);
}

int getAnswer(const string& msg, int a, int b) {
	while(1) {
		cout << msg;
		string line;
		getline(cin, line);
		int r;
		if(parseInt(line, r) and a <= r and r <= b) {
			return r;
		}
		cout << "invalid number.\n";
	}
}

// void count(const string& g, const string& e, int& dig, int& pos) {
// 	dig = pos = 0;

// 	for(int i = 0; i < g.length(); i++) {
// 		for(int j = 0; j < e.length(); j++) {
// 			if(g[i] == e[j]) {
// 				dig++;
// 				pos += i == j;
// 			}
// 		}
// 	}
// }

void count(const string& g, const string& e, int& d, int& p) {
	d = p = 0;

	for (int i = 0; i < g.length(); ++i) {
		for(int j = 0; j < e.length(); ++j) {
			if(g[i] == e[j]) {
				d++;
				p += i == j;
			}
		}
	}
}


// vector<string> filter(const vector<string>& guesses, int dig, int pos) {
// 	vector<string> res;

// 	string g = guesses.front();

// 	for(const string& e : guesses) {
// 		int dig2, pos2;
// 		count(g, e, dig2, pos2);

// 		if(dig2 == dig and pos2 == pos) {
// 			res.push_back(e);
// 		}
// 	}
// 	return res;
// }

vector<string> filter(const vector<string>& nums, int d, int p) {
	vector<string> res;

	string g = nums.front();

	for(const auto& e : nums) {
		int d2, p2;
		count(g, e, d2, p2);
		if(d == d2 and p == p2) {
			res.push_back(e);
		}
	}
	return res;
}

int main() {
	vector<string> guesses = fillGuesses();

	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(guesses.begin(), guesses.end(), rnd);

	while(1) {
		cout << "My guess: " << guesses.front() << '\n';
		int digits = getAnswer("digits:    ", 0, 4);
		int positions = getAnswer("positions: ", 0, digits);

		if(digits == 4 and positions == 4) {
			cout << "AI won.\n";
			break;
		}

		guesses = filter(guesses, digits, positions);

		if(guesses.empty()) {
			cout << "Cheating!\n";
			break;
		}
	}
}

