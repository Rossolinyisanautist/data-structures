#include<iostream>

using namespace std;

int main() {
	string s1, s2, s3;
	int n;
	getline(cin, s3);
	n = stoi(s3);

	while(n--) {
		s3 = "";
		getline(cin, s1);
		getline(cin, s2);

		for (int i = 0; i < s1.length(); ++i) {
			if(s1[i] != s2[i]) {
				s3 += '*';
			}
			else s3 += '.';
		}
		cout << s1 << '\n';
		cout << s2 << '\n';
		cout << s3 << '\n';
	}
}