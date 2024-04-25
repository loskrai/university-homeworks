#pragma once
#include "headfile.h"

class Node;
class Polynomial;

class Node {
public:
	friend class Polynomial;
	friend Polynomial operator+(const Polynomial& a, const Polynomial& b);
	friend Polynomial operator-(const Polynomial& a, const Polynomial& b);
	friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
	Node(float c, int e, Node* n = NULL) :coe(c), exp(e), next(n) {}
	~Node(){}
	inline Node* Add_Node(float c, int e);
	void Clear_Node();
private:
	float coe;
	int exp;
	Node* next;
protected:
};

inline Node* Node::Add_Node(float c, int e) {
	Node* n = new Node(c, e);
	this->next = n;
	return n;
}

class Polynomial {
public:
	Polynomial() { Node* p = new Node(0, 0); head = p; count++; }
	Polynomial(Node *l):head(l){}
	Polynomial(const Polynomial& o);
	~Polynomial(){}
	inline void set(Node* p);
	inline void clear();
	friend inline void print_count();
	void print()const;
	float compute(float x)const;
	int seek_max()const;
	friend Polynomial operator+(const Polynomial& a, const Polynomial& b);
	friend Polynomial operator-(const Polynomial& a, const Polynomial& b);
	friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
	Polynomial& operator=(const Polynomial& that);
private:
	static int count;
	Node* head;
protected:
};

int Polynomial::count = 0;

inline void Polynomial::set(Node* p) {
	this->head = p;
}

inline void Polynomial::clear() {
	this->head->Clear_Node();
}

inline void print_count() {
	cout << "一共有" << Polynomial::count << "个多项式";
}