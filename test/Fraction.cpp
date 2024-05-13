#include"Fraction.h"

inline void Fraction::display() const {
	if (denominator == 0 || numerator == 0) {
		cout << 0 << "\n";
	}
	else if (denominator == numerator) {
		cout << 1 << "\n";
	}
	else if (denominator == -numerator) {
		cout << -1 << "\n";
	}
	else {
		cout << numerator << "/" << denominator << "\t" << (numerator * 1.0 / denominator) << "\n";
	}
}

Fraction Fraction::operator +(const Fraction& b) const {
	int up = numerator * b.denominator + b.numerator * denominator;
	int down = b.denominator * denominator;
	Fraction plus(up, down);
	return plus;
}

Fraction Fraction::operator -(const Fraction& b) const {
	int up = numerator * b.denominator - b.numerator * denominator;
	int down = b.denominator * denominator;
	Fraction plus(up, down);
	return plus;
}

Fraction Fraction::operator *(const Fraction& b) const {
	int up = numerator * b.numerator;
	int down = b.denominator * denominator;
	Fraction plus(up, down);
	return plus;
}

Fraction Fraction::operator /(const Fraction& b) const {
	int up = numerator * b.denominator;
	int down = b.numerator * denominator;
	Fraction plus(up, down);
	return plus;
}

bool Fraction::operator >(const Fraction& b) const {
	int up1 = numerator * b.denominator;
	int up2 = b.numerator * denominator;
	if (up1 > up2) {
		return true;
	}
	else {
		return false;
	}
}

int Fraction::measure(int x, int y)
{
	if (x < 0) {
		x = -x;
	}
	if (y < 0) {
		y = -y;
	}
	int z = y;
	while (x % y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}