//#include<iostream>
//
//using namespace std;
//
//class Point {
//	friend double distance(const Point& p1, const Point& p2);
//public:
//	Point() :x(0), y(0) {}
//	Point(int xx, int yy) :x(xx), y(yy) {}
//	Point(const Point &a){
//		x = a.x;
//		y = a.y;
//	}
//	~Point() {
//		x = y = 0;
//	}
//	double getX(){
//		return x;
//	}
//	double getY() {
//		return y;
//	}
//	void setX(double x=0) {
//		this->x = x;
//	}
//	void setY(double y=0) {
//		this->y = y;
//	}
//	void display(Point &point) {
//		cout << "点坐标是：(" << point.x << "," << point.y << ")\n";
//	}
//	void display(const Point& point)const {
//		cout << "(常量)点坐标是：(" << point.x << "," << point.y << ")\n";
//	}
//	double distance(const Point& p2) {
//		return sqrt(pow((x - p2.x), 2) + pow((y - p2.y), 2));
//	}
//private:
//	double x;
//	double y;
//};
//
//double distance(const Point& p1, const Point& p2) {
//	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
//}
//
//int main() {
//	Point a;
//	a.setX(1);
//	a.setY(1);
//	Point b(0, 0);
//	cout << a.distance(b) << "\n";
//	cout << distance(a, b) << "\n";
//}


#include<iostream>
#include<vector>

using namespace std;

class IntegerSet {
public:
	IntegerSet():list(100,0){}
	IntegerSet(int *p,int cache):list(100,0){
		for (int i = 0; i < cache; ++i) {
			list[*(p + i)] = 1;
		}
	}
	IntegerSet unionOfSets(const IntegerSet& s2);
	IntegerSet intersectionOfSets(const IntegerSet& s2);
	void insertElement(int a);
	void printSet();
	bool isEqualTo(const IntegerSet& s2);
private:
	vector<bool> list;
};

IntegerSet IntegerSet::unionOfSets(const IntegerSet& s2) {
	IntegerSet temp;
	for (int i = 0; i < 100; ++i) {
		if (list[i] || s2.list[i]) {
			temp.list[i] = 1;
		}
		else {
			temp.list[i] = 0;
		}
	}
	return temp;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& s2) {
	IntegerSet temp;
	for (int i = 0; i < 100; ++i) {
		if (list[i] && s2.list[i]) {
			temp.list[i] = 1;
		}
		else {
			temp.list[i] = 0;
		}
	}
	return temp;
}

void IntegerSet::insertElement(int a) {
	list[a] = 1;
}

void IntegerSet::printSet() {
	bool a = false;
	for (int i = 0; i < 100; ++i) {
		if (list[i]) {
			cout << i << " ";
			a = true;
		}
	}
	if(!a){
		cout << "---\n";
	}
	else {
		cout << "\n";
	}
}

bool IntegerSet::isEqualTo(const IntegerSet &s2) {
	for (int i = 0; i < 100; ++i) {
		if (list[i] != s2.list[i]) {
			return false;
			break;
		}
	}
	return true;
}

int main() {
	int node[10] = { 1,2,3,4,5,6,7,8,9,10 };
	IntegerSet a;
	IntegerSet b(node, 10);
	a.printSet();
	b.printSet();
	a.insertElement(5);
	a.printSet();
	cout << a.isEqualTo(b) << "\n";
	a.insertElement(6);
	IntegerSet temp;
	temp = a.intersectionOfSets(b);
	temp.printSet();
	temp = a.unionOfSets(b);
	temp.printSet();
}