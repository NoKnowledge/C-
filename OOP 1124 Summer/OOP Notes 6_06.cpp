//Jimmy Lauchoy
//CS1124 SUMMER 


#include <iostream>
#include <string>
#include <vector>

//lab exam code
Readings temp;
vector<Readings> v;
while(file1 >> temp.id >> temp.r1){
	temp r2 = 0;
	temp.seenR2
}
while(file2 >> temp.id >> temp.r2){
	bool seen = false;
	for(Readings& r : v){
		if(r.id == temp.id){
			r.r2 = temp.r2;
			seen = r.seenR2 = true;
		}
	}
	if(!seen){
		cout << temp.id << " exists in file2, does not exist in file1" << endl;
	}
}
for(Readings r : v){
	if(!r.seenR2){
		cout << r.id << " exists in file1, does not exist in file2";
	}
	else{
		cout << r.id 
	}
}

//notes

struct Person{
	string name;
	Person* spouse;

};

int main(){
	int arr[10];
	int x = 100;
	int * ptr;
	ptr = &x;
	int* y, z; //y is a pointer to int, z is an int
	cout << "A: " << x << endl; //100
	cout << "B: " << &x << endl; //memory address
	cout << "C: " << ptr << endl; //same as B
	cout << "D: " << *ptr << endl; //100
	cout << "E: " << &ptr << endl; //
	int** w = &ptr;
	int* newptr;
	newptr = nullptr; //or newptr = NULL;
	if(newptr != nullptr){
		cout << *newptr << endl; //CRASH bc dereferencing nullptr
	}
	ptr = arr;
	ptr[3] = 100;
	ptr = ptr + 3;
	cout << *ptr;	//prints 100
	cout << ptr[0] << endl; //prints 100
	ptr++;
	*ptr = 200;

	for(int i = 0; i < 10; i++){
		arr[i] = i * 10;
		ptr = arr + 3j;
		cout << *ptr++ << endl; //prints 30	
		cout << *ptr << endl;	//prints 40
	}
	Person p1;
	p1.spouse = nullptr;
	p1.name = "Daniel"heap lyh=bbub;
	Person p2;
	p2.spouse = "Glorie";
	p1.spouse = &p2;
	p2.spouse = &p1;
	Person* sp = p1.spouse;
	
	prt = getxxgcf(p1.spouse != nullptr){                                                                                                                                                      
		cout < p1.name << "is married to: " << *(p1.spouse).name << endl
		delete ptr;
		get= new int[shower]l
}
}