//Jimmy Lauchoy
//CS1124 Summer
//HW01

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//PART ONE
bool isInVector(vector<int>vec, int num) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == num) {
			return true;
		}
	}
	return false;
}

//PART TWO
void makeUnique(vector<int>&vec, vector<int>&vec2) {
	for (int i = 0; i < vec.size(); i++) {
		if (isInVector(vec2, vec[i]) == false) {
			vec2.push_back(vec[i]);
		}
	}
}

//PART THREE
void fillVectFromFile(vector<int>&vec) {
	string filename;
	ifstream readFile;
	cout << "Enter input file: ";
	cin >> filename;
	readFile.open(filename);
	if (!readFile) {
		cerr << "File could not be opened" << endl;
	}
	else {
		int num;
		while (readFile >> num) {
			vec.push_back(num);
		}
	}
	readFile.close();
}

//PART 4
int writeToFile(vector<int>vec) {
	fillVectFromFile(vec);
	vector<int>copyVec;
	makeUnique(vec, copyVec);
	string filename;
	ofstream writeFile;
	cout << "Enter output file: ";
	cin >> filename;
	writeFile.open(filename);
	for (int i = 0; i < copyVec.size(); i++) {
		writeFile << copyVec[i] << "\n" ;
	}
	writeFile.close();
	return 0;
}


int main() {
	vector<int>vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec1.push_back(5);
	vec1.push_back(7);
	vec1.push_back(7);
	vec1.push_back(8);
	vec1.push_back(9);
	vector<int>vec2;
	makeUnique(vec1, vec2);
	/*	
	cout << "PART TWO: " << endl;
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << endl;
	}
	cout << "PART THREE: " << endl;
	*/
	vector<int>vec3;
	fillVectFromFile(vec3);
	/*
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << endl;
	}
	cout << "PART FOUR: " << endl;
	*/
	vector<int>vec4;
	writeToFile(vec4);
}

