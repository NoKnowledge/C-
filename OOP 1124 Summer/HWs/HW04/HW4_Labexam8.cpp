//Jimmy Lauchoy
//CS1124 Summer

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//int length;

int stringLength(char* aString){
	//if (*aString == nullptr)
	if (*aString == '\0'){ //somehow would not work with nullptr
		//int returnLen = length;
		//length = 0;
		//return returnLen;
		return 0;
	}
	else{
		//length++;
		return 1 + stringLength(++aString);
	}
}

int fillArray(ifstream& readFile, int newarray[]){
	int num;
	while (readFile >> num){
		newarray = &num;
		//cout << '\n' << *newarray << endl;
		return 1 + fillArray(readFile, newarray + 1);
	}
	return 0; //if file is empty returns 0
}

int main(){
	//problem 1
	char newstring[] = "this is a string";
	int len = 0;
	len = stringLength(newstring);
	cout << len << endl;
	//cout << length << endl;
	char newstring2[] = "this is another string";
	len = stringLength(newstring2);
	cout << len << endl;
	//problem 2
	ifstream filename;
	filename.open("data.txt");
	int anArray[1000];
	int size = 0;
	size = fillArray(filename, anArray);
	cout << "Number of ints: " << size << endl;
	filename.close();
	ifstream filename2;
	filename2.open("emptydata.txt");
	int anArray2[1000];
	int size2 = 0;
	size2 = fillArray(filename2, anArray2);
	cout << "Number of ints2: " << size2 << endl;
	filename2.close();
}