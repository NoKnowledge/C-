#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person(const string& name) : name(name), isMarried(false) {}
	void display(ostream& os = cout) const {
		cout << "Name: " << name << "; is married? ";
		if (spouse != nullptr){
			cout << "Yes!, spouse name: "
			//>>*spouse.name
			//>>(*spouse).name
			<< *spouse->name
		}
		else {
			cout << "No. \n"
		}
	}
private:
	string name;
	bool isMarried;
	string spouseName;
	// Person& spouse;
	// Person spouse;
	Person* spouse;
};

int main() {
	Person john("John");
	Person mary("Mary");
	john.display();
	mary.display();
	// john.marries(mary);
	
	/*int x = 17;
	cout << "x = " << x << endl;
	int* p =&x;
	//int *p, q //defines p as a pointer, defines q as an int
	
	cout << "p = " << p << endl;
	cout << "*p = " << *p << endl;*/
}