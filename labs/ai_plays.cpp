#include<iostream>
#include<set>
#include<vector>
#include<sstream>

using namespace std;


vector<string> fillNumbers() {
	vector<string> v;
	for(int i = 1000; i < 9999; i++) {
		string number = to_string(i);
		set<char> s(number.begin(), number.end());
		if(s.size() == number.length()) {
			v.push_back(number);
		}
	}
	return v;
}



void countDigitsAndPositions(const string& g, const string& e, int& digit, int& positios) {
	digit = 0;
	positios = 0;

	for(int i = 0; i < 4; i++ ) {
		for(int j = 0; j < 4; j++) {
			if(g[i] == e[j]) {
				digit++;
				positios += j == i;
			}
		}
	}
}

vector<string> filter(const vector<string>& v, int digits, int positios) {
	vector<string> res;

	string g = v.front();
	for(const auto& s: v) {
		int d, p;
		countDigitsAndPositions(g, s, d, p);
		if(d == digits && p == positios) {
			res.push_back(s);
		}
	}
	return res;
}

bool parseInt(const string& s, int& n) {
	istringstream sinp(s);
	return sinp >> n >> ws and sinp.eof();
}

int getAnswer(const string& msg, int a, int b) {
	while(true) {
		cout << msg;
		string line;
		getline(cin, line);
		int r;
		if(parseInt(line, r) and r <= b and r >= a) {
			return r;
		}
		else {
			cout << "incorrect input" << '\n';
		}
	}
}


int main() {
	vector<string> guesses = fillNumbers();

	while(true) {
		cout << "My guess: " << guesses.front() << '\n';
		int digits = getAnswer("correct digits: ", 0, 4);
		int positions = getAnswer("correct position: ", 0, digits);

		if(digits == 4 and positions == 4) {
			cout << "AI won\n";
			break;
		}
		guesses = filter(guesses, digits, positions);

		if(guesses.empty()) {
			cout << "Cheating\n";
			break;
		}

	}
}



