#include<iostream>
#include<ctime>
#include<sstream>
#include<vector>

using namespace std;

int defaultSize = 4;
int minSize = 3;
int maxSize = 6;

int parseCmdLineArgs(int argc, char* argv[]);
vector<int> fillNumbers(int n);

int main(int argc, char* argv[]) {
	srand(time(0));

	int n = parseCmdLineArgs(argc, argv);
}

int parseCmdLineArgs(int argc, char* argv[]) {
	int result = 4;

	if(argc == 2) {
		int t = 0;
		istringstream sinp(argv[1]);

		if(sinp >> t >> ws && sinp.eof()) {
			result = abs(t);
			result = (minSize <= result && result <= maxSize) ? result : defaultSize;
		}
	}
	return result;
}

vector<int> fillNumbers(int n) {
	vector<int> lowerLim = { 102, 1023, 10234, 102345 }
	vector<int> upperLim = { 987, 9876, 98765, 987654 }

	vector<string> result;

	for(int i = lowerLim[n - minSize]; i <= upperLim[n - minSize]; i++) {
		string t = to_string(i);
		set<char> s(t.begin(), t.end());
		if(s.size() == n) {
			res.push_back(t);
		}
	}

}











