#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

class Student {
public:
	string getNum() {
		return num;
	}
	string getName() {
		return name;
	}
	string getGender() {
		return gender;
	}
	string getGrade() {
		return grade;
	}
	int getAge() {
		return age;
	}
	int getScore() {
		return score;
	}
	void setNum(string num) {
		this->num = num;
	}
	void setName(string name) {
		this->name = name;
	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setGrade(string grade) {
		this->grade = grade;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setScore(int score) {
		this->score = score;
	}
	void input() {
		cout << "请输入学号：";
		cin >> num;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入性别：";
		cin >> gender;
		cout << "请输入年龄：";
		cin >> age;
		cout << "请输入分数：";
		cin >> score;
		cout << "请输入班级：";
		cin >> grade;
	}
	void display() {
		cout << "学号：" << num << "\t";
		cout << "姓名：" << name << "\t";
		cout << "性别：" << gender << "\t";
		cout << "年龄：" << age << "\t";
		cout << "分数：" << score << "\t";
		cout << "班级：" << grade << "\n";
	}
private:
	string num;
	string name;
	string gender;
	int age;
	int score;
	string grade;
};

bool cmp(Student a, Student b) {
	return a.getScore() > b.getScore();
}

class StudentManage {
public:
	StudentManage() :num(0) {};
	void addStudent() {
		student[num].input();
		++num;
	}
	void showAll() {
		for (int i = 0; i < num; ++i) {
			student[i].display();
		}
	}
	void showByScore() {
		sort(student, student + num,cmp);
		showAll();
	}
	void showByGrade(string grade) {
		for (int i = 0; i < num; ++i) {
			if (student[i].getGrade() == grade) {
				student[i].display();
			}
		}
	}
private:
	Student student[100];
	int num;
};
//int main() {
//	StudentManage a;
//	int choice = 1;
//	while (choice != 0) {
//		cout << "1.添加学生基本信息\n";
//		cout << "2.显示所有学生信息\n";
//		cout << "3.按分数显示所有学生的基本信息\n";
//		cout << "4.显示指定班级学生的基本信息\n";
//		cin >> choice;
//		switch (choice) {
//		case 1:a.addStudent(); break;
//		case 2:a.showAll(); break;
//		case 3:a.showByScore(); break;
//		case 4:cout << "那个班级？"; string b; cin >> b; a.showByGrade(b); break;
//		}
//	}
//}