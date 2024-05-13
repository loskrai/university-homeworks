#include"CosmeticManager.h"
#define FILENAME "Cosmetic.txt"

struct node {
	string name;
	int num = 0;
	node* next;
};

node* head = nullptr;

time_t gettm(const string& date) {
	tm time = {};
	istringstream tim(date);
	tim >> get_time(&time, "%Y/%m/%d");
	time_t t = mktime(&time);
	return t;
}

CosmeticManager::CosmeticManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::out);
	if(!ifs.is_open()){
		ofstream ifj(FILENAME);
	}
	string h1, h2, h3, h4, h5, h6, h7;
	ifs >> h1;
	ifs >> h2;
	ifs >> h3;
	ifs >> h4;
	ifs >> h5;
	ifs >> h6;
	ifs >> h7;
	string name;
	double price;
	bool type;
	string date;
	int number;
	int quantity;
	bool typeP;
	int num = 0;
	while (ifs >> number && ifs >> name && ifs >> price && ifs >> type && ifs >> quantity&& ifs >>typeP  && ifs >> date) {
		num++;
	}
	ifs.close();
	ifs.open(FILENAME, ios::out);
	cosNum = num;
	cosptr = new Cosmetic[num];
	int i = 0;
	ifs >> h1;
	ifs >> h2;
	ifs >> h3;
	ifs >> h4;
	ifs >> h5;
	ifs >> h6;
	ifs >> h7;
	while (ifs >> number && ifs >> name && ifs >> price && ifs >> type && ifs >> quantity&& ifs >> typeP && ifs >> date) {
		cosptr[i].setName(name);
		cosptr[i].setPrice(price);
		cosptr[i].setType(type);
		cosptr[i].setDate(date);
		cosptr[i].setTypeP(typeP);
		cosptr[i].setNum(number);
		cosptr[i].setQuantity(quantity);
		i++;
	}
	ifs.close();
}

CosmeticManager::~CosmeticManager() {
	delete[] cosptr;
	cosptr = nullptr;
}

void CosmeticManager::Purchasegoods(int num) {
	if ((num - int(num) != 0 || num <= 0)) {
		cout << "进货量不能为非正数或小数！" << endl;
		exitsystem();
	}
	int sumnum = num + cosNum;
	Cosmetic* temp = new Cosmetic[sumnum];
	int i = 0;
	if (cosNum > 0) {
		for (i = 0; i < cosNum; i++) {
			temp[i].setName(cosptr[i].getName());
			temp[i].setPrice(cosptr[i].getPrice());
			temp[i].setType(cosptr[i].getType());
			temp[i].setTypeP(cosptr[i].getTypeP());
			temp[i].setDate(cosptr[i].getDate());
			temp[i].setNum(cosptr[i].getNum());
			temp[i].setQuantity(cosptr[i].getQuantity());
		}
	}
	for (int j = 1; i < sumnum; j++, i++) {
		cout << "请输入第" << j << "个货源的品牌：";
		string name;
		cin >> name;
		cout << "请输入第" << j << "个货源的单价：";
		double price;
		cin >> price;
		cout << "请输入第" << j << "个货源是否为国产，是为1否为0";
		bool type;
		cin >> type;
		cout << "请输入第" << j << "个货源是否为进货，是为1否为0";
		bool typeP;
		cin >> typeP;
		cout << "请输入第" << j << "个货源的数量：";
		int quantity;
		cin >> quantity;
		SYSTEMTIME time;
		GetLocalTime(&time);
		string ntime;
		ntime = to_string(time.wYear) + "/" + to_string(time.wMonth) + "/" + to_string(time.wDay);
		temp[i] = Cosmetic(cosNum + j, quantity, name, type, price, ntime, typeP);
	}
	delete[] this->cosptr;
	this->cosptr = temp;
	cosNum = sumnum;
	save();
	cout << "操作成功";
	system("cls");
	showMenu();
}

void CosmeticManager::printCosmetic() {
	cout << "编号\t品牌\t单价\t类型\t数量\t日期\n";
	for (int i = 0; i < this->cosNum; i++) {
		cosptr[i].printCos();
	}
}

void CosmeticManager::SortCosmeticManager() {
	Cosmetic* temp = new Cosmetic[cosNum];
	for (int i = 0; i < cosNum; i++) {
		temp[i].setName(cosptr[i].getName());
		temp[i].setPrice(cosptr[i].getPrice());
		temp[i].setType(cosptr[i].getType());
		temp[i].setTypeP(cosptr[i].getTypeP());
		temp[i].setDate(cosptr[i].getDate());
		temp[i].setNum(cosptr[i].getNum());
		temp[i].setQuantity(cosptr[i].getQuantity());
	}
	for (int i = 0; i < cosNum; i++) {
		for (int j = 0; j < cosNum - i - 1; j++) {
			if(cosptr[j].getPrice() > cosptr[j + 1].getPrice()) {
				Cosmetic temp = cosptr[j];
				cosptr[j] = cosptr[j + 1];
				cosptr[j + 1] = temp;
			}
		}
	}
	printCosmetic();
	delete[] cosptr;
	cosptr = temp;
	system("pause");
}

void CosmeticManager::TyproCosmrticManager(bool type) {
	cout << "编号\t品牌\t单价\t类型\t数量\t日期\n";
	for (int i = 0; i < cosNum; i++) {
		if (cosptr[i].getType() == type) {
			cosptr[i].printCos();
		}
	}
	system("pause");
}

void CosmeticManager::save() {
	ofstream ofs;
	ofs.open("Cosmetic.txt");
	ofs << "编号\t品牌\t单价\t类型\t数量\t操作\t日期\n";
	for (int i = 0; i < cosNum; i++) {
		ofs << cosptr[i].getNum() << "\t" << cosptr[i].getName() << "\t" << cosptr[i].getPrice() << "\t" << cosptr[i].getType() << "\t" << cosptr[i].getQuantity() << "\t" << cosptr[i].getTypeP() << "\t" << cosptr[i].getDate() << endl;
	}
	ofs.close();
}

void CosmeticManager::delCosmetic(string name) {
	for (int i = 0; i < cosNum; i++) {
		if (cosptr[i].getName() == name) {
			cosptr[i].printCos();
			cout << endl;
			cout << "是否删除？" << endl;
			cout << "1、是" << endl;
			cout << "2、否" << endl;
			int a;
			cin >> a;
			if (a == 1) {
				for (int j = i; j < cosNum - 1; j++) {
					this->cosptr[j] = cosptr[j + 1];
				}
				cosNum--;
				cout << "删除成功";
				system("pause");
				save();
				break;
			}
			if (i == cosNum - 1) {
				cout << "无此化妆品！" << endl;
				system("pause");
			}
		}
	}
}

void CosmeticManager::modifyCosmetic(string name) {
	int i;
	for (i = 0; i < cosNum; i++) {
		if (cosptr[i].getName() == name) {
			cout << "请输入修改后化妆品的品牌：";
			string cname;
			cin >> cname;
			cout << "请输入修改后化妆品的单价：";
			double price;
			cin >> price;
			cout << "是否为国产？(是 1 否 0 )";
			bool type;
			cin >> type;
			cout << "是否为进货？(是 1 否 0 )";
			bool typeP;
			cin >> typeP;
			cout << "请输入修改后化妆品的数量：";
			int quantity;
			cin >> quantity;
			SYSTEMTIME time;
			GetLocalTime(&time);
			string ntime;
			ntime = to_string(time.wYear) + "/" + to_string(time.wMonth) + "/" + to_string(time.wDay);
			cosptr[i] = Cosmetic(i, quantity, cname, type, price, ntime,typeP);
			break;
		}
	}
	if (i == cosNum) {
		cout << "查不到该化妆品！" << endl;
	}
	system("pause");
	save();
}

void CosmeticManager::printByPriceCondition(int price) {
	for (int i = 0; i < cosNum; i++) {
		if (cosptr[i].getPrice() >= price) {
			cosptr[i].printCos();
		}
	}
	system("pause");
}

void CosmeticManager::printByName(string name) {
	int count = 0;
	int i;
	for (i = 0; i < cosNum; i++) {
		if (cosptr[i].getName() == name) {
			cosptr[i].printCos();
			count++;
		}
	}
	if (count == 0) {
		cout<<"没有找到该化妆品！"<<endl;
	}
	system("pause");
}

void CosmeticManager::showRepertory(const string& date) {
	bool flag = 0;
	node* p = nullptr;
	while (head) {
		p = head;
		head = head->next;
		delete p;
		p = nullptr;
	}
	for (int i = 0; i < cosNum; i++) {
		flag = 0;
		if (gettm(cosptr[i].getDate()) <= gettm(date)) {
			if (head == nullptr) {
				head = new node;
				head->name = cosptr[i].getName();
				if (cosptr[i].getTypeP()) {
					head->num += cosptr[i].getQuantity();
				}
				else {
					head->num -= cosptr[i].getQuantity();
				}
				head->next = nullptr;
			}
			else {
				node* p2 = head;
				while (p2 != nullptr) {
					if (p2->name == cosptr[i].getName()) {
						flag = 1;
						if (cosptr[i].getTypeP()) {
							p2->num += cosptr[i].getQuantity();
						}
						else {
							p2->num -= cosptr[i].getQuantity();
						}
					}
					p2 = p2->next;
				}
				if (flag) { continue; }
				p2 = head;
				while (p2->next != nullptr) {
					if (p2->name == cosptr[i].getName()) {
						flag = 1;
						if (cosptr[i].getTypeP()) {
							p2->num += cosptr[i].getQuantity();
						}
						else {
							p2->num -= cosptr[i].getQuantity();
						}
					}
					p2 = p2->next;
				}
				p2->next = new node;
				p2->next->name = cosptr[i].getName();
				if (cosptr[i].getTypeP()) {
					p2->next->num += cosptr[i].getQuantity();
				}
				else {
					p2->next->num -= cosptr[i].getQuantity();
				}
				p2->next->next = nullptr;
			}
		}
	}
	cout << "品牌\t库存\n";
	node* p1 = head;
	while (p1) {
		cout << p1->name << "\t" << p1->num << "\n";
		p1 = p1->next;
	}
	system("pause");
}

void CosmeticManager::showMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|     欢迎来到化妆品管理系统            |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     1、添加                           |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     2、显示化妆品                     |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     3、修改                           |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     4、删除                           |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     0、退出系统                       |" << endl;
	cout << "|                                       |" << endl;
	cout << "-----------------------------------------" << endl;
}

void CosmeticManager::showSonMenu() {
	cout << "-----------------------------------------" << endl;
	cout << "|                                       |" << endl;
	cout << "|     1、按单价降序显示所有化妆品       |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     2、按类型显示化妆品               |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     3、显示所有化妆品                 |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     4、显示单价比输入单价高的化妆品   |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     5、按品牌显示化妆品               |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     6、显示库存                       |" << endl;
	cout << "|                                       |" << endl;
	cout << "|     0、返回上一层                     |" << endl;
	cout << "-----------------------------------------" << endl;
}


void CosmeticManager::exitsystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}


