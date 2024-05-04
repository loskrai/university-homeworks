#pragma once
#include"headfile.h"
class Point;
class Rectangle;

class point {
public:
	point(int x , int y ) {
		X = x;
		Y = y;
	}
	void move(int offX, int offY) {
		X += offX;
		Y += offY;
	}
	int getX() {
		return X;
	}
	int getY() {
		return Y;
	}
private:
	int X;
	int Y;
protected:
};

class rectangle: public point{
public:
	rectangle(int x, int y, int length, int width) :point(x, y), length(length), width(width) {}
	int getLength() {
		return length;
	}
	int getwidth() {
		return width;
	}
	int getArea() {
		return length*width;
	}
private:
	int length;
	int width;
protected:
};