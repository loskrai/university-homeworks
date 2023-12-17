#include"login.h"

#define SIZE 100 //最大容量
using namespace std;
//职工工资类
class Salary {
	friend class System;
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
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0; m_LastSalary = 0; m_StartSalary = 0; m_dTax = 0; memset(m_dSalary, 0, sizeof(m_dSalary));
	}
	void clean() {
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0; m_LastSalary = 0; m_StartSalary = 0; m_dTax = 0; memset(m_dSalary, 0, sizeof(m_dSalary));
	}
	//写入属性
	//------------------------------------
	void m_In_Basic_Ifo() {
		cout << "请输入职工的四项身份信息（工号 姓名 职称 工龄）：\n";
		cin >> m_num >> m_name >> m_title >> m_workage;
		checkPosition(&m_title);
		checkNum(&m_num);
	}
	void m_Change_Basic_Ifo() {
		string b;
		m_name.clear(); m_num.clear(); m_title.clear(); m_workage = 0;
		cout << "请输入职工的四项身份信息（工号 姓名 职称 工龄）：\n";
		cin >> b >> m_name >> m_title >> m_workage;
		checkNum(&b);
		checkPosition(&m_title);
		m_num = b;
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
		cout << m_LastSalary << "\t";
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
		m_Get_LastSalary();
		m_Show_Basic_Ifo();
		m_Show_dSalary();
		m_Show_LastSalary();
	}
	void m_Show_All(){
		outputtitle();
		for (int i = 0; i < Salary::m_count; i++) {
			workers[i].m_Show_Member();
			cout << "\n";
		}

	}
	void batchInput() {
		int num = 0,temp=0;
		cout << "请输入录入人数：";
		cin >> num;
		cout << "请输入" << num << "位教工的工资信息" << endl;
		temp = Salary::m_count;
		for (int i = 0; i < num ; i++) {
			workers[i+ temp].m_In_Member();
			Salary::m_count++;
		}
	}
	//--------------------------------------
	//整个删除
	void deleteRecord(int num) {
		for (int i = num; i < Salary::m_count; i++) {
			workers[num] = workers[num + 1];
		}
	}

	//平均值
	void getTotal() {
		temp.clean();
		for (int i = 0; i < Salary::m_count; i++) {
			temp.m_dTax += workers[i].m_dTax;
			temp.m_LastSalary += workers[i].m_LastSalary;
			temp.m_StartSalary += workers[i].m_StartSalary;
			for (int g = 0; g < 15; g++) {
				temp.m_dSalary[g] += workers[i].m_dSalary[g];
			}
		}
	}
	void getAvg() {
		getTotal();
		temp.m_dTax /=Salary::m_count;
		temp.m_LastSalary /= Salary::m_count;
		temp.m_StartSalary /= Salary::m_count;
		for (int g = 0; g < 15; g++) {
			temp.m_dSalary[g] /= Salary::m_count;
		}
	}
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
	void outputtitle() {
		cout << "工号" << "\t" << "姓名" << "\t" << "职称" << "\t" <<"工龄" <<"\t" << "岗位工资" << "\t" <<
			"薪级工资" << "\t" << "岗位津贴" << "\t" <<
			"生活补贴" << "\t" << "奖励绩效" << "\t" << "公积金贴" << "\t" <<
			"逐月房贴" << "\t" << "交通贴" << "\t" << "应缴公积金" << "\t" <<
			"失业险" << "\t" << "养老险" << "\t" << "职业年金" << "\t" <<
			"医疗险" << "\t" << "工会费" << "\t" << "医互金" << "\t" << "实发工资" << "\t\n";
	}
	void checkPosition(string* title) {
		if (*title != "教授" && *title != "副教授" && *title != "讲师" && *title != "助教" && *title != "初级") {
			cout << "无此职位请重新输入:";
			cin >> *title;
			checkPosition(title);
		}
	}
	bool m_findnum(const string num) {
		for (int i = 0; i < Salary::m_count; i++) {
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
int Salary::m_count = 0;
//学校12个月总额
class School {
	friend class Salary;
public:
	int month;
	int startmonth;
	double month_sum[12][3];//1.应发工资总额 2.扣税额 3.实发工资总额
	School() {
		month = 0;
		memset(month_sum, 0, sizeof(month_sum));
		SYSTEMTIME st;
		GetLocalTime(&st);
		month = st.wMonth;
	}
	void m_In_Month_Sum_LastSalary(double LastSalary) {
		month_sum[month-1][2] += LastSalary;
	}
	void m_Get_Month_Sum_LastSalary() {
		for (int i = 0; i < Salary::m_count; i++) {
			m_In_Month_Sum_LastSalary(workers[i].m_LastSalary);
		}
	}
	void m_In_Month_Sum_dTax(double dTax) {
		month_sum[month-1][1] += dTax;
	}
	void m_Get_Month_Sum_dTax() {
		for (int i = 0; i < Salary::m_count; i++) {
			m_In_Month_Sum_dTax(workers[i].m_dTax);
		}
	}
	void m_In_Month_Sum_StartSalary(double StartSalary) {
		month_sum[month-1][0] += StartSalary;
	}
	void m_Get_Month_Sum_StartSalary() {
		for (int i = 0; i < Salary::m_count; i++) {
			m_In_Month_Sum_StartSalary(workers[i].m_StartSalary);
		}
	}
	void m_Get() {
		memset(month_sum, 0, sizeof(month_sum));
		m_Get_Month_Sum_StartSalary();
		m_Get_Month_Sum_dTax();
		m_Get_Month_Sum_LastSalary();
	}
	void m_Show_Month_Sum() {
		m_Get();
		cout << "\t应发\t扣税\t实发";
		for (int i = 0; i < 12; i++) {
			cout << "\n" << i + 1 << "月\t";
			for (int g = 0; g < 3; g++) {
				cout << month_sum[i][g] << "\t";
			}
		}
	}
	void save() {
		ofstream outfile;
		outfile.open("total.txt", ios::binary);
		if (!outfile) {
			abort();
		}
		for (int i = 0; i < 12; i++) {
			for (int g = 0; g < 3; g++) {
				outfile << month_sum[i][g] << endl;
			}
		}
		outfile.close();
	}
	void read() {
		ifstream infile;
		infile.open("total.txt",ios::binary);
		if (!infile) {
			cout << "读取文件失败。";
			ofstream test;
			test.open("total.txt");
			test.close();
			abort();
		}
		for (int i = 0; i < 12; i++) {
			for (int g = 0; g < 3; g++) {
				infile >> month_sum[i][g];
			}
		}
		infile.close();
	}
}sc;
//系统类（主要处理函数）
class System {
	friend class Salary;
public:
	int menu()
	{
		string choice;
		cout << setw(29) << setfill(' ') << "工资管理系统" << endl;
		cout << setw(25) << setfill('*') << "菜单" << setw(25) << setfill('*') << "*" << endl;
		cout << "1.录入工资                2.删除工资记录" << setw(50) << setfill(' ') << " " << endl;
		cout << "3.查询工资记录            4.修改工资记录" << setw(50) << setfill(' ') << " " << endl;
		//插入工资（单条）因为查寻时的排序而失去了在某个位置插入的意义，若默认在最后加插入，那么批量录入也可实现，故修改作用5
		cout << "5.重置                    6.统计分析" << setw(50) << setfill(' ') << " " << endl;
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
		else if (choice == "5" || choice == "重置" ) {
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
	void choice(int choice) {
		switch (choice) {
		case 0:break;
		case 1:temp.batchInput(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 2:deleteMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 3:findMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 4:changeMenu(); break;
		case 5:rebuild(); return;
		case 6:analysisMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 7:sortMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 8:fixMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
		case 9:showMenu(); cout << "\n\n\n\n\n\n\n\n\n"; break;
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
		cout << "不存在此工号\n";
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
		cout << "不存在此人\n";
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
	void findLastSalary(double a,double b) {
		bool c = false;
		for (int i = 0; i < Salary::m_count; i++) {
			if (workers[i].m_LastSalary >= a && workers[i].m_LastSalary <= b) {
				workers[i].m_Show_Member();
				c = true;
				cout << "\n";
			}
		}
		if (!c) {
			cout << "不存在";
		}
	}
	int findLastSalaryCount(int a, int b) {
		int count = 0;
		for (int i = 0; i < Salary::m_count; i++) {
			if (workers[i].m_LastSalary >= a && workers[i].m_LastSalary <= b) {
				count++;
			}
		}
		return count;
	}
	void printstar(int num) {
		for (int i = 0; i < num; i++) {
			cout << "*";
		}
	}
	void makepic() {
		int a, b, c, d, e;
		a = b = c = d = e = 0;
		for (int i = 0; i < Salary::m_count; i++) {
			if (workers[i].m_title == "教授") {
				a++;
			}
			else if (workers[i].m_title == "助教") {
				b++;
			}
			else if (workers[i].m_title == "讲师") {
				c++;
			}
			else if (workers[i].m_title == "副教授") {
				d++;
			}
			else {
				e++;
			}
		}
		cout << "教授：";
		printstar(a);
		cout << "\n";
		cout << "助教：";
		printstar(b);
		cout << "\n";
		cout << "讲师：";
		printstar(c);
		cout << "\n";
		cout << "副教授：";
		printstar(d);
		cout << "\n";
		cout << "初级：";
		printstar(e);
		cout << "\n";
	}
	double salaryPUP(string title) {
		double uprate = 0;
		if (title == "教授") {
			uprate = 0.1;
		}
		else if (title == "副教授") {
			uprate = 0.08;
		}
		else if (title == "讲师") {
			uprate = 0.05;
		}
		else if (title == "初级") {
			uprate = 0.04;
		}
		else {
			uprate = 0.03;
		}
		return uprate;
	}
	double salaryYear(int year) {
		double up = 0;
		if (year >= 1 && year <= 10) {
			up = 40;
		}
		else if (year > 10 && year <= 15) {
			up = 45;
		}
		else if (year > 15 && year <= 20) {
			up = 50;
		}
		else if (year > 20 && year <= 25) {
			up = 55;
		}
		else {
			up = 60;
		}
		return up;
	}
	void salaryChange(double& salaryPO, double& salaryYe, string workPOsi, int workage) {
		salaryYe += salaryYear(workage);
		salaryPO *= (1 + salaryPUP(workPOsi));
	}
	void changeMenu() {
		int choice=-1;
		string num;
		while (choice != 0) {
			cout << "  ====>1.修改工资\n\n";
			cout << "  ====>2.修改基本信息\n\n";
			cout << "  ====>0.退出\n\n";
			cout << "请选择（0~1）\n\n";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 0) {
				cout << "格式错误";
				cin >> choice;
			}
			if (choice == 1) {
				cout << "想要修改工号为几的记录：";
				cin >> num;
				int a = -1;
				a = biSearchNum(workers, num);
				if (a != -1) {
					workers[a].m_Show_Basic_Ifo();
					workers[a].m_In_dSalary();
					cout << "修改完成,修改后：\n";
					workers[a].m_Show_Member();
					cout << "\n";
				}
			}
			else if (choice == 2) {
				cout << "想要修改工号为几的记录：";
				cin >> num;
				string g, b, c;
				int d;
				int a = -1,a1=-1;
				a = biSearchNum(workers, num);
				if (a!=-1) {
					workers[a].m_Show_Basic_Ifo();
					workers[a].m_Change_Basic_Ifo();
					cout << "修改完成,修改后：\n";
					workers[a].m_Show_Member();
					cout << "\n";
				}
			}
			else {
				break;
			}
		}
	}
	void fixMenu() {
		int choice = -1;
		while (choice != 0) {
			string find;
			cout << "  ====>1.调整全部\n\n";
			cout << "  ====>2.调整指定工号的员工\n\n";
			cout << "  ====>0.退出调整\n";
			cout << "请选择（1-2或0）";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 0) {
				cout << "格式错误，请重新输入";
				cin >> choice;
			}
			if (choice == 1) {
				for (int g = 0; g < Salary::m_count; g++) {
					workers[g].m_LastSalary = 0;
					salaryChange(workers[g].m_dSalary[0], workers[g].m_dSalary[1], workers[g].m_title, workers[g].m_workage);
					workers[g].m_Get_dTax();
					workers[g].m_Get_StartSalary();
					workers[g].m_Get_LastSalary();
				}
				temp.m_Show_All();
				cout << "修改完成\n";

			}
			else if (choice ==2 ) {
				int a = -1;
				cout << "请输入想要调整的工号：";
				cin >> find;
				a = biSearchNum(workers, find);
				if (a != -1) {
					salaryChange(workers[a].m_dSalary[0], workers[a].m_dSalary[1], workers[a].m_title, workers[a].m_workage);
					workers[a].m_Get_dTax();
					workers[a].m_Get_StartSalary();
					workers[a].m_Get_LastSalary();
					temp.m_Show_All();
					cout << "修改完成";
				}
				cout << "\n";
			}
			else {
				break;
			}
		}
	}
	void findMenu() {
		int choice = -1;
		while (choice != 0) {
			string find;
			cout << "  ====>1.按职工工号查询\n\n";
			cout << "  ====>2.按职工姓名查询\n\n";
			cout << "  ====>3.按工资范围查询\n\n";
			cout << "  ====>0.退出查询\n";
			cout << "请选择（1-3或0）";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
				cout << "格式错误，请重新输入";
				cin >> choice;
			}
			if (choice == 1) {
				int a = -1;
				cout << "请输入想要查询的工号：";
				cin >> find;
				a = biSearchNum(workers, find);
				if (a != -1) {
					workers[biSearchNum(workers, find)].m_Show_Member();
				}
				cout << "\n";
			}
			else if (choice == 2) {
				bool a = false;
				cout << "请输入想要查询的姓名：";
				cin >> find;
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_name == find) {
						workers[i].m_Show_Member();
						a = true;
						cout << "\n";
					}
				}
				if (!a) {
					cout << "不存在此人";
				}
			}
			else if (choice == 3) {
				double a, b;
				cout << "请输入工资范围[a,b]";
				cin >> a >> b;
				findLastSalary(a, b);
				cout << "\n";
			}
			else {
				break;
			}
		}
		cout << "退出";
	}
	void sortMenu() {
		int choice = -1;
		while (choice != 0) {
			cout << "  ====>1.按职工工号排序\n\n";
			cout << "  ====>2.按职工姓名排序\n\n";
			cout << "  ====>3.按实发工资排序\n\n";
			cout << "  ====>0.退出排序\n";
			cout << "请选择（1-3或0）";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 0) {
				cout << "格式错误，请重新输入";
				cin >> choice;
			}
			if (choice == 1) {
				sortNum();
				temp.m_Show_All();
			}
			else if (choice == 2) {
				sortName();
				temp.m_Show_All();
			}
			else {
				sortLastSalary();
				temp.m_Show_All();
			}
		}
		cout << "退出";
	}
	void deleteMenu() {
		int choice = -1;
		string num;
		while (choice != 0) {
			cout << "  ====>1.按职工工号删除\n\n";
			cout << "  ====>2.按职工姓名删除\n\n";
			cout << "  ====>0.退出删除\n";
			cout << "请选择（1-2或0）";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 0) {
				cout << "输入格式错误，请重新输入！";
				cin >> choice;
			}
			if (choice == 1) {
				cout << "想要删除工号为几的记录：";
				cin >> num;
				cout << "\n";
				int a = 0;
				a = biSearchNum(workers, num);
				if (a != -1) {
					temp.deleteRecord(a);
					cout << "删除完成\n";
					temp.m_Show_All();
					Salary::m_count--;
				}
			}
			else if (choice == 2) {
				cout << "想要删除谁的记录：";
				cin >> num;
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_name == num) {
						temp.deleteRecord(i);
						Salary::m_count--;
					}
				}
				cout << "删除完成\n";
				temp.m_Show_All();
			}
			else {
				break;
			}
		}
		cout << "退出\n";
	}
	void showMenu() {
		temp.m_Show_All();
		temp.getAvg();
		cout << Salary::m_count << "位员工的工资记录\n";
		cout << "平均值";
		temp.m_Show_Member();
	}
	void analysisMenu() {
		int choice = -1;
		while (choice != 0) {
			cout << "  ====>1.显示全校教职工各项工资平均工资及总工资\n\n";
			cout << "  ====>2.统计符合指定条件的工资信息\n\n";
			cout << "  ====>3.统计全校职工各职称人数\n\n";
			cout << "  ====>4.显示实发工资最大值，最小值，以及低于平均工资的员工\n\n";
			cout << "  ====>5.显示每月的应发工资总额、扣税额及实发工资总额\n\n";
			cout << "  ====>0.退出分析界面\n";
			cin >> choice;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice!=5 && choice != 0) {
				cout << "输入格式错误，请重新输入";
				cin >> choice;
			}
			if (choice == 1) {
				temp.getTotal();
				temp.outputtitle();
				cout << "总计：";
				temp.m_Show_Member();
				cout << "\n平均值";
				temp.getAvg();
				temp.m_Show_Member();
				cout << "\n";
			}
			else if (choice == 2) {
				double a[100] = {0},section1=0,section2=0;
				int num1 = -1, num2 = 0;
				cout << "您想查看员工工资前几项工资的统计:";
				cin >> num1;
				while (!(num1 >= 1 && num1 <= 15)) {
					cout << "输入格式错误，请重新输入.";
					cin >> num1;
				}
				for (int i = 0; i < Salary::m_count;i++) {
					for (int g = 0; g < num1; g++) {
						a[i] += workers[i].m_dSalary[g];
					}
				}
				cout << "您想统计几个工资区间：";
				cin >> num2;
				while (num2 <= 0) {
					cout << "输入格式错误，请重新输入.";
					cin >> num2;
				}
				for (int i = 1; i <= num2;i++) {
					cout << "第" << i << "个工资区间[a,b](以空格为界)";
					cin >> section1 >> section2;
					if (section2 < section1) {
						cout << "输入格式错误，请重新输入：";
						cin >> section1 >> section2;
					}
					double count = 0;
					for (int i = 0; i < Salary::m_count; i++) {
						if (a[i] >= section1 && a[i] <= section2) {
							++count;
						}
					}
					cout << "在[" << section1 << "," << section2 << "]的有" << count << "人，占" << ((count / Salary::m_count) * 100) << "%\n";
				}
			}
			else if (choice == 3) {
				makepic();
			}
			else if (choice == 4){
				for (int i = 0; i < Salary::m_count-1; i++) {
					temp = workers[i].m_Get_Max_LastSalary(workers[i + 1]);
				}
				cout << "得到最多实发工资的是：\n";
				temp.m_Show_Member();
				cout << "\n";
				for (int i = 0; i < Salary::m_count - 1; i++) {
					temp = workers[i].m_Get_Min_LastSalary(workers[i + 1]);
				}
				cout << "得到最少实发工资的是：\n";
				temp.m_Show_Member();
				cout << "\n";
				temp.getAvg();
				int a = 0;
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_LastSalary < temp.m_LastSalary) {
						a++;
					}
				}
				cout << "低于平均工资的员工人数为：" << a << "人\n";
				cout << "具体人员为：\n";
				for (int i = 0; i < Salary::m_count; i++) {
					if (workers[i].m_LastSalary < temp.m_LastSalary) {
						workers[i].m_Show_Basic_Ifo();
						cout<<"\n";
					}
				}
			}
			else if (choice == 5) {
				sc.m_Show_Month_Sum();
				cout << "\n";
			}
			else {
				break;
			}
		}
	}
	void rebuild() {
		ofstream outfile;
		initializeFile();
		outfile.open("userdata.txt");
		outfile.close();
		outfile.open("total.txt", ios::binary);
		outfile.close();
		ofstream otime;
		otime.open("time.txt");
		otime.close();
	}
}sy;


//--------------------------------全局函数申明-------------------------------------
//read,save
void read() {
	ifstream infile;
	infile.open("userdata.txt");
	if (!infile) {
		cout << "读取文件失败。";
		abort();
	}
	for (int i = 0; i<100; i++) {
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



int main() {
	read();
	sc.read();
	int choice = -1;
	bool log = login();
	while (log && choice != 0 && choice != 5) {
		choice = sy.menu();
		sy.choice(choice);
	}
	if (choice == 5) {
		return 0;
	}
	save();
	sc.save();
	return 0;
}