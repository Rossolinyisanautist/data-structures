#pragma once

#include<cstdint>
#include<iostream>
#include<string>
#include<stdexcept>

class Rational final {

	std::int64_t mNum;
	std::int64_t mDen;

public:
	Rational(std::int64_t num = 0) 
        : mNum(num)
        , mDen(1)
	{	}

	Rational(std::int64_t num, std::int64_t den);

	int64_t num() const {
		return mNum;
	}
	int64_t den() const {
		return mDen;
	}
	double toDouble() {
		return double(mNum) / mDen;
	}

	std::string toSchoolForm() const;
};

inline std::ostream& operator<<(std::ostream& out, const Rational& r) {
	return out << r.num() << "/" << r.den();
}
std::iostream& operator>>(std::istream& inp, const Rational& r);

inline Rational operator+(const Rational& r1, const Rational& r2) {
	return Rational(r1.num() * r2.den() + r2.num() * r1.den(),
					r1.den() * r2.den());
}

inline Rational operator-(const Rational& r1, const Rational& r2) {
	return Rational(r1.num() * r2.den() - r2.num() * r1.den(),
					r1.den() * r2.den());
}

inline Rational operator*(const Rational& r1, const Rational& r2) {
	return Rational(r1.num() * r2.num(), r1.den() * r2.den());
}

inline Rational operator/(const Rational& r1, const Rational& r2) {
	if(r2.num() == 0) {
		throw std::runtime_error("Rational: division by zero");
	}
	return Rational(r1.num() * r2.den(), r1.den() * r2.num());
}

inline Rational operator-(const Rational& r1) {
	return Rational(-r1.num(), r1.den());
}

inline Rational operator+(const Rational& r1) {
	return r1;
}

inline bool operator==(const Rational& r1, const Rational& r2) {
	return r1.num() == r2.num() && r1.den() == r2.den();
}

inline bool operator!=(const Rational& r1, const Rational& r2) {
	return !(r1 == r2);
}

inline bool operator>(const Rational& r1, const Rational& r2) {
	return r1.num() * r2.den() > r1.den() * r2.num();
}

inline bool operator<(const Rational& r1, const Rational& r2) {
	return r2 > r1;
}

inline bool operator>=(const Rational& r1, const Rational& r2) {
	return !(r1 < r2);
}

inline bool operator<=(const Rational& r1, const Rational& r2) {
	return !(r1 > r2);
}
























