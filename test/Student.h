#pragma once
#include"headfile.h"

class Person;
class Pupil;

class Person {
public:
	Person(const string& na = "无名氏", const int& ag = 18, const char& ge = 'M', const string id = "none") {
		name = na;
		age = ag;
		gender = ge;
		idCode = id;
	}
	void sayHellow() {
		cout << "大家好！我是" << name << endl;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
private:
protected:
	string name;
	int age;
	char gender;
	string idCode;
};

class Pupil:public Person {
public:
	Pupil(const string& na, const int& ag, const char& ge, const string id, const string& school, const string& grand,const string &clas,const int &num,
		const double &cn, const double &en,const double &ma) :Person(na,ag,ge,id),school(school),grand(grand),clas(clas),en(en),cn(cn),ma(ma),num(num){}
	double getSumScore() {
		return en + cn + ma;
	}
	void printIfo() {
		cout << school << " " << grand << " " << clas << " " << num << " " << name << " " << age << " " << gender << " " << idCode << " "
			<< getSumScore();
	}
private:
	string school;
	string grand;
	string clas;
	int num;
	double cn;
	double en;
	double ma;
protected:
};