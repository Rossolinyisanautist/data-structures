#pragma once

#include<stdexcept>
#include<iostream>
#include<cstring>

class String {
	
	const static int short_max = 15;
	int sz;
	char* ptr;

	union {
		int space;
		char ch[short_max + 1];
	};

	void check(int n) const {
		if(n < 0 || n >= sz) {
			throw std::out_of_range("String::at()");
		}
	}

	void copy_from(const String&);
	void move_from(String&);

public:
	String();

	String(const char*);

	String(const String&);

	String(String&&);

	~String() {
		if(short_max < sz) {
			delete[] ptr;
		}
	}

	char& operator[](int n) {
		return ptr[n];
	} 

	char operator[](int n) const {
		return ptr[n];
	}

	char& at(int n) {
		check(n);
		return ptr[n];
	}

	char& at(int n) const {
		check(n);
		return ptr[n];
	}

	char* c_str() {
		return ptr;
	}

	const char* c_str() const {
		return ptr;
	}

	int size() const {
		return sz;
	}

	int capacity() const {
		return sz <= short_max ? short_max : sz + space;
	}

	String& operator+=(char);
	String& operator=(const String&);
	String& operator=(String&&);
};

std::ostream& operator<<(std::ostream&, const String&);

std::istream& operator>>(std::istream&, String&);

char* begin(String&);

const char* begin(const String&);

char* end(String&);

const char* end(const String&);

bool operator==(const String&, const String&);

bool operator!=(const String&, const String&);

String& operator+=(String&, const String&);

String operator+(const String&, const String&);

















