#include"UI.h"



void Menu::read() {

	string num, name, price, discount;

	ifstream infile("menu.txt");

	if (!infile) {

		cout << "No txt";

		exit(0);

	}

	while (!infile.eof()) {

		infile >> num >> name >> price >> discount;

		phead->add(pphead, num, name, discount, price);

	}

	Menu::num = atoi(num.c_str()) + 1;

	infile.close();

}



void Menu::save() const {

	string num, name, price, discount;

	ofstream outfile("menu.txt");

	if (!outfile) {

		cout << "No txt";

		exit(0);

	}

	link_node* cur = phead;

	while (cur->next) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\n";

		cur = cur->next;

	}

	if (cur) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount;

	}

	cout << "Null\n";

	outfile.close();

}



void Order::read() {

	string num, name, price, discount, sale;

	ifstream infile("order.txt");

	if (!infile) {

		cout << "No txt";

		exit(0);

	}

	while (!infile.eof()) {

		infile >> num >> name >> price >> discount >> sale;

		phead->add(pphead, num, name, discount, price, sale);

	}

	Order::num = atoi(num.c_str()) + 1;

	infile.close();

}



void Order::save() const {

	ofstream outfile("order.txt");

	if (!outfile) {

		cout << "No txt";

		exit(0);

	}

	link_node* cur = phead;

	while (cur->next) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->sale << "\n";

		cur = cur->next;

	}if (cur) {

		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->sale;

	}

	cout << "Null\n";

	outfile.close();

}







link_node* Order::roll(const int num) const {

	link_node* cur = phead;

	for (int i = 1; i < num; ++i) {

		cur = cur->next;

	}

	return cur;

}



int UI::log() const {

	cout << endl;

	cout << "****************************************\n";

	cout << "*请选择序号确定身份                    *\n";

	cout << "*   1.管理员                           *\n";

	cout << "*   2.顾客                             *\n";

	cout << "****************************************\n";

	int choice = 0, res = 0;

	cin >> choice;

	while (choice != 1 && choice != 2) {

		cout << "请重新输入";

		cin >> choice;

	}

	if (choice == 1) {

		if (login()) {

			res = 1;

		}

	}

	else {

		res = 2;

	}

	return res;

}







void UI::userUI() {

	string num, name, discount, price, sale;

	link_node* cur;

	cout << "****************************************\n";

	cout << "*   1.查找订单                         *\n";

	cout << "*   2.修改订单                         *\n";

	cout << "*   3.删除订单                         *\n";

	cout << "*   4.菜品信息增加                     *\n";

	cout << "*   5.菜品信息修改                     *\n";

	cout << "*   6.菜品信息删除                     *\n";

	cout << "*   7.菜品信息查找                     *\n";

	cout << "*   8.销售情况统计(没要求做，未完成)   *\n";

	cout << "*   9.菜单展示                         *\n";

	cout << "*   0.退出                             *\n";

	cout << "****************************************\n";

	int choice = 10;

	int t;

	char a[25];

	while (choice != 0) {

		cur = 0;

		cout << "请输入选择：";

		cin >> choice;

		switch (choice) {

		case 1:cout << "请输入编号："; cin >> t; cur = order.roll(t); cout << num << "\t" << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t" << cur->sale << "\n"; break;

		case 2:cout << "请输入编号："; cin >> t; cur = order.roll(t);  _itoa(t, a, 10); cout << "请输入修改信息（名字，折扣，价钱, 数量）\n "; cin >> name >> discount >> price >> sale; order.phead->change(order.pphead, cur, a, name, discount, price, sale); break;

		case 3:cout << "请输入编号："; cin >> t; cur = order.roll(t); if (cur) { order.phead->del(order.pphead, cur); } cout << "删除完成！\n"; break;

		case 4:_itoa(Menu::num, a, 10); Menu::num++; cout << "请输入增加信息（名字，折扣，价钱）\n "; cin >> name >> discount >> price; menu.phead->add(menu.pphead, a, name, discount, price); break;

		case 5:cout << "请输入编号："; cin >> num; cur = menu.phead->find(menu.phead, num); cout << "请输入修改信息（名字，折扣，价钱）\n "; cin >> name >> discount >> price; menu.phead->change(menu.pphead, cur, num, name, discount, price); break;

		case 6:cout << "请输入编号："; cin >> num; cur = menu.phead->find(menu.phead, num); if (cur) { menu.phead->del(menu.pphead, cur); } cout << "删除完成！\n"; break;

		case 7:cout << "请输入编号："; cin >> num; cur = menu.phead->find(menu.phead, num); cout << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t"; break;

		case 8:break;

		case 9:menu.phead->show(menu.phead); break;

		}

	}

}



void UI::customerUI() {

	menu.phead->show(menu.phead);

	cout << "*****************************************\n";

	cout << "*请输入要点的菜品编号和数量（按下x结束）*\n";

	cout << "*****************************************\n";

	string num, con;

	link_node* cur;

	while (cin >> num, num != "x") {

		cin >> con;

		cur = menu.phead->find(menu.phead, num);

		char a[25];

		_itoa(Order::num, a, 10);

		order.phead->add(order.pphead, a, cur->name, cur->discount, cur->price, con);

		Order::num++;

	}

}

