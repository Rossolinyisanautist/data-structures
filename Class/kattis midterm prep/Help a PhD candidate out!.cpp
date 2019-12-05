#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	while(n--) {
		string s;
		cin >> s;
		if(s == "P=NP") {
			cout << "skipped\n"; 
			continue;
		}
		int i = s.find('+');
		int a = stoi(s.substr(0, i));
		int b = stoi(s.substr(i + 1));
		cout << (a + b) << '\n';

	}
}