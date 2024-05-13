#include"UI.h"
#include"Fraction.h"
#include"Point.h"
#include"Student.h"
#include"Package.h"
#include"Windows.h"
#include<sstream>
#include<string>
#include<ctime>
#include<iomanip>

int Order::num = 0;

int Menu::num = 0;

time_t gettm(const string& date) {
	tm time = {};
	istringstream tim(date);
	tim >> get_time(&time, "%Y/%m/%d %H:%M:%S");
	time_t t = mktime(&time);
	return t;
}

int main() {

	/*UI ui;

	ui.menu.read();

	ui.order.read();

	int res;

	res = ui.log();

	if (res == 1) {

		ui.userUI();

	}

	else {

		ui.customerUI();

	}



	ui.menu.save();

	ui.order.save();*/
	//rectangle a(1, 2, 3, 4);
	//a.move(10, -5);
	//cout << "(" << a.getX() << "," << a.getY() << ")" << "\n" << "width:" << a.getwidth() << "\n" << "length:" << a.getLength() << "\n" << "area:" << a.getArea() << "\n";
	//
	//Pupil b("张三", 20, 'M', "XXXXXXXXXXXXX", "南工", "大一", "计2301", 30, 100, 100, 100);
	//b.printIfo();
	//cout << "\n";

	//Package a1("11", "11", "12", "12", "12", 12, 12, 21);
	//TwoDayPackage a2("11", "11", "12", "12", "12", 12, 12, 21, 1);
	//OvernightPackage a3("11", "11", "12", "12", "12", 12, 12, 21, 1);
	//cout << a1.calculate_Cost() << "\n";
	//cout << a2.calculate_Cost() << "\n";
	//cout << a3.calculate_Cost() << "\n";

	string a = "2020/10/11 12:22:55";
	string b = "2023/1/30 15:55:59";
	time_t a1 = gettm(a);
	time_t a2 = gettm(b);
	cout << (a1 < a2);

	return 0;

}
