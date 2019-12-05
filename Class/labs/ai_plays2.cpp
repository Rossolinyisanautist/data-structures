#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<chrono>
#include<random>

using namespace std;

vector<string> fillGuesses();
int getAnswer(const string& msg, int a, int b);
void count(const string& g, const string& e, int& d, int& p);
vector<string> filter(const vector<string>& nums, int d, int p);
bool parseInt(const string& str, int& num);


int main() {

	vector<string> nums = fillGuesses();


	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(nums.begin(), nums.end(), rnd);

	while(1) {
		cout << "My guess: " << nums.front() << '\n';
		int d = getAnswer("digits:   ", 0, 4);
		int p = getAnswer("poitions: ", 0, d);

		if(p == 4 and d == 4) {
			cout << "AI won.";
			break;
		}
		nums = filter(nums, d, p);

		if(nums.empty()) {
			cout << "Cheating!\n";
			break;
		}

	}
}

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

int getAnswer(const string& msg, int a, int b) {
	while(1) {
		cout << msg;
		string line;
		getline(cin, line);
		int res;
		if(parseInt(line, res) and a <= res and res <= b) {
			return res;
		}
		else {
			cout << "invalid number\n";
		}
	}
}

bool parseInt(const string& str, int& num) {
	istringstream sinp(str);
	char c;
	return sinp >> num and !(sinp >> c);
}

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








