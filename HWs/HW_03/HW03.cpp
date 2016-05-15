#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class Sword{ //sword is what the warrior looks for and establishes the warrior's hp
public:
	Sword(string new_sword_name, int new_sword_hp) { //constructor takes in the name of the sword and the hp value of the sword
		sword_name = new_sword_name;
		sword_hp = new_sword_hp;
	}
	//getters
	int get_hp() const {
		return sword_hp;
	}

	string get_name() const {
		return sword_name;
	}
	//setters
	void set_hp(int new_hp) {
		sword_hp = new_hp;
	}

private: //sword is binded to the warrior
	string sword_name;
	int sword_hp;
};

class Warrior{
	
public: 
	//constructor takes three values, two of which come from the sword class
Warrior(string new_warrior_name, string sword_name, int warrior_hp):sword(sword_name, warrior_hp) {
	warrior_name = new_warrior_name;
	}
	//getters
	string get_name() const {
		return warrior_name;
	}

	string get_sword_name() const {
		return sword.get_name();
	}

	int get_warrior_hp() const {
		return sword.get_hp();
	}
	//setters
	void set_warrior_hp(int new_hp) {
		sword.set_hp(new_hp);
	}
	//function that the warrior uses to fight another warrior
	void battle(Warrior& warrior_other) {
		cout << get_name() << " battles " << warrior_other.get_name() << endl;
		//same comparisons as last hw, modified syntax
		if (get_warrior_hp() == 0 && warrior_other.get_warrior_hp() == 0) {
			cout << "THEY'RE BOTH DEAD!!" << endl;
		}
		else if (get_warrior_hp() == 0) {
			cout << get_name() << " is already dead!" << endl;
			}
		else if (warrior_other.get_warrior_hp() == 0) {
			cout << warrior_other.get_name() << " is already dead!" << endl;
			}
		else if (get_warrior_hp() == warrior_other.get_warrior_hp()) {
			cout << "They both killed each other!" << endl;
			set_warrior_hp(0);
			warrior_other.set_warrior_hp(0);
			}
		else if (get_warrior_hp() < warrior_other.get_warrior_hp()) {
			cout << warrior_other.get_name() << " defeats " << get_name() << endl;
			set_warrior_hp(0);
			warrior_other.set_warrior_hp(get_warrior_hp() - warrior_other.get_warrior_hp());
			}	 
		else if (get_warrior_hp() > warrior_other.get_warrior_hp()) {
			cout << get_name() << " defeats " << warrior_other.get_name() << endl;
			set_warrior_hp(get_warrior_hp() - warrior_other.get_warrior_hp());
			warrior_other.set_warrior_hp(0);
			}
	}
private: 
	string warrior_name;
	Sword sword; //creates object from class Sword so it can be accessed
};


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
	string weapon_name;
	int weapon_power;
	vector<Warrior>warrior_data;
	while (ifs>>commands){ //runs through file line by line
		if (commands == "Warrior"){ //looks for string "Warrior"
			ifs>>w_name>>weapon_name>>weapon_power; //next three words are stored into variables
			Warrior warrior(w_name,weapon_name,weapon_power); //runs function to add a new warrior
			warrior_data.push_back(warrior);
		}
		else if (commands == "Status"){ //looks for string "Status"
			cout << "There are: " << warrior_data.size() << " warriors" << endl;
			for (int i = 0; i <= warrior_data.size()-1; i++){ //reads through vector 
				cout << "Warrior: "<< warrior_data[i].get_name() << "," << //prints out the status of the warrior
				" weapon: "<< warrior_data[i].get_sword_name() << " " << warrior_data[i].get_warrior_hp() << endl;
			}
		}
		else if (commands == "Battle") { //looks for string "Battle"
			string warrior_1, warrior_2; //new variables to store names in each line after Battle
			ifs >> warrior_1 >> warrior_2;
			int index1, index2;
			for (int i = 0; i <= warrior_data.size() -1; i++) { //looks for the names in the vector
				if (warrior_data[i].get_name() == warrior_1) {
					index1 = i; //stores index of vector in a variable
				}
				else if (warrior_data[i].get_name() == warrior_2) {
					index2 = i;
				}
			}
			warrior_data[index1].battle(warrior_data[index2]); //engages the battle between warrior 1 and warrior 2
		}
	}
	return 0; //finishes program
}
