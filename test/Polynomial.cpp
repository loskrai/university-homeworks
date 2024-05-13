#include"Polynomial.h"

void Node::Clear_Node() {
	Node* p=this;
	Node* q = p;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
}

Polynomial::Polynomial(const Polynomial &o) {
	Node* O = o.head;
	Node* a = new Node(O->coe, O->exp);
	Node* p = a;
	while (O) {
		a = a->Add_Node(O->coe, O->exp);
		O = O->next;
	}
	this->head = p;
	count++;
}

void Polynomial::print()const {
	Node* p = this->head;
	bool flag = false;
	while (p) {
		if (p->coe != 0) {
			if (p->coe >= 0) {
				if (flag) {
					cout << "+";
				}
			}
			if (p->exp == 0) {
				cout << p->coe;
			}
			else if (p->exp == 1) {
				if (p->coe == 1);
				else if (p->coe == -1) {
					cout << "-";
				}else {
					cout << p->coe;
				}
				cout << "x^" << p->exp;
			}else{
				if (p->coe == 1);
				else if (p->coe == -1)cout << "-";
				else cout << p->coe;
				cout << "x^" << p->exp;
			}
		}
		p = p->next;
		flag = true;
	}
	cout << endl;
}

float Polynomial::compute(float x)const {
	float result = 0;
	Node* p = this->head;
	while (p) {
		result = result + p->coe * pow(x, p->exp);
		p = p->next;
	}
	return result;
}

int Polynomial::seek_max()const{
	Node* p = this->head;
	int max = p->exp;
	while (p) {
		if (p->exp > max) { max = p->exp; }
		p = p->next;
	}
	return max;
}

Polynomial operator+(const Polynomial& a, const Polynomial& b) {
	Node* p = a.head;
	Node* q = b.head;
	Node* h = NULL;
	Node* s = NULL;
	int max = 0;
	float x = 0;
	int A = a.seek_max();
	int B = b.seek_max();
	max = A > B ? A : B;
	for (int i = 0; i <= max; i++) {
		while (p) {
			if (p->exp == i) {
				x = x + p->coe;
			}
			p = p->next;
		}
		while (q) {
			if (q->exp == i) {
				x = x + q->coe;
			}
			q = q->next;
		}
		if (x) {
			if (h) s = s->Add_Node(x, i);
			else {
				h = new Node(x, i);
				s = h;
			}
		}
		x = 0;
		p = a.head;
		q = b.head;
	}
	Polynomial C(h);
	return C;
}

Polynomial operator-(const Polynomial& a, const Polynomial& b) {
	Node* p = a.head;
	Node* q = b.head;
	Node* h = NULL;
	Node* s = NULL;
	int max = 0;
	float x = 0;
	max = a.seek_max() > b.seek_max() ? a.seek_max() : b.seek_max();
	for (int i = 0; i <= max; i++) {
		while (p) {
			if (p->exp == i) {
				x = x + p->coe;
			}
			p = p->next;
		}
		while (q) {
			if (q->exp == i) {
				x = x - q->coe;
			}
			q = q->next;
		}
		if (x) {
			if (h) s = s->Add_Node(x, i);
			else {
				h = new Node(x, i);
				s = h;
			}
		}
		x = 0;
		p = a.head;
		q = b.head;
	}
	Polynomial C(h);
	return C;
}

Polynomial operator*(const Polynomial& a, const Polynomial& b) {
	Node* p = a.head;
	Node* q = b.head;
	Node* h = NULL;
	Node* s = NULL;
	Polynomial C;
	Polynomial P;
	while (p) {
		while (q) {
			if (h) s = s->Add_Node(p->coe * q->coe, p->exp + q->exp);
			else {
				h = new Node(p->coe * q->coe, p->exp + q->exp);
				s = h;
			}
			q = q->next;
		}
		p = p->next;
		q = b.head;
		P.set(h);
		h = NULL;
		s = NULL;
		C = C + P;
	}
	return C;
}

Polynomial& Polynomial::operator=(const Polynomial& that) {
	Node* q = that.head;
	Node* p = this->head;
	Node* s = p;
	Node* h = NULL;
	while (q) {
		if (p) {
			p->coe = q->coe;
			p->exp = q->exp;
			s = p;
			p = p->next;
		}
		else {
			h = new Node(q->coe, q->exp);
			p = h;
			s = p;
			p = p->next;
		}
		q = q->next;
	}
	return *this;
}