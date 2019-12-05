#include<iostream>

using namespace std;

int main() {
	int lineCount = 0;
	string line;
	while(getline(cin, line)) {
		lineCount++;

		int start = -1;
		for (int i = 0; i < line.length(); ++i) {
			if(line[i] == '"' and start == -1) {
				start = i;
			}
			else if(line[i] == '"' and start != -1) {
				cout << lineCount << ": " << line.substr(start, i - start + 1) << '\n';
				start = -1;
			}
		}
	}
}