#include<iostream>

using namespace std;

int main() {
	char ch;
	while(cin >> noskipws >> ch) {
		switch(ch) {
			case 'A':
			case 'a':
				cout << "@";
				break;
			case 'B':
			case 'b':
				cout << "8";
				break;
			case 'C':
			case 'c':
				cout << "(";
				break;
			case 'D':
			case 'd':
				cout << "|)";
				break;
			case 'E':
			case 'e':
				cout << "3";
				break;
			case 'F':
			case 'f':
				cout << "#";
				break;
			case 'g':
			case 'G':
				cout << "6";
				break;
			case 'h':
			case 'H':
				cout << "[-]";
				break;
			case 'i':
			case 'I':
				cout << "|";
				break;
			case 'j':
			case 'J':
				cout << "_|";
				break;
			case 'k':
			case 'K':
				cout << "|<";
				break;
			case 'l':
			case 'L':
				cout << "1";
				break;
			case 'm':
			case 'M':
				cout << "[]\\/[]";
				break;
			case 'n':
			case 'N':
				cout << "[]\\[]";
				break;
			case 'o':
			case 'O':
				cout << "0";
				break;
			case 'p':
			case 'P':
				cout << "|D";
				break;
			case 'q':
			case 'Q':
				cout << "(,)";
				break;
			case 'r':
			case 'R':
				cout << "|Z";
				break;
			case 's':
			case 'S':
				cout << "$";
				break;
			case 't':
			case 'T':
				cout << "']['";
				break;
			case 'u':
			case 'U':
				cout << "|_|";
				break;
			case 'v':
			case 'V':
				cout << "\\/";
				break;
			case 'w':
			case 'W':
				cout << "\\/\\/";
				break;
			case 'x':
			case 'X':
				cout << "}{";
				break;
			case 'y':
			case 'Y':
				cout << "`/";
				break;
			case 'z':
			case 'Z':
				cout << "2";
				break;
			default:
				cout << ch;
		}
	}
	cout << '\n';
}