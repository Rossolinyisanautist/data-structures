#include<sstream>
#include<iostream>

using namespace std;

int main() {
	string line1;


	while(getline(cin, line1)) {
		if(line1.empty()) {
			cout << line1 << '\n';
			continue;
		}
		istringstream inp(line1);
		string name;
		inp >> name;
		int sum = 0;
		int point;
		while(inp >> point) {
			sum += point;
		}
		cout << name << ": " << sum << '\n';
	}
}