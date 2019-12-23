#pragma once

#include <cstring>
#include <iostream>
#include <stdexcept>


class String {

public:
	String(); // default constructor : x{""}

	String(const char* p); // constructor from C-style string: x{"Euler"}

	String(const String&); // copy constructor

	String(String&& x); // move constr uctor

 	~String() { 
 		if (short_max < sz) {
 			delete[] ptr; 	
 		}
 	} // destructor

 	char& operator[](int n) {
 		return ptr[n]; 
 	} // unchecked element access

	char operator[](int n) const { 
		return ptr[n]; 
	}

	char& at(int n) {
		check(n); 
		return ptr[n]; 
	} // range-checked element access

	char at(int n) const { 
		check(n); 
		return ptr[n]; 
	}

	char* c_str() { 
		return ptr; 
	} // C-style string access

	const char* c_str() const { 
		return ptr; 
	}

	int size() const { 
		return sz; 
	} // number of elements

	int capacity() const { // elements plus available space 
		return (sz <= short_max) ? short_max : sz + space; 
	}

	String& operator+=(char c); // add c at end
	String& operator=(String&& x); // move assignment
	String& operator=(const String&);

private:

	static const int short_max = 15;
	int sz; // number of characters
	char* ptr;

	union {
		int space; // unused allocated space
		char ch[short_max + 1]; // leave space for terminating 0
	};

	void check(int n) const { // range check 
		if (n < 0 || sz <= n) {
			throw std::out_of_range("String::at()");
		}
	} // ancillary member functions:

	void copy_from(const String& x);
	void move_from(String& x);
};


std::ostream& operator<<(std::ostream& os, const String& s);

std::istream& operator>>(std::istream& is, String& s);

bool operator==(const String& a, const String& b);

bool operator!=(const String& a, const String& b);

char* begin(String& x);

const char* begin(const String& x);

char* end(String& x);

const char* end(const String& x);

String& operator+=(String& a, const String& b);

String operator+(const String& a, const String& b);








