//Jimmy Lauchoy
//CS1124 Summer
//May 25, 2016

//Compilation: Changing high level(Human readable) 
//code into machine language code which can be run

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func(){
	return 5;
}

void printx(int x);

void anotherFunc(int x){ //pass by value (copy)
	x = 100;
}

void yetAnotherFunc(int& x){ //pass by reference (not a copy)
	x = 100;
}

struct Date{
	int day;
	int month;
	int year;
};

struct Person{
	string name;
	Date bday;
	Date anniversary;

	Date ImportantDates[10];
	int TestScores[4];
};

void openInputFile(ifstream& inFile){
	string filename;
	cout << "What filename: ";
	cin >> filename;
	inFile.open(filename);
	while(!inFile){
		cout << "Bad filename." << endl;
		cout << "What filename: ";
		cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}
}

const int CONSTANT_VARIABLE = 100;
const int ARRAY_MAX_SIZE = 10;
int main(){
	//File reading
	ofstream outFile;
	outFile.open("file.txt");
	//also could do: ofstream outFile("file.txt")
	for (int i = 0; i < 100; i++){
		outFile << i << endl;
	}

	ifstream inFile;
	openInputFile(inFile);
	vector<double> d;
	double temp;
	string wholeLine;
	getline(inFile, wholeLine);

	while(inFile >> temp){
		d.push_back(temp);
	}

	vector<int> v1;
	v1.push_back(100);
	for (int i = 0; i < 10; i++){
		v1.push_back(i * 10);
	}
	for (int i = 0; i < v1.size(); i++){
		cout << v1[i] << endl;
	}
	for (int val : v1){ //ranged for loop
		cout << val << endl;
	}
	v1.clear(); //get rid of everything in the vector
	vector<Date> v2;

	Person parr[10];
	parr[0].name = "John";
	parr[0].ImportantDates[0].day = 1;
	parr[0].ImportantDates[0].month = 6;
	parr[0].ImportantDates[0].year = 2016;
	int arr[ARRAY_MAX_SIZE]; //or int arr[10]
	int x = 10;
	//int arr2[x]; //not allowed
	int size = 0;
	arr[0] = 100;
	arr[1] = 200;
	for(int i = 0; i < 10; i++){
		arr[i] = i * 10;
	}
	size = 10;

	Person p1;
	p1.name = "Daniel";
	p1.bday.day = 9;
	p1.bday.month = 7;

	Date d1;
	d1.day = 1;
	d1.month = 6;
	d1.year = 2016;
	Date d2;
	d2.month = 10;
	d2.day = 31;
	d2.year = 2016;

	int num = 10;
	anotherFunc(num);
	cout << num << endl; //prints 20
	yetAnotherFunc(num);
	cout << num << endl; //prints 100
	anotherFunc(5); //allowed
	yetAnotherFunc(5); //illegal
	cout << "Hello World" << endl;
	int x; //x's value is garbage
	int y = 100; //y's value is 100
	int z(200); //z's value is 200
	//definition syntax of y and z are the same
	y = z + 100; //y = 300
	y *= 10; //y = 3000
	y++; //y = 3001
	cout << "Enter a value for x: ";
	cin >> x;
	cout << "What is your name? ";
	string name;
	cin >> name;
	if (x > 100){
		cout << "Hello";
		cout << "World";
	}
	else{
		cout << "Boo";
		cout << "hoo";
	}
	if (x > 5) {
		if (x > 100){
			cout << "A";
		}
		else{
			cout << "B";
		}
	}
	//Ctrl + A + K + F //fixes indentation
	while (x < 100){
		cout << x++;
	}
	//Do...while
	/*do{
		cout << x++;
		while (x < 100);
	}
	//for loop
	//for(init;test;increment){
		//code }
	for(int i = 0; i < 100; i++){
		cout << i;
	}*/
}

//exponentiation (** or ^) does not exist
/*
3 parts to functions:

1 function prototype (optional)
2 function call
3 function definition:
	either the definition or the prototype 
	must precede the call

*/
