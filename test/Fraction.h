#pragma once
#include"headfile.h"

class Fraction {
public:
	Fraction() :numerator(0), denominator(0) {};
	Fraction(int numerator, int denominator) :numerator(numerator), denominator(denominator) {
		int a;
		a = measure(numerator, denominator);
		this->denominator /= a;
		this->numerator /= a;
	}
	inline void display() const;
	inline int getDown() const{
		return denominator;
	}
	inline int getUp() const{
		return numerator;
	}
	inline void setDown(int down) {
		denominator = down;
	}
	inline void setUp(int up) {
		numerator = up;
	}
	Fraction operator +(const Fraction& b) const;
	Fraction operator -(const Fraction& b) const;
	Fraction operator *(const Fraction& b) const;
	Fraction operator /(const Fraction& b) const;
	bool operator >(const Fraction& b) const;
private:
	int numerator;
	int denominator;
	int measure(int x, int y);
};