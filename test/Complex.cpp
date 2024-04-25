#include"Complex.h"

Complex Complex::operator +(const Complex& that)const {
	Complex temp;
	temp.real = real + that.real;
	temp.imag = imag + that.imag;
	return temp;
}

Complex operator -(const Complex& a, const Complex& b) {
	Complex temp;
	temp.setImag(a.getImag() - b.getImag());
	temp.setReal(a.getReal() - b.getReal());
	return temp;
}

Complex operator *(const Complex& a, const Complex& b) {
	Complex temp;
	temp.real = a.real * b.real - a.imag * b.imag;
	temp.imag = a.imag * b.real + a.real * b.imag;
	return temp;
}
Complex Complex::operator /(const Complex& that)const {
	Complex temp;
	temp.real = (real * that.real + imag * that.imag) / (pow(that.real, 2) + pow(that.imag, 2));
	temp.imag = (imag * that.real - real * that.imag) / (pow(that.real, 2) + pow(that.imag, 2));
	return temp;
}