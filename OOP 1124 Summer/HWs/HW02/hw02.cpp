//Jimmy Lauchoy
//CS1124 Summer
//HW 02

#include <iostream>
#include <string>

using namespace std;

class Measure{
	int feet;
	int inches;
public:
	Measure(): feet(0), inches(0){}
	Measure(int newInches): inches(newInches), feet(0){reduce();}
	int getFeet() const {return feet;}
	int getInch() const {return inches;}
	Measure operator +  (const Measure& rhs) const;
	Measure operator -  (const Measure& rhs) const;
	friend bool operator == (const Measure& lhs, const Measure& rhs);
	friend bool operator != (const Measure& lhs, const Measure& rhs);	
	Measure& operator ++ (); //preincrement
	Measure  operator ++ (int n); //postincrement
	friend ostream& operator << (ostream& os, const Measure& rhs);

	void reduce(){
     	while(inches < 0){
     		--feet;
     		inches += 12;
     	}
     	if(feet <= 0){feet = 0;}
        while(inches > 11){
         	++feet;
         	inches = inches - 12;
        }
 	}
};

Measure Measure::operator+(const Measure& rhs) const {
    Measure temp;
    temp.inches = inches + rhs.inches;
    temp.feet = feet + rhs.feet;
    return temp; 
}
Measure Measure::operator-(const Measure& rhs) const {
    Measure temp;
    temp.inches = inches - rhs.inches;
    temp.feet = feet - rhs.feet;
    return temp; 
}

bool operator == (const Measure& lhs, const Measure& rhs){
	//cout << "both objects are the same" << endl;
    return (lhs.inches == rhs.inches && lhs.feet == rhs.feet); 
    //check to see if both inches & feet are the same
 
}

bool operator!=(const Measure& lhs, const Measure& rhs){
	//cout << "both objects are not the same" << endl;
    return(lhs.inches != rhs.inches) || (lhs.feet != rhs.feet);
}

Measure& Measure::operator++(){
    inches++;
    return *this;
}

Measure Measure::operator++(int n){
	Measure temp;
	temp.inches = inches;
	temp.feet = feet;
	inches++;
	return temp;
}

ostream& operator << (ostream& output, const Measure& rhs) {
    output << rhs.feet << "F' " << rhs.inches << " I'' " << endl; 
    return output;
}


int main(){
	Measure m(15);
	cout << m << endl;
	Measure n(26);
	cout << n << endl;
	cout << m + n << endl;
	cout << m - n << endl;
	cout << m << endl;
	cout << ++m << endl;
	cout << m++ << endl;
	bool a = m == n;
	cout << a << endl;
	bool b = m != n;
	cout << b << endl;
}