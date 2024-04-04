//#include<iostream>
//
//using namespace std;
//
//class Point {
//public:
//	Point(int xx = 0, int yy = 0, int zz = 0) :x(xx), y(yy), z(zz) {
//		++count;
//	}
//	static void display(Point &point) {
//		cout << "点坐标是：(" << point.x << "," << point.y << "," << point.z << ")\n";
//		cout << "创建的点数：" << count << "\n";
//	}
//private:
//	int x;
//	int y;
//	int z;
//	static int count;
//};
//
//int Point::count = 0;
//
//int main() {
//	Point p1(1, 2, 3), p2(10, 20, 30);
//	Point::display(p1);
//	Point::display(p2);
//	return 0;
//}
//
//
//
//
//#include<iostream>
//
//using namespace std;
//
//class Point {
//public:
//	Point(int xx = 0, int yy = 0, int zz = 0) :x(xx), y(yy), z(zz) {}
//	void move(int xOff, int yOff, int zOff) {
//		x += xOff;
//		y += yOff;
//		z += zOff;
//	}
//	void display() const{
//		cout << "点坐标是：(" << x << "," << y << "," << z << ")\n";
//	}
//
//private:
//	int x;
//	int y;
//	int z;
//};
//
//
//int main() {
//	Point p1(1, 2, 3);
//	Point p2(10, 20, 30);
//	p1.move(5, 6, 7);
//	p1.display();
//	p2.move(50, 60, 70);
//	p2.display();
//	return 0;
//}
//
//
//#include<iostream>
//
//using namespace std;
//
//class SavingAccount {
//public:
//	void setSB(double sb) {
//		savingsBalance = sb;
//	}
//	void display() {
//		cout << savingsBalance << endl;
//	}
//	void calculateMonthlyInterest() {
//		savingsBalance += savingsBalance * annualInterestRate / 12;
//	}
//	static void  modifyInterestRate(double aI) {
//		annualInterestRate = aI;
//	}
//private:
//	static double annualInterestRate;
//	double savingsBalance;
//};
//
//double SavingAccount::annualInterestRate = 0;
//int main() {
//	SavingAccount saver1, saver2;
//	saver1.setSB(2000);
//	saver2.setSB(3000);
//	saver1.modifyInterestRate(0.03);
//	saver1.calculateMonthlyInterest();
//	saver2.calculateMonthlyInterest();
//	saver1.display();
//	saver2.display();
//	saver1.modifyInterestRate(0.04);
//	saver1.calculateMonthlyInterest();
//	saver2.calculateMonthlyInterest();
//	saver1.display();
//	saver2.display();
//}