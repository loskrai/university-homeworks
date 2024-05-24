#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<string.h>
using namespace std;

class BaseAccount {
public:
	BaseAccount() {}
	BaseAccount(string name, string account, double balance = 0) :name(name), account(account), balance(balance) {}
	virtual inline void setName(string name) { this->name = name; }
	virtual inline void setAccount(string account) { this->account = account; }
	virtual inline void setBalance(double blance) { this->balance = balance; }
	virtual void Deposit(double deposit) {
		this->balance += deposit;
	}
	virtual void Withdraw(double withdraw) {
		if (withdraw > this->balance) {
			cout << "insufficient";
			cout << "操作不成功";
		}
		else {
			this->balance -= withdraw;
		}
	}
	virtual void Display() {
		cout << "当前结余：" << balance << "\n";
	}
private:
protected:
	string name;
	string account;
	double balance;

};

class BasePlus :public BaseAccount {
public:
	BasePlus() {}
	BasePlus(string name, string account, double balance) :BaseAccount(name, account, balance), limit(5000), limit_sum(0) {}
	BasePlus(string name, string account, double balance, double limit) :BaseAccount(name, account, balance), limit(limit), limit_sum(0) {}
	virtual void Withdraw(double withdraw) final override {
		if (limit_sum <= limit) {
			if (withdraw > this->balance) {
				if (withdraw - limit < this->balance && withdraw - balance <= limit - limit_sum) {
					limit_sum += withdraw - balance;
					this->balance = 0;
				}
				else {
					cout << "insufficient";
					cout << "操作不成功";
				}
			}
			else {
				this->balance -= withdraw;
			}
		}
		else {
			cout << "insufficient";
			cout << "操作不成功";
		}
	}
	virtual void Display() final override {
		cout << "当前结余：" << balance << "当前透支总额：" << limit_sum << "透支上限:" << limit << "\n";
	}
private:
	double limit;
	double limit_sum;
protected:
};

int main() {
	BaseAccount BA("老王", "268555", 1000);
	BasePlus BP("老李", "256999", 5000);
	BaseAccount* p = nullptr;
	p = &BA;
	p->Deposit(200);
	p->Display();
	p->Withdraw(2000);
	p->Display();
	p->Deposit(50000);
	p->Withdraw(200);
	p->Display();
	p = &BP;
	p->Deposit(200);
	p->Display();
	p->Withdraw(6000);
	p->Display();
	p->Deposit(500);
	p->Withdraw(2000);
	p->Display();
}
