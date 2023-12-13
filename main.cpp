#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#define SIZE 100 //最大容量
using namespace std;


//系统类（主要处理函数）
class System {
public:
	int menu()
	{
		string choice;
		cout << setw(29) << setfill(' ') << "工资管理系统" << endl;
		cout << setw(25) << setfill('*') << "菜单" << setw(25) << setfill('*') << "*" << endl;
		cout << "1.录入工资（批量）        2.删除工资记录" << setw(50) << setfill(' ') << " " << endl;
		cout << "3.查询工资记录            4.修改工资记录" << setw(50) << setfill(' ') << " " << endl;
		cout << "5.插入工资（单条）        6.统计分析" << setw(50) << setfill(' ') << " " << endl;
		cout << "7.工资记录排序            8.调整工资" << setw(50) << setfill(' ') << " " << endl;
		cout << "9.显示工资记录            0.退出管理系统" << setw(50) << setfill(' ') << " " << endl;
		cout << setw(50) << setfill('*') << "*" << endl;
		cout << setw(29) << setfill('*') << "请选择0~9：" << setw(22) << setfill('*') << " " << endl;
		cin >> choice;
		if (choice == "0" || choice == "退出管理系统" || choice == "退出" || choice == "退出系统" || choice == "退出管理") {
			return 0;
		}
		else if (choice == "1" || choice == "录入工资（批量）" || choice == "批量录入工资" || choice == "批量录入") {
			return 1;
		}
		else if (choice == "2" || choice == "删除工资记录" || choice == "删除工资" || choice == "删除记录") {
			return 2;
		}
		else if (choice == "3" || choice == "查询工资记录" || choice == "查询工资" || choice == "查询记录") {
			return 3;
		}
		else if (choice == "4" || choice == "修改工资记录" || choice == "修改工资" || choice == "修改记录") {
			return 4;
		}
		else if (choice == "5" || choice == "插入工资" || choice == "插入工资（单条）" || choice == "插入单条工资" || choice == "插入单条") {
			return 5;
		}
		else if (choice == "6" || choice == "统计分析" || choice == "分析" || choice == "统计") {
			return 6;
		}
		else if (choice == "7" || choice == "工资记录排序" || choice == "排序" || choice == "记录排序") {
			return 7;
		}
		else if (choice == "8" || choice == "调整工资" || choice == "调整") {
			return 8;
		}
		else if (choice == "9" || choice == "显示工资记录" || choice == "显示记录" || choice == "显示工资") {
			return 9;
		}
		else {
			cout << "请重新输入：";
			cin >> choice;
		}
	}
};

//职工工资类
class Salary {
	friend class System;
	friend  int biSearchNum(Salary arr[], string key);
public:
	static int m_count;
	string m_name;//basic
	string m_title;//basic
	string m_num;//basic
	int m_workage;//basic
	double m_dSalary[15];//工资详细
	double m_dTax;//扣税8~14
	double m_StartSalary;//应发工资0~7
	double m_LastSalary;//实发工资0~14

	Salary() {
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0; m_LastSalary = 0; m_dTax = 0; memset(m_dSalary, 0, sizeof(m_dSalary));
	}

	//------------------------------------
	void m_In_Basic_Ifo() {
		cout << "请输入职工的四项身份信息（工号 姓名 职称 工龄）：\n";
		cin >> m_num >> m_name >> m_title >> m_workage;
		checkPosition(&m_title);
		checkNum(&m_num);
		++m_count;
	}
	void m_Show_Basic_Ifo() {
		cout << m_num << "\t" << m_name << "\t" << m_title << "\t" << m_workage << "\t";
	}

	void m_In_dSalary() {
		cout << "请输入职工的15项工资明细：\n";
		for (int g = 0; g < 15; g++) {
			cin >> m_dSalary[g];
		}
	}
	void m_Show_dSalary() {
		for (int g = 0; g < 15; g++) {
			cout << m_dSalary[g] << "\t";
		}
	}

	void m_Get_LastSalary() {
		m_LastSalary = 0;
		for (int g = 0; g < 15; g++) {
			m_LastSalary += m_dSalary[g];
		}
	}
	void m_Show_LastSalary() {
		cout << m_LastSalary;
	}

	void m_Get_dTax() {
		m_dTax = 0;
		for (int g = 8; g < 15; g++) {
			m_dTax += m_dSalary[g];
		}
	}
	void m_Show_dTax() {
		cout << m_dTax;
	}

	void m_Get_StartSalary() {
		m_StartSalary = 0;
		for (int g = 0; g < 8; g++) {
			m_StartSalary += m_dSalary[g];
		}
	}
	void m_Show_StartSalary() {
		cout << m_StartSalary;
	}

	void m_In_Member() {
		m_In_Basic_Ifo();
		m_In_dSalary();
		m_Get_dTax();
		m_Get_StartSalary();
		m_Get_LastSalary();
	}
	void m_Show_Member() {
		m_Show_Basic_Ifo();
		m_Show_dSalary();
	}
	void batchInput() {
		int num = 0;
		cout << "请输入录入人数：";
		cin >> num;
		cout << "请输入" << num << "位教工的工资信息" << endl;
		for (int i = Salary::m_count; i < num + Salary::m_count; i++) {
			workers[i].m_In_Member();
		}
		Salary::m_count += num;
	}
	//--------------------------------------
	//写入属性
	Salary m_Get_Max_LastSalary(Salary& a) {
		if (a.m_LastSalary > m_LastSalary) {
			return a;
		}
		else {
			return *this;
		}
	}
	Salary m_Get_Min_LastSalary(Salary& a) {
		if (a.m_LastSalary < m_LastSalary) {
			return a;
		}
		else {
			return *this;
		}
	}
	
private:
	void checkPosition(string* title) {
		if (*title != "教授" && *title != "副教授" && *title != "讲师" && *title != "助教" && *title != "初级") {
			cout << "无此职位请重新输入:";
			cin >> *title;
			checkPosition(title);
		}
	}
	bool m_findnum(const string num) {
		for (int i = 0; i < Salary::m_count-1; i++) {
			if (workers[i].m_num == num) {
				return true;
			}
		}
		return false;
	}
	void checkNum(string* num)
	{
		if (m_findnum(*num)) {
			cout << "工号已存在，请重新输入：";
			cin >> *num;
			checkNum(num);
		}
	}
	
}workers[SIZE], temp;

//学校12个月总额
class School {
	friend class Salary;
public:
	int year;
	int startyear;
	int month;
	int startmonth;
	double month_sum[12][3];//1.应发工资总额 2.扣税额 3.实发工资总额
	School() {
		month = 0; year = 0;
		memset(month_sum, 0, sizeof(month_sum));
		SYSTEMTIME st;
		GetLocalTime(&st);
		month = st.wMonth; year = st.wYear;
	}
	void m_In_Month_Sum_LastSalary(double LastSalary) {
		month_sum[month][2] += LastSalary;
	}
	void m_In_Month_Sum_dTax(double dTax) {
		month_sum[month][1] += dTax;
	}
	void m_In_Month_Sum_StartSalary(double StartSalary) {
		month_sum[month][0] += StartSalary;
	}
	void m_Show_Month_Sum() {

	}
};



int Salary::m_count = 0;




//--------------------------------全局函数申明-------------------------------------
void outputtitle() {
	cout << "工号" << "\t" << "姓名" << "\t" << "职称" << "\t" << "岗位工资" << "\t" <<
		"薪级工资" << "\t" << "岗位津贴" << "\t" <<
		"生活补贴" << "\t" << "奖励绩效" << "\t" << "公积金贴" << "\t" <<
		"逐月房贴" << "\t" << "交通贴" << "\t" << "应缴公积金" << "\t" <<
		"失业险" << "\t" << "养老险" << "\t" << "职业年金" << "\t" <<
		"医疗险" << "\t" << "工会费" << "\t" << "医互金" << "\t" << endl;
}
void deleteRecord(int num) {
	for (int i = num; i < Salary::m_count; i++) {
		workers[num] = workers[num + 1];
	}
}
void sortNum() {
	for (int i = 1; i < Salary::m_count - 1; i++) {
		for (int g = i; g > 0; g--) {
			if (workers[g].m_num < workers[g - 1].m_num) {
				temp = workers[g];
				workers[g] = workers[g - 1];
				workers[g - 1] = temp;
			}
		}
	}
}
int biSearchNum(Salary arr[], string key) {
	sortNum();
	int high = Salary::m_count - 1, low = 0, mid = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		if (arr[mid].m_num > key) {
			high = mid - 1;
		}
		else if (arr[mid].m_num < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
void sortName() {
	for (int i = 1; i < Salary::m_count - 1; i++) {
		for (int g = i; g > 0; g--) {
			if (workers[g].m_name < workers[g - 1].m_name) {
				temp = workers[g];
				workers[g] = workers[g - 1];
				workers[g - 1] = temp;
			}
		}
	}
}
int biSearchName(Salary arr[], string key) {
	sortName();
	int high = Salary::m_count - 1, low = 0, mid = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		if (arr[mid].m_name > key) {
			high = mid - 1;
		}
		else if (arr[mid].m_name < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
void sortLastSalary() {
	for (int i = 1; i < Salary::m_count - 1; i++) {
		for (int g = i; g > 0; g--) {
			if (workers[g].m_LastSalary < workers[g - 1].m_LastSalary) {
				temp = workers[g];
				workers[g] = workers[g - 1];
				workers[g - 1] = temp;
			}
		}
	}
}
int biSearchLastSalary(Salary arr[], string key) {
	sortLastSalary();
	int high = Salary::m_count - 1, low = 0, mid = 0;
	while (high >= low) {
		mid = (high + low) / 2;
		if (arr[mid].m_name > key) {
			high = mid - 1;
		}
		else if (arr[mid].m_name < key) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int findnum(string num) {
	for (int i = 0; i < Salary::m_count; i++) {
		if (workers[i].m_num == num) {
			return i;
		}
	}
	return 0;
}


//read,save
void read() {
	ifstream infile;
	infile.open("userdata.txt");
	if (!infile) {
		cout << "读取文件失败。";
		abort();
	}
	for (int i = 0; i < SIZE; i++) {
		infile.read(reinterpret_cast<char*>(&workers[i]), sizeof(Salary));
		if (workers[i].m_name != temp.m_name) {
			Salary::m_count++;
		}
		else {
			break;
		}
	}
	infile.close();
}
void save() {
	ofstream outfile;
	outfile.open("userdata.txt");
	if (!outfile) {
		cout << "写入文件失败。";
		abort();
	}
	for (int i = 0; i < Salary::m_count; i++) {
		outfile.write(reinterpret_cast<char*>(&workers[i]), sizeof(Salary));
	}
	outfile.close();
}
//---------------------------------------------------------------------------------



void choice(int choice) {
	switch (choice) {
	case 0:break;
	case 1:temp.batchInput(); break;
	case 2:break;
	case 3:break;
	case 4:break;
	case 5:break;
	case 6:break;
	case 7:break;
	case 8:break;
	case 9:break;
	}
}


int main() {
	read();
	//System system12;
	//system12.menu();
	workers[0].m_Show_Member();
	workers[1].m_Show_Member();
	workers[2].m_In_Member();
	workers[2].m_Show_Member();
	/*workers[1].m_In_Basic_Ifo();
	workers[1].m_In_dSalary();
	workers[0].m_In_Basic_Ifo();
	workers[0].m_In_dSalary();*/
	save();
}