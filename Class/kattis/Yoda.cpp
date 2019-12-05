#include<iostream>

using namespace std;


void padTo(std::string &str, const size_t num, const char paddingChar = ' ') {
    if(num > str.size())
        str.insert(0, num - str.size(), paddingChar);
}

int main() {
	string a, b, newA = "", newB = "";

	cin >> a;
	cin >> b;

	int length = (a.length() > b.length()) 
						? (a.length())
						: (b.length());

	a.insert(0, length - a.length(), '0');
	b.insert(0, length - b.length(), '0');
	// padTo(a, length, '0');
	// padTo(b, length, '0');

	for (int i = 0; i < length; ++i) {
		int digitA, digitB;

		digitA = a[i] - '0';
		digitB = b[i] - '0';

		if (digitA > digitB) {
			newA += to_string(digitA);
		}
		else if (digitB > digitA){
			newB += to_string(digitB);
		}
		else {
			newA += to_string(digitA);
			newB += to_string(digitB);
		}
	}
	if (newA == "") {
		newA = "YODA";
	}
	else {
		newA = to_string(stoi(newA));
	}
	if (newB == "") {
		newB = "YODA";
	}
	else {
		newB = to_string(stoi(newB));
	}
	cout << newA << endl << newB << endl;
}






