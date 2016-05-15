#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

//struct needs two variables
struct Warriors {
	string name;
	int strength;
};
//prototypes for the file
void warriors(string w_name,int power);
void battle(string name_1, string name_2);
vector<Warriors> new_warrior; //created vector of type Warriors

int main(){
	//read the file
	ifstream ifs("warriors.txt");
	if (!ifs){ //checks to see if file is valid / can be found
		cerr << "Could not open this file\n";
		exit(1);
	}
	//set variables
	string commands;
	string w_name;
	int power;
	while (ifs>>commands){ //runs through file line by line
		if (commands == "Warrior"){ //looks for string "Warrior"
			ifs>>w_name>>power; //next to words are stored into variables
			warriors(w_name,power); //runs function to add a new warrior
		}
		else if (commands == "Status"){ //looks for string "Status"
			for (int i = 0; i <= new_warrior.size()-1; i++){ //reads through vector 
			cout << "Warrior: "<< new_warrior[i].name << "," << //prints out the status of the warrior
			" strength:"<< new_warrior[i].strength << endl;
			}
		}
		else if (commands == "Battle"){ //looks for string "Battle"
			string n_1, n_2; //new variables to store names in each line after Battle
			ifs>>n_1>>n_2;
			battle(n_1,n_2); //runs function battle
		}
	}
	return 0; //finishes program
}

void warriors(string w_name,int power){ //function does not return anything, takes in name of warrior and its strength value
	Warriors War_type;
	War_type.strength = power; //within War_type, strength is stored with int power
	War_type.name = w_name; //new name of warrior is stored with the name input
	new_warrior.push_back(War_type); //vector is updated with the new warrior and stats
}

void battle(string name_1, string name_2){ //function that compares two warriors and prints outcome
	int str_1, str_2; //sets new variables to get strength values for each warrior
	cout << name_1 << " battles " << name_2 << endl;
	for (int i = 0; i <= new_warrior.size()-1; i++){ //searches for strength value that matches the input name
		if (name_1 == new_warrior[i].name){
			str_1 = new_warrior[i].strength; //changes value of variable to match the value from the vector
		}
		else if (name_2 == new_warrior[i].name){ //same happens for name #2
			str_2 = new_warrior[i].strength;
		}
	}	
	//comparisons and calculations happen here
	if (str_1 == 0 && str_2 == 0){ //checks to see if both warriors are dead already
		cout << "THEY'RE BOTH DEAD!!" << endl;
	}
	else if (str_1 == 0){ //checks to see if warrior 1 is dead
		cout << name_1 << " is dead already." << endl;
	}
	else if (str_2 == 0){ //checks to see if warrior 2 is dead
		cout << name_2 << " is dead already." << endl;
	}
	else if (str_1 == str_2){ //if both have same str values, they both die & str become 0
		cout << "Oh no! They both killed each other!" << endl;
		str_1 = 0; str_2 = 0;
	}
	else{
		if (str_1 > str_2){ //if warrior 1 has higher str, warrior 1 wins and warrior 2's str becomes 0
			str_1 = str_1 - str_2; str_2 = 0; //difference between higher str and lower str is calculated
			cout << name_1 << " defeats " << name_2 << endl;	
		}
		else if (str_1 < str_2){ //if warrior 2 has higher str, warrior 2 wins and warrior 1's str becomes 0
			str_2 = str_2 - str_1; str_1 = 0; //difference between higher str and lower str is calculated
			cout << name_2 << " defeats " << name_1 << endl;
		}
	}
	for (int i = 0; i <= new_warrior.size()-1; i++){ //updates the new str values 
		if (name_1 == new_warrior[i].name){ //warrior 1's stats are updated in the vector
			new_warrior[i].strength = str_1;
		}
		else if (name_2 == new_warrior[i].name){ //warrior 2's stats are updated in the vector
			new_warrior[i].strength = str_2;
		}
	}	
}
