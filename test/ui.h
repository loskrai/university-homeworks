#pragma once
#include"link_node.h"
#include"login.h"


class Menu {
public:

	link_node* phead, ** pphead;

	Menu() :phead(0), pphead(&phead) {}

	~Menu() {
		cout << "class Menu\n";

	}

	Menu operator +(Menu& b) {
		link_node* a = b.phead;
		while (a) {
			phead->add(pphead, a->num, a->name, a->discount, a->price, a->sale);
			a = a->next;
		}
	}
	void read();

	void save() const;


	int static num;

private:

protected:
};


class Order {
public:

	link_node* phead, ** pphead;

	Order() :phead(0), pphead(&phead) {}

	~Order() {

		cout << "class Order\n";

	}

	void read();

	void save() const;

	link_node* roll(const int num)const;

	int static num;

private:

protected:
};



class UI {
public:

	Menu menu;

	Order order;

	~UI() {

		cout << "class UI\n";

	}

	int log() const;

	void userUI();

	void customerUI();

private:

protected:

};



