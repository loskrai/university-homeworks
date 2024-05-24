#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>

using namespace std;

class Shape {
public:
	virtual void area() = 0;
	virtual void draw() = 0;
private:
protected:
};

class Triangle:public Shape {
	void area() final override {
		cout << "调用三角形获取面积函数\n";
	}
	void draw() final override {
		cout << "调用三角形绘制函数\n";
	}
};

class Rectangle :public Shape {
	void area() final override {
		cout << "调用矩形获取面积函数\n";
	}
	void draw() final override {
		cout << "调用矩形绘制函数\n";
	}
};

class Circle :public Shape {
	void area() final override {
		cout << "调用圆获取面积函数\n";
	}
	void draw() final override {
		cout << "调用圆绘制函数\n";
	}
};
int main() {
	time_t begin, end;
	begin = clock();
	
	Shape* p = nullptr;
	Triangle a;
	Circle b;
	Rectangle c;
	p = &a;
	p->area();
	p->draw();
	p = &b;
	p->area();
	p->draw();
	p = &c;
	p->area();
	p->draw();


	end = clock();
	cout << "\n run time:" << double(end - begin) / CLOCKS_PER_SEC;
}
