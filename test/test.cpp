#pragma once
#include"headfile.h"
#include"login.h"
#include"link_node.h"




class Menu{
public:
	link_node* phead, ** pphead;

	Menu() :phead(0), pphead(&phead) {}

	~Menu() {
		cout << "class Menu\n";
	}

	void read();

	void save() const;

private:

protected:
};



class Order {
public:
	link_node* phead, ** pphead;

	Order() :phead(0), pphead(&phead) {}

	~Order() {
		cout << "class Menu\n";
	}

	void read();

	void save() const;

	int static num;

private:
protected:
};

int Order::num = 0;
class Administor {
public:

private:
protected:
};

class Customers {
public:
private:
protected:
};


class UI {
public:
	Menu menu;
	Order order;
	int log();
	int userUI();
	int customerUI();
private:
protected:
};


int main() {
	initializeFile();
	UI ui;
	ui.menu.read();
	int res;
	
	res = ui.log();
	if (res == 1) {
		ui.userUI();
	}
	else {
		ui.customerUI();
	}
}


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
	infile.close();
}

void Menu::save() const{
	string num, name, price, discount;
	ofstream outfile("menu.txt");
	if (!outfile) {
		cout << "No txt";
		exit(0);
	}
	link_node* cur = phead;
	while (cur) {
		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\n";
		cur = cur->next;
	}
	cout << "Null\n";
	outfile.close();
}

void Order::read() {
	string num, name, price, discount,sale;
	ifstream infile("order.txt");
	if (!infile) {
		cout << "No txt";
		exit(0);
	}
	while (!infile.eof()) {
		infile >> num >> name >> price >> discount>>sale;
		phead->add(pphead, num, name, discount, price, sale);
	}
	infile.close();
}

void Order::save() const {
	string num, name, price, discount;
	ofstream outfile("order.txt");
	if (!outfile) {
		cout << "No txt";
		exit(0);
	}
	link_node* cur = phead;
	while (cur) {
		outfile << cur->num << "\t" << cur->name << "\t" << cur->price << "\t" << cur->discount << "\t" << cur->sale << "\n";
		cur = cur->next;
	}
	cout << "Null\n";
	outfile.close();
}

int UI::log() {
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



int UI::userUI() {
	string num, name, discount, price;
	link_node *cur;
	cout << "****************************************\n";
	cout << "*   1.查找订单                         *\n";
	cout << "*   2.修改订单                         *\n";
	cout << "*   3.删除订单                         *\n";
	cout << "*   4.菜品信息增加                     *\n";
	cout << "*   5.菜品信息修改                     *\n";
	cout << "*   6.菜品信息删除                     *\n";
	cout << "*   7.菜品信息查找                     *\n";
	cout << "*   8.销售情况统计                     *\n";
	cout << "*   9.菜单展示                         *\n";
	cout << "*   0.退出                             *\n";
	cout << "****************************************\n";
	int choice = 10;
	cin >> choice;
	while (choice != 0) {
		switch (choice) {
		case 1:cin >> num; cur = order.phead->find(menu.phead, num); cout << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t";
		case 2:;
		case 3:;
		case 4:cin >> num >> name >> discount >> price; menu.phead->add(menu.pphead, num, name, discount, price);
		case 5:cin >> num; cur = menu.phead->find(menu.phead, num); cin >> num >> name >> discount >> price; menu.phead->change(menu.pphead, cur, num, name, discount, price);
		case 6:cin >> num; cur = menu.phead->find(menu.phead, num); menu.phead->del(menu.pphead, cur);
		case 7:cin >> num; cur = menu.phead->find(menu.phead, num); cout << cur->num << "\t" << cur->name << "\t" << cur->discount << "\t" << cur->price << "\t";
		case 8:
		case 9:menu.phead->sortList(menu.pphead); menu.phead->show(menu.phead);
		}
	}
	return choice;
}

int UI::customerUI(){
	menu.phead->show(menu.phead);
	cout << "*****************************************\n";
	cout << "*请输入要点的菜品编号和数量（按下x结束）*\n";
	cout << "*****************************************\n";
	string num, con;
	link_node *cur;
	while (cin >> num, num != "x"){
		cin >> con;
		cur = menu.phead->find(menu.phead, num);
		order.phead->add(order.pphead, cur->num, cur->name, cur->discount, cur->price, con);
		Order::num++;
	}
}
