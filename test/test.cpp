#include"UI.h"
#include"Fraction.h"


int Order::num = 0;

int Menu::num = 0;

class X {
	int a;
public:
	X() :b(&a) {};
	int* b;
};

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

	Fraction a(1, 3);
	Fraction b(1, 4);
	cout << (a > b);

	return 0;

}