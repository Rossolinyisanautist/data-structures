#include <iostream>

using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	while(n--) {
		string str;
		cin >> str;
		if(str.find("CD") == string::npos) {
			count++;
		}
	}
	cout << count << '\n';
}