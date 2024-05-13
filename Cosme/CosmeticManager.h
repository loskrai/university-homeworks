#pragma once
#include"Cosmetic.h"
#include<fstream>
#include<Windows.h>

class CosmeticManager {
public:
	CosmeticManager();
	~CosmeticManager();
	void Purchasegoods(int num);
	void printCosmetic();
	void SortCosmeticManager();
	void TyproCosmrticManager(bool type);
	void save();
	void modifyCosmetic(string name);
	void delCosmetic(string name);
	void printByPriceCondition(int price);
	void printByName(string name);
	void showMenu();
	void showSonMenu();
	void showRepertory(const string& date);
	void exitsystem();
private:
	Cosmetic* cosptr;
	int cosNum;
protected:
};