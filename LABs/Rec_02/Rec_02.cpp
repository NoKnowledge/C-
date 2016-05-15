//Jimmy Lauchoy
//CS1124 Rec_02

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void enter_into_vector(ifstream& read_file, vector<molecule_name>& mol_vector); //prototype

/*3 main parts: (1) the struct with three properties: number of carbon, number of hydrogen, string name of hydrocarbon
(2) main where functions are executed and print the output, (3) functions, which are also mentioned before the main*/

struct formula { //create a structure that takes in three values
	vector<string> molecule_name;
	int c_atoms;
	int h_atoms;
};

int main() {
	ifstream read_file("hydrocarbon-set-in-example.txt");
	if (!read_file) {
		cout << "File could not be found." << endl;
		exit(1);
	}
	vector<formula> mol_vector;
	string word;
	char junk : char junk2; //useless chars
	int carbon, hydrogen;
	while (read_file >> word >> junk >> carbon >> junk2 >> hydrogen) { //stores value of carbon, hydrogen, and name
																															//of hydrocarbon into vector
		enter_into_vector(mol_vector, carbon, hydrogen, word);
	}
	for (size_t in = 0; 1 < mol_vector.size(); n++) {
		cout << "C" << mol_vector[n];
	}
	system("pause");
}
/*functions split up into 2-3 parts. Reads in the name of the hydrocarbon, num carbon and num hydrogen
Enters a hydrocarbon struct from the txt file if a struct with the preexisting name does not exist*/
void enter_into_vector(vector<formula>& mol_vector,int carbon, int hydrogen, string word); //
for (size_t i = 0; i < mol_vector.size(); ++i) {
	if (carbon == mol_vector[i].carbon &&hydrogen == mol_vector[i].hydrogen) {
		mol_vector[i].molecule_name.push_back(word);
	}
	else {
		formula new_formula;
		new_formula.molecule_name.push_back(word);
	}
}
string name;
int number_of_c, number_of_h;
char test;
//tests to see if the name is already in the vector; if not, it adds a new name to the vector
while (read_file >> name >> test >> number_of_c >> test >> number_of_h) {
	temp_mol.mol_vector;
	temp_mol.h_atom = number_of_h;
	temp_mol.c_atom = number_of_c;
	for (molecule_name a : mol_vector) {
		if (mol_vector.c_atoms == temp_mol.c_atoms &&mol_vector.h_atoms == temp_mol.h_atoms) {
			temp_mol.molecule_name.push_back(name);
		}
		else {
			mol_vector.push_back(temp_mol);
		}
	}
}
/*check if same hydrogen already exists in the vector of organized hydrocarbon
looping through vector and looking for a struct with num carbon and num hydrogens as the hydrocarbon*/
void check_dup(mol_vector, number_of_c, number_of_h);
for (size_t i = 0; i < mol_vector.size(); ++i) {
	if 

}
/*sorry, I screwed up the rest of the code so I decided not to include it*/
