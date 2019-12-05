#include<iostream>
#include<string>
using namespace std;

int main() {

	string zero = " ",
	two = "abc",
	three = "def",
	four = "ghi",
	five = "jkl",
	six = "mno",
	seven = "pqrs",
	eight = "tuv",
	nine = "wxyz";

	int n, k = 1;
	string temp;
	getline(cin, temp);
	n = stoi(temp);

	while(k <= n) {
		string s, output = "";
		getline(cin, s);
		string prev = "!";

		for(int j = 0; j < s.length(); j++) {
			char c = s[j];
			int len = output.length();

			if(two.find(c) != string::npos) {
				if(prev == two) { output += ' '; len++; }
				output.insert(len, two.find(c) + 1, '2');
				prev = two;
			}
			else if(three.find(c) != string::npos) {
				if(prev == three) { output += ' '; len++; }
				output.insert(len, three.find(c) + 1, '3');
				prev = three;
			}
			else if(four.find(c) != string::npos) {
				if(prev == four) { output += ' '; len++; }
				output.insert(len, four.find(c) + 1, '4');
				prev = four;
			}
			else if(five.find(c) != string::npos) {
				if(prev == five) { output += ' '; len++; }
				output.insert(len, five.find(c) + 1, '5');
				prev = five;
			}
			else if(six.find(c) != string::npos) {
				if(prev == six) { output += ' '; len++; }
				output.insert(len, six.find(c) + 1, '6');
				prev = six;
			}
			else if(seven.find(c) != string::npos) {
				if(prev == seven) { output += ' '; len++; }
				output.insert(len, seven.find(c) + 1, '7');
				prev = seven;
			}
			else if(eight.find(c) != string::npos) {
				if(prev == eight) { output += ' '; len++; }
				output.insert(len, eight.find(c) + 1, '8');				
				prev = eight;
			}
			else if(nine.find(c) != string::npos) {
				if(prev == nine) { output += ' '; len++; }
				output.insert(len, nine.find(c) + 1, '9');
				prev = nine;
			}
			else if(c == ' '){
				if(prev == " ") {
					output += ' ';
				}
				output += '0';
				prev = " ";
			}
		}
		cout << "Case #" << k << ": " << output << '\n';
		k++;
	}
}