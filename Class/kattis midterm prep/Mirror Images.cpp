#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;

	string line, newStr;

	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		
		while(x--) {
			cin >> line;	
			newStr += line + '\n';
		} 
		reverse(newStr.begin(), newStr.end());
		newStr = newStr.substr(1);
		cout << "Test " << i << '\n';
		cout << newStr << '\n';	
		newStr = "";
	}
}