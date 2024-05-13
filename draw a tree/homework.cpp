//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//class Point {
//public:
//	Point(double tx = 0, double ty = 0) :x(tx), y(ty) {};
//	~Point() {};
//	void setX(double tx) {
//		x = tx;
//	}
//	void setY(double ty) {
//		y = ty;
//	}
//	double getX() {
//		return x;
//	}
//	double getY() {
//		return y;
//	}
//private:
//	double x, y;
//};
//
//class Circle {
//	friend class Point;
//public:
//	Circle() {}
//	Circle(double a, double b, double c) :r(c), center(a, b) {}
//	void setX(double x) {
//		center.setX(x);
//	}
//	void setY(double y) {
//		center.setY(y);
//	}
//	void setR(double r1) {
//		r = r1;
//	}
//	double getX() {
//		return center.getX();
//	}
//	double getY() {
//		return center.getY();
//	}
//	double getR() {
//		return r;
//	}
//private:
//	Point center;
//	double r = 0;
//};
//
//double distanceOfCircleCenter(Circle& c1, Circle& c2) {
//	return (sqrt(pow(c1.getX() - c2.getX(), 2) + pow(c1.getY() - c2.getY(), 2)));
//}
//
//int circleRelationShip(Circle c1, Circle c2) {
//	double dis = distanceOfCircleCenter(c1, c2);
//	double r1 = c1.getR();
//	double r2 = c2.getR();
//	double sor = r1 + r2;
//	double gap = abs(r1 - r2);
//	if (c1.getX() == c2.getX() && c1.getY() == c2.getY()) {
//		return 4;
//	}
//	if (dis == gap) {
//		return 1;
//	}
//	else if (dis < sor && dis > gap) {
//		return 0;
//	}
//	else if (dis < gap) {
//		return 3;
//	}
//	else if (sor == dis) {
//		return 2;
//	}
//	else if (dis > sor) {
//		return 5;
//	}
//}
//
//int main() {
//	//freopen("in.txt", "r", stdin);
//	string situ[] = { "相交","内切","外切","包含","同心圆","相离" };
//	Circle r1;
//	Circle r2;
//	double x = 0, y = 0, r = 0;
//	while (1) {
//		cout << "请输入第一个圆的坐标(x,y)和半径。\n";
//		cin >> x >> y >> r;
//		r1.setX(x);
//		r1.setY(y);
//		r1.setR(r);
//		cout << "请输入第二个圆的坐标(x,y)和半径。\n";
//		cin >> x >> y >> r;
//		r2.setX(x);
//		r2.setY(y);
//		r2.setR(r);
//		int ret = 0;
//		ret = circleRelationShip(r1, r2);
//		cout << "位置关系为：" << situ[ret] << "\n";
//	}
//}