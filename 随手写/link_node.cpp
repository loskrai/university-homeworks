//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<ctime>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//#include<fstream>
////#define _REDF_
//using namespace std;
//class StudentList {
//public:
//	int num = 0;
//	string name;
//	static int count;
//	StudentList* pri = NULL;
//	StudentList* next = NULL;
//	StudentList* appSpace();
//	StudentList* find(StudentList *phead, int num);
//	void add(StudentList** pphead, int num, string name);
//	void del(StudentList** pphead, StudentList* pos);
//	void change(StudentList** pphead, StudentList* pos, int num, string name);
//	void insert(StudentList **pphead,StudentList *pos, int num, string name);
//	void show(StudentList *phead);
//	void sortList(StudentList** pphead);
//
//	void destory(StudentList** pphead);
//};
//
//
//int StudentList::count = 0;
//
//
//int main() {
//#ifdef _REDF_
//	freopen("in.txt", "r", stdin);
//#endif
//	time_t beg = clock();
//	
//	ifstream infile("in.txt");
//	if (!infile) {
//		cout << "No txt";
//		exit(0);
//	}
//	
//	StudentList *temp;
//	StudentList* phead=NULL;
//	StudentList** pphead = &phead;
//	string name;
//	int num;
//
//
//	while (!infile.eof()) {
//		infile >> num >> name;
//		phead->add(pphead, num, name);
//	}
//	infile.close();
//	
//	cout << "加载完成！\n";
//
//	
//	cout << "*****************************************" << "\n";
//	cout << "1.增加到链表尾                2.删除\n" <<
//		    "3.修改(按学号)                4.查询(按学号)\n" <<
//		    "5.指定位置插入(指定学号后)    6.显示链表\n" <<
//		    "7.排序                        8.退出\n";
//	cout << "*****************************************" << "\n";
//	int choice=0;
//	
//	while (choice!=8) {
//		cin >> choice;
//		switch (choice) {
//		case 1:cin >> num >> name; phead->add(pphead, num, name); phead->show(phead); break;
//		case 2:cin >> num; temp = phead->find(phead, num); phead->del(pphead, temp); phead->show(phead); break;
//		case 3:cin >> num; temp = phead->find(phead, num); cin >> num >> name; phead->change(pphead, temp, num, name); phead->show(phead); break;
//		case 4:cin >> num; temp = phead->find(phead, num); cout << temp->num << "\t" << temp->name << "\n"; break;
//		case 5:cin >> num; temp = phead->find(phead, num); cin >> num >> name; phead->insert(pphead, temp, num, name); phead->show(phead); break;
//		case 6:phead->show(phead); break;
//		case 7:phead->sortList(pphead); phead->show(phead); break;
//		}
//	}
//
//	phead->destory(pphead);
//	time_t end = clock();
//	cout << "\nRun time: " << static_cast<double>(end - beg) / CLOCKS_PER_SEC << "s" << endl;
//
//	return 0;
//}
//
//StudentList* StudentList::appSpace() {
//	StudentList* newNode = new StudentList;
//	if (newNode == NULL) {
//		perror("Fail to apply new space");
//		exit(0);
//	}
//	return newNode;
//}
//
//void StudentList::add(StudentList** pphead, int num, string name) {
//	StudentList* newNode = appSpace();
//	if ((*pphead) == NULL) {
//		(*pphead) = newNode;
//		(*pphead)->name = name;
//		(*pphead)->num = num;
//		++count;
//	}
//	else {
//		StudentList* cur = *pphead;
//		while (cur->next) {
//			cur = cur->next;
//		}
//		cur->next = newNode;
//		cur->next->pri = cur->next;
//		cur->next->num = num;
//		cur->next->name = name;
//		++count;
//	}
//}
//
//void StudentList::del(StudentList **pphead,StudentList *pos) {
//	if (pos == *pphead) {
//		*pphead = (*pphead)->next;
//		(*pphead)->pri = 0;
//		delete pos;
//		pos = NULL;
//		--count;
//	}
//	else {
//		pos->pri->next = pos->next;
//		pos->next->pri = pos->pri;
//		delete pos;
//		pos = NULL;
//		--count;
//	}
//}
//
//void StudentList::change(StudentList** pphead, StudentList* pos, int num, string name) {
//	pos->name = name;
//	pos->num = num;
//}
//
//void StudentList::insert(StudentList** pphead, StudentList* pos, int num, string name) {
//	StudentList* newNode = appSpace();
//	StudentList* next = pos->next;
//	pos->next = newNode;
//	newNode->num = num;
//	newNode->name = name;
//	newNode->pri = pos;
//	newNode->next = next;
//	next->pri = newNode;
//	++count;
//}
//
//StudentList* StudentList::find(StudentList* phead, int num) {
//	while (phead) {
//		if (phead->num == num) {
//			return phead;
//		}
//		phead = phead->next;
//	}
//	return NULL;
//}
//
//void StudentList::show(StudentList *phead) {
//	StudentList* cur = phead;
//	int icount = 1;
//	while (cur) {
//		cout << icount << "\t" << cur->num << "\t" << cur->name << "\n";
//		cur = cur->next;
//		++icount;
//	}
//	cout << "Null\n";
//}
//
//void StudentList::sortList(StudentList** pphead) {
//	if ((*pphead) == NULL) {
//		perror("No list");
//		return;
//	}
//	StudentList* temp = (*pphead);
//	StudentList* start = temp;
//	//StudentList* next;*/
//	bool flag = 0;
//	for (int i = 0; i < count-1;++i) {
//		for (int j = 0; j < count-1-i;++j) {
//			if (temp->num > temp->next->num) {
//				int a;
//				string b;
//				a = temp->next->num;
//				temp->next->num = temp->num;
//				temp->num = a;
//				b = temp->next->name;
//				temp->next->name = temp->name;
//				temp->name = b;
//			}
//		}
//		temp = temp->next;
//		start = temp->next;
//	}
//}
//
//void StudentList::destory(StudentList** pphead) {
//	while (*pphead) {
//		count = 0;
//		StudentList* next = (*pphead)->next;
//		delete* pphead;
//		*pphead = next;
//	}
//}