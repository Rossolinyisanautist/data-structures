#include<iostream>

using namespace std;

int main() {
	string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
	int n;
	while(true) {
		string str, temp;
		cin >> n;
		if(n == 0) break;
		cin >> str;

		for(int i = str.length() - 1; i >= 0; i--) {
			char c = str.at(i);
			int index = (c == '.') ? 
							index = c - 19 : (c == '_') ? 
								index = c - 69 : index = c - 'A';
			
			temp += alpha.at( (index + n) % alpha.length() );
		}
		cout << temp << '\n';

	}

}