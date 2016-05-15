#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>
#include <iostream>

struct Node;

void display(Node* headptr, int exponent);
class Polynomial {
	friend std::ostream& operator << (std::ostream& os, const Polynomial& rhs); //output operator
	friend bool operator == (const Polynomial& lhs, const Polynomial& rhs);         //== operator
	friend bool operator != (const Polynomial& lhs, const Polynomial& rhs);         //!= operator
private:
	Node* headptr;
	int degree;
public:
	Polynomial(const std::vector<int>&coefficients);
	Polynomial::Polynomial();
	void listAddToEnd(Node*& headptr, int data);
	Node* listFindEnd(Node* headptr);
	int evaluate(int n); //evaluates polynomial
	~Polynomial(); //destructor
	Polynomial(const Polynomial& rhs); //copy constructor
	Polynomial& operator = (const Polynomial& rhs); //assignment operator
	Polynomial& operator += (const Polynomial& rhs);											   //+= operator
	Polynomial operator + (const Polynomial& rhs);													  //+ operator

};
#endif
