/* Jimmy Lauchoy
   CS 1124
   HW 05 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Warrior {
private:
string w_name;
int strength;

public:
	Warrior(const string name, const int str) : w_name(name), strength(str) {}
	string get_name() const{
		return w_name;
	}
	int get_str() const{
		return strength;
	}
	void set_str(int new_str){
		strength = new_str;
	}
};

class Noble {
private:
string n_name;
vector<Warrior*>army;

public:
	Noble(const string name) : n_name(name) {}
	string get_name() const {
		return n_name;
	}
	void display() const {
		cout << n_name << " has an army of: " << army.size() << endl;
		if(army.size() == 0) {
			cout << "NONE" << endl;
		}
		for(size_t i = 0; i < army.size(); i++){
			cout << "\t" << army[i]->get_name() << ": " << army[i]->get_str() << endl;
		}
	}
	int get_army_strength(){
		int total = 0;
		for (size_t i = 0; i < army.size(); i++) {
			total += army[i] -> get_str();
		}
		return total;
	}
	void hire(Warrior* warrior) {
		army.push_back(warrior);
	}
	Warrior* fire(const string& w_name){
		for(size_t i = 0; i < army.size(); i++){
			if (army[i]->get_name() == w_name) {
				cout << "You don't work for me anymore " << w_name << "!\n--" << n_name << endl;
				Warrior* temp = army[i];
				army[i] = army[army.size() - 1]; //puts element in last position in the index that you want to be removed
				army.pop_back();
				return temp; //temp warrior is put back in unemployed vector
			}
		}
		return NULL; //expecting a pointer to Warrior, since temp is already returned, null should be returned
					 //from the loop
	}
	bool check_army(string w_name) { //loops through army to see if warrior is in it
		for(size_t i = 0; i < army.size(); i++) {
			if (w_name == army[i]->get_name()){
				return true;
			}
		}
		return false; 
	}
	void set_army_strength(int new_hp){
		for(size_t i = 0; i < army.size(); i++) {
			army[i] -> set_str(new_hp);
		}
	}
	void battle(Noble& opponent) { 
		cout << n_name << " battles " << opponent.get_name() << endl;
		if (get_army_strength() == 0 && opponent.get_army_strength() == 0) {
			cout << "THEY'RE BOTH DEAD!!" << endl;
		}
		else if (get_army_strength() == 0) {
			cout << get_name() << " is already dead!" << endl;
			}
		else if (opponent.get_army_strength() == 0) {
			cout << opponent.get_name() << " is already dead!" << endl;
			}
		else if (get_army_strength() == opponent.get_army_strength()) {
			cout << "They both killed each other!" << endl;
			set_army_strength(0);
			opponent.set_army_strength(0);
			}
		else if (get_army_strength() < opponent.get_army_strength()) {
			cout << opponent.get_name() << " defeats " << get_name() << endl;
			set_army_strength(0);
			int factor = get_army_strength() / opponent.get_army_strength();
			for (size_t i = 0; i < army.size(); i++) {
				//each warrior's new hp is their original value subtracted by the original value * ratio
				int modified_hp = army[i] -> get_str() * (1-factor);
				army[i] -> set_str(modified_hp);
				}
			//opponent.set_army_hp(get_army_strength() - opponent.get_army_strength());
			}	 
		else if (get_army_strength() > opponent.get_army_strength()) {
			cout << get_name() << " defeats " << opponent.get_name() << endl;
			opponent.set_army_strength(0);
			int factor = opponent.get_army_strength() / get_army_strength();
			for (size_t i = 0; i < army.size(); i++) {
				int modified_hp = army[i] -> get_str() * (1-factor);
				army[i] -> set_str(modified_hp);
				}
			}
		}
		void clear_army(){
			for(size_t i = 0; i < army.size(); i++) {
				delete army[i];
			}
			army.clear();
		}
	
};
int main() {
	ifstream ifs("NobleWarrior.txt"); //using file made from input file in hw05
	vector<Noble*> nobles;
	string command;
	vector<Warrior*> unemployed;
	while(ifs >> command){
		if (command == "Noble") {
			string name;
			ifs >> name;
			bool nameExists = false; //assumes the noble is new
			for (size_t i = 0; i < nobles.size(); i++) {
				if (name == nobles[i]->get_name()) {
					nameExists = true;
				}
			}
			if(nameExists==false){
				Noble* n = new Noble(name);
				nobles.push_back(n);
			}
		}
		else if (command == "Warrior") {
			//checks to see if the warrior is already in a noble's army
			//check to see if the warior is in the unemployed group
			
			string w_name;
			double strength;
			ifs >> w_name;
			ifs >> strength;
			bool nameExists = false;
			for(size_t i = 0; i < unemployed.size(); i++){
				if (w_name == unemployed[i] -> get_name()) {
					nameExists = true;
				}
			}
			
			for(size_t i = 0; i < nobles.size(); i++){
				if(nobles[i]->check_army(w_name) == true){
					nameExists = true;
				}
			}

			if(nameExists == false) {
				Warrior* warrior = new Warrior(w_name, strength);
				unemployed.push_back(warrior);
			}
		}
		else if (command=="Battle"){
			string noble_1;
			string noble_2;
			ifs >> noble_1;
			ifs >> noble_2;
			for (size_t i = 0; i < nobles.size(); i++) {
				if (noble_1 == nobles[i]->get_name()){
					for (size_t j = 0; j < nobles.size(); j++) {
						if (noble_2 == nobles[j]->get_name()){
							nobles[i]->battle(*nobles[j]);
						}
					}
				}
			}
		}
		else if (command == "Hire") {
			//first check if the noble or warrior exists
			string name;
			string w_name;
			ifs >> name;
			ifs >> w_name;
			int n_index = -1;
			int w_index = -1;
			for (size_t i = 0; i < nobles.size(); i++) {
				if (name == nobles[i] -> get_name()) {
					n_index = i;
				}
			}
			for (size_t j = 0; j < unemployed.size(); j++){
				if (w_name == unemployed[j] -> get_name()) {
					w_index = j;
				}
			}
			if (n_index != -1 && w_index != -1) {
				nobles[n_index]->hire(unemployed[w_index]);
				unemployed[w_index] = unemployed[unemployed.size()-1];
				unemployed.pop_back();
			}
		}
		else if (command == "Fire") {
			string name;
			string w_name;
			ifs >> name;
			ifs >> w_name;
			for(size_t i = 0; i < nobles.size(); i++) {
				if (name == nobles[i]->get_name()) {
					Warrior* temp = nobles[i]->fire(w_name);
					if (temp != NULL) {
						unemployed.push_back(temp); //the warrior in temp gets put back into unemployed
					}
				}
			}
		}
		else if (command == "Status") {
			cout << "STATUS\n======\nNobles:\n";
			if (nobles.size() == 0){
				cout << "NONE" << endl;
			}
			for (size_t i = 0; i < nobles.size(); i++) {
				nobles[i]->display();
			}
			cout << "Unemployed Warriors:\n";
			if (unemployed.size() == 0) {
				cout << "NONE" << endl;
			}
			for (size_t i = 0; i < unemployed.size(); i++) {
				cout << unemployed[i]->get_name() << ": " << unemployed[i]->get_str() << endl;;
			}
		}
		else if (command == "Clear") {
			//clears everything in the vectors and even the nobles' army vector
			for (size_t i = 0; i< nobles.size(); i++) {
				nobles[i]->clear_army();
			}
			for (size_t i = 0; i < unemployed.size(); i++) {
				delete unemployed[i];
			}
			for (size_t i = 0; i < nobles.size(); i++) {
				delete nobles[i];
			}
			unemployed.clear();
			nobles.clear();
			//deletes warriors from the heap and changes the size of the noble vector to 0
		
		}
	}
}