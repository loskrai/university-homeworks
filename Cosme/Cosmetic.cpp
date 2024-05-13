#include"Cosmetic.h"

Cosmetic::Cosmetic(int num,int quantity,string name, bool type, double price,string date,bool typeP):typeP(typeP),date(date),quantity(quantity),num(num),name(name),type(type),price(price) {}

void Cosmetic::printCos() {
	cout << this->num << "\t" << this->name << "\t" << this->price << "\t" << (this->type ? "国产" : "进口") << this->quantity << "\t" << (this->typeP ? "进货" : "销售") << "\t" << this->date << endl;
}