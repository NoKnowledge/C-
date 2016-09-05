//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
	string name;
	protected: //can be accessed by members of a derived class
	int height;
public:
	Person(string newname = ""):name(newname), height(1){}
	int getHeight() const{
		return height;
	}
	void setHeight(int newHeight){
		height = newHeight;
	}
	string getName() const{
		return name;
	}
	void changeName(string newname){
		name = newname;
	}

};

class Student : public Person{ //student "is a" person
	double gpa;
public:
	Student(double newGpa = 0, string newName = "");
	Student(string newName): Person(newName), gpa(0){}
	void setGpa(double newGpa){
		gpa = newGpa;
	}
	double getGpa() const{
		return gpa;
	}
};

Student::Student(double newGpa, string newName):Person(newName){
	gpa = newGpa;
}

void Student::changeName(newName){
	gpa = 0;
	//name = newName //illegal, name is private
	//changeName(newName); //calls STUDENT changename
	Person::changeName(newName);
}

void func(const Person& p){
	cout << p.getName() << endl;
}


class Pet{
	string name;
public:
	void setName(string newName){
		name = newName;
	}
	string getName() const{
		return name;
	}
	virtual void makeNoise() const = 0; //pure virtual function
	void feed() const{
		makeNoise();
	}
};

class Cat: public Pet{
	int livesRemaining;
public:
	Cat(): livesRemaining(9){}
	void reduceLivesRemaining(){
		livesRemaining--;
	}
	Cat& operator -- (){
		livesRemaining--;
		return *this;
	}
	Cat operator -- (int){
		Cat temp = *this;
		livesRemaining--;
		return temp;
	}
	void makeNoise() const{
		cout << "MEOW!" << endl;
	}
};

class Dog: public Pet{
	string breed;
public:
	Dog(string newBreed = "mutt"): breed(newBreed){}
	string getBreed() const{
		return breed;
	}
	void makeNoise() const{
		cout << "WOOF!" << endl;
	}
};

int main(){
	/*
	Student a;
	s.changeName("Daniel");
	s.setGpa(4.0);
	Person p("John");
	*/
	//Pet p;
	Pet* pptr;
	Cat c;
	Cat* cptr = &c;
	//p = c; //SLICING, copies those items from cat that exist in pet
	//c = p //only allowed if we overload Cat::operator=(const Pet&)
	//polymorphism
	pptr = &c; //always allowed, polymorphism
	//cptr = &p  //NEVER ALLOWED
	cout << pptr->getName() << endl; 
	//pptr can access any pet class functions in the cat object
	cout << "Make the pet make noise!" << endl;
	pptr->makeNoise();
	cout << "Done making noise" << endl;

	Pet** arr = new Pet*[5];
	arr[0] = new Dog;
	arr[1] = new Cat;
	arr[2] = new Dog;
	arr[3] = new Cat;
	arr[4] = new Dog;
	for(int i = 0; i < 5; i++){
		arr[i]->makeNoise();
	}

}