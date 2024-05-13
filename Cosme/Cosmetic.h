#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
#include<iomanip>

using namespace std;

class Cosmetic {
public:
	Cosmetic(){}
	Cosmetic(int num, int quantity, string name, bool type, double price, string date,bool typeP=0);
	void setName(string name) { this->name = name; }
	void setType(bool type) { this->type = type; }
	void setTypeP(bool typeP) { this->typeP = typeP; }
	void setPrice(double price) { this->price = price; }
	void setNum(int num) { this->num = num; }
	void setQuantity(double quantity) { this->quantity = quantity; }
	void setDate(string date) { this->date = date; }
	void printCos();
	string getName() { return this->name; }
	string getDate() { return this->date; }
	bool getType() { return this->type; }
	bool getTypeP() { return this->typeP; }
	double getPrice() { return this->price; }
	int getNum() { return this->num; }
	int getQuantity() { return this->quantity; }
	
private:
	int num;
	int quantity;
	string date;
	string name;
	bool type;
	bool typeP;
	double price;
protected:
};