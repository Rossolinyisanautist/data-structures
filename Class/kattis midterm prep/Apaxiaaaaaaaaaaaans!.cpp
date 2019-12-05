#include<iostream>
#include<string>

using namespace std;

int main() {
	string res;
	char c;

	while(cin >> c) {
		if(res.back() != c) {
			res += c;
		}
	}
	cout << res << '\n';
}