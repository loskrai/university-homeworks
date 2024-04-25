#pragma once
#include"headfile.h"

class Complex;

class Complex {
public:
	Complex(double real = 0, double imag = 0) :real(real), imag(imag) {};
	double getReal() const{
		return real;
	}
	double getImag() const{
		return imag;
	}
	void setReal(double a) {
		real = a;
	}
	void setImag(double a) {
		imag = a;
	}
	void showComplex() {
		if (real != 0) {
			if (imag > 0) {
				cout << real << "+" << imag << "i" << endl;
			}else if(imag==0){
				cout << real << endl;
			}
			else {
				cout << real << imag << "i" << endl;
			}
		}
		else {
			if (imag == 0) {
				cout << 0 << endl;
			}
			else {
				cout << imag << "i" << endl;
			}
		}
	}
	Complex operator +(const Complex& that) const;
	friend Complex operator *(const Complex& a, const Complex& b);
	Complex operator /(const Complex& that) const;
private:
	double real;
	double imag;
protected:
};

Complex operator -(const Complex& a, const Complex& b);