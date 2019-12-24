
#include<iostream>
#include<cstring>

#include "stringProject.hpp"

char* expand(const char* ptr, int n) {
	char* p = new char[n];
	strcpy(p, ptr);
	return p;
}

String::String() 
	: sz(0)
	, ptr(ch)
{
	ch[0] = 0;
}

String::String(const char* c) 
	: sz(strlen(c))
	, ptr( sz <= short_max ? ch : new char[sz + 1] )
	, space(0)
{
	strcpy(ptr, c);
}

String::String(const String& s) {
	copy_from(s);
}

String::String(String&& s) {
	move_from(s);
}

String& String::operator=(const String& s) {
	if(this == &s) {
		return *this;
	}
	//strange
	char* p = (short_max < sz) ? ptr : 0;
	copy_from(s);
	delete[] p;
	return *this;
}

String& String::operator=(String&& s) {
	if(this == &s) {
		return *this;
	}
	if(short_max < sz) {
		delete[] ptr;
	}

	move_from(s);
	return *this;
}

String& String::operator+=(char c) {
	if(sz == short_max) {
		int n = sz + sz + 2;
		ptr = expand(ptr, n);
		space = n - sz - 2;
	}
	else if(short_max < sz) {
		if(space == 0) {
			int n = sz + sz + 2;
			char* p = expand(ptr, n);
			delete[] ptr;
			ptr = p;
			space = n - sz - 2;
		}
		else {
			--space;
		}
	}
	ptr[sz] = c;
	ptr[++sz] = 0;
	return *this;
}

void String::copy_from(const String& s) {
	if(s.sz <= short_max) {
		memcpy(this, &s, sizeof(s));
		ptr = ch;
	}
	else {
		ptr = expand(s.ptr, s.sz + 1);
		sz = s.sz;
		space = 0;
	}
}

void String::move_from(String& s) {
	if(s.sz <= short_max) {
		memcpy(this, &s, sizeof(s));
		ptr = ch;
	}
	else {
		ptr = s.ptr;
		sz = s.sz;
		space = s.space;

		s.ptr = s.ch;
		s.sz = 0;
		s.ch[0] = 0;
	}
}

std::ostream& operator<<(std::ostream& out, const String& s) {
	return out << s.c_str();
}

std::istream& operator>>(std::istream& inp, String& s) {
	s = "";
	inp >> std::ws;
	char ch = ' ';

	while(inp.get(ch) && !isspace(ch)) {
		s += ch;
	}
	return inp;
}

bool operator==(const String& a, const String& b) {
	if(a.size() != b.size()) {
		return false;
	}
	// ???????????????????????
	for(int i = 0; i != a.size(); i++) {
		if(a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const String& a, const String& b) {
	return !(a == b);
}

char* begin(String& s) {
	return s.c_str();
}

const char* begin(const String& s) {
	return s.c_str();
}

char* end(String& s) {
	return s.c_str() + s.size();
}

const char* end(const String& s) {
	return s.c_str() + s.size();
}

String& operator+=(String& a, const String& b) {
	for(auto ch : b) {
		a += ch;
	}
	return a;
}

String operator+(const String& a, const String& b) {
	String temp(a);
	temp += b;
	return temp;
}




