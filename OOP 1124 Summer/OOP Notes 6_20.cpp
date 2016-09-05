//Jimmy Lauchoy
//CS1124 Summer
//June 20, 2016

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class BigInt{
	int val;
public:
	/*explicit*/BigInt(int newval = 0) : val(newval){}
	void setVal(int newval){val = newval;}
	int getVal()const{return val;}

	//BigInt& operator+(const BigInt& rhs) const;
	BigInt& operator+=(const BigInt& rhs);

	BigInt operator++(int); //post-increment
	BigInt& operator++(); //pre-increment
};

BigInt& BigInt::operator+(const BigInt& lhs, const BigInt& rhs){
	BigInt temp = lhs;
	temp += rhs;
	return temp;
}

BigInt BigInt::operator++(int){ //post-increment
	BigInt temp(*this);
	val++;
	return temp;
}

BigInt& BigInt::operator++(){ //pre-increment
	val++;
	return *this;
}


bool operator< (const BigInt& rhs) const;
bool operator> (const BigInt& rhs) const{return rhs < *this;}
bool operator<=(const BigInt& rhs) const{return !(rhs < *this);}
bool operator>=(const BigInt& rhs) const{return !(*this < rhs);}
bool operator!=(const BigInt& rhs) const{return (rhs < *this ||);}
bool operator==(const BigInt& rhs) const{return !(rhs < *this ||);}

int& operator[](const int index){return val;}
int operator[](const int index)const{return val;}

BigInt operator-(const BigInt& lhs){}

int main(){
	/*
	C = A + B;
	C = (A + B);
	C.operator(A:operator + (B)); //+ is overloaded as a member
	C.operator = (opeartor+(A,B)); //+ is overloaded as a non-member
	Types of operands
	*/
	BigInt a(100);
	BigInt b;
	b.setVal(20);
	BigInt c;
	c.setVal(a.getVal() + b.getVal());
	c = a + b;
	c = a + 10; //uses default "+"" constructor
	c = 10 + a; //does not work if + is a member
	c = 10 - a;
}