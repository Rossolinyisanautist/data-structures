#include<iostream>
#include<sstream>
#include<vector>
#include<random>
#include<chrono>
#include<set>
using namespace std;

vector<string> fillGuesses() {
	vector<string> res;

	for(int i = 1000; i < 9999; i++ ) {
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
		int res;
		if(parseInt(line, res) and a <= res and res <= b) {
			return res;
		}
		cout << "Invalid number.\n";
	}
}

void countDigitsAndPosistions(const string& g, const string& e, int& d, int& p) {
	d = p = 0;

	for(int i = 0; i < g.length(); i++) {
		for(int j = 0; j < e.length(); j++) {
			if(g[i] == e[j]) {
				d++;
				p += j == i;
			}
		}
	}

}

vector<string> filter(const vector<string>& guesses, int d, int p) {
	vector<string> res;

	string g = guesses.front();

	for(const auto& e: guesses) {
		int d2, p2;
		countDigitsAndPosistions(g, e, d2, p2);

		if(d2 == d and p2 == p) {
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
		int d = getAnswer("digits:    ", 0, 4);
		int p = getAnswer("positions: ", 0, d);

		if(d == 4 and p == 4) {
			cout << "AI won.\n";
			break;
		}

		guesses = filter(guesses, d, p);

		if(guesses.empty()) {
			cout << "Cheating.\n";
			break;
		}
	}
}