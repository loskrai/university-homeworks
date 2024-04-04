#include<iostream>

using namespace std;

class Rational {
public:
	Rational() :numerator(0), denominator(0) {};
	Rational(int numerator,int denominator):numerator(numerator), denominator(denominator){
		int a;
		a = measure(numerator, denominator);
		this->denominator /= a;
		this->numerator /= a;
	}
	void display(){
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
			cout << numerator << "/" << denominator<<"\t"<< (numerator *1.0/ denominator) << "\n";
		}
	}
	int getDown() {
		return denominator;
	}
	int getUp() {
		return numerator;
	}
	void setDown(int down) {
		denominator = down;
	}
	void setUp(int up) {
		numerator = up;
	}
	Rational operator +(const Rational &b) {
		int up = numerator * b.denominator + b.numerator * denominator;
		int down = b.denominator * denominator;
		Rational plus(up, down);
		return plus;
	}
	Rational operator -(const Rational& b) {
		int up = numerator * b.denominator - b.numerator * denominator;
		int down = b.denominator * denominator;
		Rational plus(up, down);
		return plus;
	}
	Rational operator *(const Rational& b) {
		int up = numerator * b.numerator;
		int down = b.denominator * denominator;
		Rational plus(up, down);
		return plus;
	}
	Rational operator /(const Rational& b) {
		int up = numerator * b.denominator;
		int down = b.numerator * denominator;
		Rational plus(up, down);
		return plus;
	}
private:
	int numerator;
	int denominator;
	int measure(int x, int y)
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
};


//int main() {
//	int down, up;
//	while (cin >> up >> down) {
//		Rational a(up, down);
//		cin >> up >> down;
//		Rational b(up, down);
//		Rational temp;
//		temp = a + b;
//		temp.display();
//		temp = a - b;
//		temp.display();
//		temp = a * b;
//		temp.display();
//		temp = a / b;
//		temp.display();
//	}
//}