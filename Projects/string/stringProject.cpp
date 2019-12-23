#include <cstring>
#include <iostream>

#include "stringProject.hpp"

char* expand(const char* ptr, int n) { // expand into free store 
	char* p = new char[n];
	strcpy(p, ptr); // §43.4
	return p;
}

String::String() // default constructor : x{""}
	: sz{0}
	, ptr{ch} // ptr points to elements, ch is an initial location (§19.3.3)
{
	ch[0] = 0; // terminating 0
}

String::String(const char* p)
	: sz(strlen(p))
	, ptr( (sz <= short_max) ? ch : new char[sz + 1] )
	, space(0)
{
	strcpy(ptr,p); // copy characters into ptr from p
}

String::String(const String& x) { // copy constr uctor 
	copy_from(x); // copy representation from x
}

String::String(String&& x) { // move constr uctor 
	move_from(x);
}

String& String::operator=(const String& x) {
	if (this == &x) return *this; // deal with self-assignment
	char* p = (short_max < sz) ? ptr : 0;
	copy_from(x);
	delete[] p;
	return *this;
}

String& String::operator=(String&& x) {
	if (this == &x) return *this; // deal with self-assignment (x = move(x) is insanity)
	if (short_max < sz) delete[] ptr; // delete target

	move_from(x); // does not throw
	return *this;
}

String& String::operator+=(char c) {
	if(sz == short_max) { // expand to long string
		int n = sz + sz + 2; // double the allocation (+2 because of the terminating 0)
		ptr = expand(ptr, n);
		space = n - sz - 2;
	}
	else if(short_max < sz) {
		if(space == 0) { // expand in free store
			int n = sz + sz + 2; // double the allocation (+2 because of the terminating 0)
			char* p = expand(ptr, n);
			delete[] ptr;
			ptr = p;
			space = n - sz - 2; 
		} 
		else {
			--space;
		}
	}
	ptr[sz] = c; // add c at end
	ptr[++sz] = 0; // increase size and set terminator
	return *this;
}



void String::copy_from(const String& x) { // make *this a copy of x
	if (x.sz <= short_max) { // copy *this
		memcpy(this, &x, sizeof(x)); // §43.5
		ptr = ch;
	}
	else { // copy the elements
		ptr = expand(x.ptr, x.sz + 1);
		sz = x.sz;
		space = 0;
	}
}

void String::move_from(String& x) {
	if (x.sz <= short_max) { // copy *this
		memcpy(this, &x, sizeof(x)); // §43.5
		ptr = ch;
	}
	else { // grab the elements
		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		x.ptr = x.ch; // x = ""
		x.sz = 0;
		x.ch[0] = 0;
	}
}


std::ostream& operator<<(std::ostream& os, const String& s) {
	return os << s.c_str(); // §36.3.3
}

std::istream& operator>>(std::istream& is, String& s) {
	s = ""; // clear the target string
	is >> std::ws; // skip whitespace (§38.4.5.1)
	char ch = ' ';
	while(is.get(ch) && !isspace(ch))
		s += ch;
	return is;
}

bool operator==(const String& a, const String& b) {
	if (a.size() != b.size())
		return false;
	for (int i = 0; i != a.size(); ++i)
		if (a[i] != b[i])
			return false;
	return true;
}
bool operator!=(const String& a, const String& b) {
	return !(a == b);
}

char* begin(String& x) { // C-string-style access 
	return x.c_str();
}

const char* begin(const String& x) {
	return x.c_str();
}

char* end(String& x) {
	return x.c_str() + x.size();
}

const char* end(const String& x) {
	return x.c_str() + x.size();
}


String& operator+=(String& a, const String& b) { // concatenation 
	for (auto x : b) 
		a += x;
	return a;
}

String operator+(const String& a, const String& b) { // concatenation 
	String res {a};
	res += b;
	return res;
}


