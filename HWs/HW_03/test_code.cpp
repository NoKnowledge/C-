#include<iostream>
#include<fstream>
#include<string> 

using namespace std;

int main(){

	ofstream theFile("players.txt");

	cout << "Enter player ID, name, money" << endl;
	cout << "press ctrl+z to quit \n" << endl;

	int id_num;
	string name;
	double money;

	while (cin >> id_num >> name >> money){
		theFile << id_num << " " << name << " " << money << endl;
	}
}