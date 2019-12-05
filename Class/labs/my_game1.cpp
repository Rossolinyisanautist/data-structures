#include<ctime>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<iostream>
#include<sstream>

using namespace std;

vector<string> fillGuesses();
vector<string> filter(const vector<string>& guesses, int digits, int positions);
bool parseInt(const string& str, int& num);
void countBullsAndCows(const string& currGuess, const string& otherGuess, int& digits, int& positions);
int getAnswer(const string& message, int lowLim, int upLim);


int main() {
	srand(time(0));

	vector<string> guesses = fillGuesses();
	
	while(true) {
		cout << "My guess is " << guesses.front() << '\n';

		int digits = getAnswer("Correct digits: ", 0, 4);
		int positions = getAnswer("Correct positions: ", 0, digits);

		if(digits == 4 && positions == 4) {
			cout << "Number is found.\n";
			break;
		}

		guesses = filter(guesses, digits, positions);

		if(guesses.empty()) {
			cout << "You are cheating!\n";
			break;
		}
	}
}

vector<string> fillGuesses() {
	vector<string> result;
	for (int i = 1000; i < 9999; ++i) {
		string guess = to_string(i);
		set<char> guessTest(begin(guess), end(guess));
		if(guessTest.size() == 4) {
			result.push_back(guess);
		}
	}
	return result;
}

int getAnswer(const string& message, int lowLim, int upLim) {
	while(true) {
		cout << message;
		string line;
		getline(cin, line);

		int num;
		if(!parseInt(line, num) && lowLim <= num && num <= upLim) {
			return num;
		}
		cout << "Invalid input. Input may contain digits and whitespaces only\n";
	}
}

bool parseInt(const string& str, int& num) {
	istringstream input(str);
	return input >> num >> ws && input.eof();
}

vector<string> filter(const vector<string>& guesses, int digits, int positions) {
	vector<string> result;

	string currGuess = guesses.front();

	for(const auto& guess: guesses) {
		int digits_1, positions_1;
		countBullsAndCows(currGuess, guess, digits_1, positions_1);
		if(digits == digits_1 && positions == positions_1) {
			result.push_back(guess);
		}
	}
	return result;
}

void countBullsAndCows(const string& currGuess, const string& otherGuess, int& digits, int& positions) {
	digits = 0;
	positions = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(currGuess[i] == otherGuess[j]) {
				digits++;
				positions += i == j;
			}
		}
	}
}










