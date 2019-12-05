#include<iostream>

using namespace std;

string encode(const string& str) ;
string decode(const string& str) ;

int main() {
	char action;
	cin >> action;
	string msg;
	cin >> msg;

	if(action == 'E') {
		cout << encode(msg) << '\n';
	}
	else {
		cout << decode(msg) << '\n';
	}
}

string encode(const string& str) {
	string res;

	char currCh = str[0];
	int count = 1;
	for (int i = 1; i < str.length(); ++i) {
		char ch = str[i];
		if(ch != currCh) {
			res += currCh + to_string(count);
			currCh = ch;
			count = 0;
		}
		count++;
	}
	res += str.back() + to_string(count);
	return res;
}
string decode(const string& str) {
	string res = "";
	for (int i = 0; i < str.length() - 1; i += 2) {
		int times = str[i + 1] - '0';
		char ch = str[i];
		res.insert(res.length(), times, ch);
	}
	return res;	
}




