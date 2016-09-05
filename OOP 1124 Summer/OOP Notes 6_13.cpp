#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
//private: //not needed, its the default
	string name;
	int height;
	double weight;
	Person* spouse;
public:
	Person() :name(""), height(0) {weight = 0; } //Default constructor

	Person(string newName) : name(newName), height(0), weight(0),spouse(nullptr){}

	int getHeight() const{
		return height;
	}
	string getName() const{
		return name;
	}
	double getWeight() const{
		return weight;
	}
	void setName(string newname){
		name = newname;
	}
	void setHeight(int newHeight);
	void setWeight(double newWeight);
	bool isMarried()const{
		return spouse == nullptr;
	}
	string getSpouseName() const;
	bool marry(Person& other);
	void divorce();
};

void Person::setHeight(int newHeight){
	height = newHeight;
}

void Person::setWeight(double newWeight){
	weight = newWeight;
}

string Person::getSpouseName() const{
	if(isMarried()){
		return spouse->name;
	}
	return "(unmarried)";
}

void Person::divorce(){
	if(!isMarried()){
		return;
	}
	spouse->spouse = nullptr;
	spouse = nullptr;
}

bool Person::marry(Person& other){
	if(this->isMarried() || other.isMarried()){
		return false;
	}
	spouse = &other;
	other.spouse = this;
}
int main(){
	Person p;
	p.setName("John");
	cout << p.getHeight() << endl;

	Person p2("David"); //one string argument constructor
	//Person p3(100.5); //not allowed, only string or nothing!
}