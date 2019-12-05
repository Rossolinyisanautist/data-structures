#include<iostream>
#include<string>
using namespace std;

int main () {
	int n;
	string str;

	getline(cin, str);
	n = stoi(str);

	while(n--) {

		getline(cin, str);
		
		if(str.find("Simon says") != string::npos) {
			cout << str.substr(11) << '\n';	
		}
	}
}