#include <iostream>
#include <sstream>
#include <string>

#include "Rational.hpp"

using namespace std;
bool parseExpr(const string& line, Rational& r1, char& oper, Rational& r2);
void computeAndShow(const Rational& r1, char& oper, const Rational& r2);
void showResult(const Rational& r);

int main() {
	cout << boolalpha;

	string line;
	while(getline(cin, line)) {
		try {
			Rational r1;
			char op;
			Rational r2;

			if( !parseExpr(line, r1, op, r2) ) {
				cout << "Incorrect expression: " << line << endl;
			}
			else {
				computeAndShow(r1, op, r2);
			}
		}
		catch (runtime_error& e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}

bool parseExpr(const string& line, Rational& r1, char& op, Rational& r2) {
	const string operations = "+-*:<>=#";

	istringstream sinp(line);
	if( !(sinp >> r1) ) {
		return false;
	}
	if( !(sinp >> op) || operations.find(op) == string::npos ) {
		return false;
	}
	
	char c;
	if( !(sinp >> r2 || sinp >> c) ) {
		return false;
	}

	return true;
}

void computeAndShow(const Rational& r1, char op, const Rational& r2) {
	switch(op) {
		case '+':
			showResult(r1 + r2);
			break;
		case '-':
			showResult(r1 - r2);
			break;
		case '*':
			showResult(r1 * r2);
			break;
		case ':':
			showResult(r1 / r2);
			break;
		case '=':
			cout << (r1 == r2) << endl;
			break;
		case '#':
			cout << (r1 != r2) << endl;
			break;
		case '>':
			cout << (r1 > r2) << endl;
			break;
		case '<':
			cout << (r1 < r2) << endl;
			break;
	}
}

void showResult(const Rational& r) {
	cout << "Result: " << r << "\nSchool form: " << r.toSchoolForm() << '\n'; 
}





