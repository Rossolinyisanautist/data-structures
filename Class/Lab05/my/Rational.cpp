#include<cstdlib>
#include<sstream>

#include "Rational.hpp"

using namespace std;

Rational::Rational(int64_t num, int64_t den)
	: mNum(num), mDen(den) 
{
	if(mDen == 0) {
		throw runtime_error("Rational: denominator equal to zero");
	}

	int64_t a = abs(num);
	int64_t b = abs(den);

	while(b != 0) {
		int64_t r = a % b;
		a = b;
		b = r;
	}
	mNum /= a;
	mDen /= a;

	if(mDen < 0) {
		mNum = -mNum;
		mDen = -mDen;
	}
}

istream& operator>>(istream& inp, Rational& r) {
	int64_t num;
	char ch;
	int64_t den;

	if (!(inp >> num)) // if read attemt failed
	{
		return inp;
	}

	if(inp.eof()) { // if eof the we have only  numerator input
		r = num;
		return inp;
	}

	if(!inp.get(ch)) { // if not eof then there must be '/'
		return inp;
	}

	if(ch != '/') { // accept only '/'
		r = num;
		inp.unget();
		return inp;
	}

	if(!inp.get(ch)) {  // if read attemt failed
		return inp;
	}

	if( !(ch == '+' || ch == '-' || isdigit(ch)) ) {
		inp.setstate(ios_base::failbit);
		return inp;
	}

	inp.unget();

	if(!(inp >> den)) {
		return inp;
	}

	r = Rational(num, den);

	return inp;
}

string Rational::toSchoolForm() const {
	ostringstream sout;

	if(mDen == 1) {
		sout << mNum;
	}
	else if( abs(mNum) < mDen) {
		sout << *this;
	}
	else {
		sout << mNum / mDen << "(" << abs(mNum) % mDen << "/" << mDen << ")";
	}

	return sout.str();
}
















