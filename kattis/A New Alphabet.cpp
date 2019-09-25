#include<iostream>
#include<map>

using namespace std; 

int main() {
	map<char, string> map;
    map['A'] = "@";
    map['B'] = "8";
    map['C'] = "(";
    map['D'] = "|)";
    map['E'] = "3";
    map['F'] = "#";
    map['G'] = "6";
    map['H'] = "[-]";
    map['I'] = "|";
    map['J'] = "_|";
    map['K'] = "|<";
    map['L'] = "1";
    map['M'] = "[]\\/[]";
    map['N'] = "[]\\[]";
    map['O'] = "0";
    map['P'] = "|D";
    map['Q'] = "(,)";
    map['R'] = "|Z";
    map['S'] = "$";
    map['T'] = "']['";
    map['U'] = "|_|";
    map['V'] = "\\/";
    map['W'] = "\\/\\/";
    map['X'] = "}{";
    map['Y'] = "`/";
    map['Z'] = "2";

    string inputString;
    getline(cin, inputString);

    cout << inputString.length();

    for (int i = 0; i < inputString.length(); ++i) {
    	char c = inputString.at(i);

    	if('a' <= c && c <= 'z') {
    		cout << map[(char)toupper(c)];
    	}
    	else if ('A' <= c && c <= 'Z') {
    		cout << map[c];
    	}
    	else {
    		cout << c;
    	}
    }
    cout << endl;
}