//Jimmy Lauchoy
//CS1124
//hw08

#include "Polynomial.h"

using namespace std;
struct Node {
	Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

Polynomial::Polynomial(const vector<int>& coefficients) : degree(coefficients.size() - 1) {
	headptr = new Node(coefficients[coefficients.size()-1]);
	Node* temp = headptr;
	for (size_t i = 1; i < coefficients.size(); i++) {
		listAddToEnd(temp, coefficients[degree - i]);
		//temp->next = new Node(coefficients[degree-i]);
		//temp = temp->next;
	}
}

Polynomial::Polynomial() {
	headptr = new Node(0);
}

Node* Polynomial::listFindEnd(Node* headptr) {
	if (headptr == nullptr) {
		return nullptr;
	}
	Node* p = headptr;
	while (p->next != nullptr) {
		p = p->next;
	}
	return p;
}

void Polynomial::listAddToEnd(Node*& headptr, int data) {
	if (headptr == nullptr) {
		headptr = new Node(data);
	}
	else {
		Node* theEnd = listFindEnd(headptr);
		theEnd->next = new Node(data);
	}
}

int Polynomial::evaluate(int x) {
	int last = 0;
	int exponent = 0;
	Node* current = headptr;
	while (current != nullptr) {
		if (exponent == 0) {
			last += current->data;
			exponent++;
			current = current->next;
		}
		else {
			int anExp = 1;
			for (int i = 0; i < exponent; i++) {
				anExp *= x;
			}
			last += (current->data * anExp);
			exponent++;
			current = current->next;
		}
	}
	return last;
}

Polynomial::~Polynomial() { //destructor
	while (headptr != nullptr) {
		Node* current = headptr->next;
		delete headptr;
		headptr = current;
	}
}
Polynomial::Polynomial(const Polynomial& rhs) : degree(rhs.degree) { //copy constructor
	headptr = new Node(rhs.headptr->data);
	Node* temp = rhs.headptr;
	Node* ctemp = headptr;
	degree = rhs.degree;
	while (temp->next != nullptr) {
		ctemp->next = new Node(temp->next->data);
		ctemp = ctemp->next;
		temp = temp->next;
	}
}
Polynomial& Polynomial::operator = (const Polynomial& rhs) { //assignment operator
	if (this != &rhs) {
		while (headptr != nullptr) {
			Node* current = headptr->next;
			delete headptr;
			headptr = current;
		}
		headptr = new Node(rhs.headptr->data);
		Node* temp = rhs.headptr;
		Node* ctemp = headptr;
		degree = rhs.degree;
		while (temp->next != nullptr) {
			ctemp->next = new Node(temp->next->data);
			ctemp = ctemp->next;
			temp = temp->next;
		}
	}
	return *this;
}
void display(Node* headptr, int exponent) { //method that displays the polynomial
	if (headptr == nullptr) {
		return;
	}
	++exponent;
	display(headptr->next, exponent);
	if (exponent == 0) {
		cout << headptr->data;
	}
	else if (exponent == 1) {
		cout << headptr->data << "x + ";
	}
	else if (exponent > 1) {
		cout << headptr->data << "x^" << exponent << " + ";
	}
}

ostream& operator << (ostream& os, const Polynomial& rhs) { //output operator
	display(rhs.headptr, -1);
	return os;
}

bool operator != (const Polynomial& lhs, const Polynomial& rhs) { //!= operator
	return !(lhs == rhs);
}

Polynomial Polynomial::operator + (const Polynomial& rhs) { //+ operator
	Polynomial temp(*this);
	return temp += rhs;
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	Node* c = headptr;
	Node* d = rhs.headptr;
	if (degree == rhs.degree) {
		while (c != nullptr && d != nullptr) {
			c->data = c->data + d->data;
			c = c->next;
			d = d->next;
		}
		degree = rhs.degree;
		return *this;
	}
	else if (degree < rhs.degree) {
		while (c->next != nullptr && d->next != nullptr) {
			c->data = c->data + d->data;
			c = c->next;
			d = d->next;
		}
		c->data = c->data + d->data;
		d = d->next;

		while (d != nullptr) {
			c->next = new Node(d->data);
			c = c->next;
			d = d->next;
		}
		degree = rhs.degree;
		return *this;
	}
	else {
		while (c != nullptr && d != nullptr) {
			c->data = c->data + d->data;
			c = c->next;
			d = d->next;
		}
		return *this;
	}
}

bool operator == (const Polynomial& lhs, const Polynomial& rhs) { //== operator
	bool same = true;
	Node* a = lhs.headptr;
	Node* b = rhs.headptr;
	if (lhs.degree != rhs.degree) {
		return false;
	}
	else {
		while (same == true && a != nullptr && b != nullptr) {
			if (a->data == b->data) {
				a = a->next;
				b = b->next;
			}
			else {
				same = false;
				return same;
			}
		}
		return same;
	}
}


