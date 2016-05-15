/* Jimmy Lauchoy
   CS 1124
   HW 06 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Noble{
public:
	Noble(const string name) : n_name(name), alive(true) {}
	string get_name(){
		return n_name;
	}
	bool is_alive() const{
		return alive;
	}

	virtual void set_alive() {
		alive = false;
	}

	virtual double get_str() const = 0;
	virtual void set_str(double str_ratio) = 0;
	virtual void battle_cry() const = 0;
	void battle(Noble& opponent) { 
		cout << get_name() << " battles " << opponent.get_name() << endl;
		if (is_alive() == true){ //checks if noble is alive
			if (opponent.is_alive() == true) { //checks if opponent is alive
				battle_cry();
				opponent.battle_cry();
				double noble_str = 0, opponent_str = 0;
				noble_str = get_str();
				opponent_str = opponent.get_str();
				if (get_str() < opponent.get_str()) { //noble is weaker than opponent
					cout << opponent.get_name() << " defeats " << get_name() << endl;
					double factor = get_str() / opponent.get_str();
					set_str(0);
					set_alive();
					opponent.set_str(factor);
				}	 
				else if (get_str() > opponent.get_str()) { //noble is stronger than opponent
					cout << get_name() << " defeats " << opponent.get_name() << endl;
					double factor = opponent.get_str() / get_str();
					opponent.set_str(0);
					opponent.set_alive();
					set_str(factor);
		 		}
		 		else if (get_str() == opponent.get_str()) {
				cout << "They both killed each other!" << endl;
				set_str(0);
				opponent.set_str(0);
				}
			}
			else {
				cout << opponent.get_name() << " is already dead!" << endl;
			}
		}
		else if (get_str() == 0 && opponent.get_str() == 0) {
				cout << "THEY'RE BOTH DEAD!!" << endl;
		}
		else {
			if (opponent.is_alive() == false) {
				cout << "They're both dead already!" << endl;
			}
			else {
				cout << get_name() << " is already dead!" << endl;
			}
		}	
	}		

private:
	string n_name;
	bool alive;
};

class PersonWithStrengthToFight: public Noble{ 
public:
	PersonWithStrengthToFight(const string name, double str): Noble(name), n_str(str) {}
	virtual double get_str() const {
		return n_str;
	}
	virtual void set_str(double new_str){
		n_str = n_str - new_str;
	}
	void battle_cry() const {}
private:
	double n_str;
};

class Lord;

class Protector{ //abstract class
public:
	Protector(const string& name, double str, Lord* lord = NULL): w_name(name), w_str(str), lord(lord){}
	double get_str() const{
		return w_str;
	}
	void set_str(double modified_hp){
		w_str = modified_hp;
	}
	string get_name() const{
		return w_name;
	}
	bool is_hired(){
		return (lord != NULL);
	}
	void set_lord(Lord* boss){
		lord = boss;
	}
	Lord* get_lord() const{
		return lord;
	}
	virtual void defend() = 0;
	//string get_boss(){
		//return lord->get_name();
	//}

private:
	string w_name;
	double w_str;
	Lord* lord;
	//Lord* boss;
};

class Lord: public Noble{ 
public:
	Lord(const string name): Noble(name){}
	void hires(Protector& soldier){
		if (is_alive() == true){ //checks to see if lord is alive
			if (soldier.get_str() != 0){ //checks to see if soldier is "alive"
				if (soldier.is_hired() == false){ //checks if a lord owns the soldier
					army.push_back(&soldier);
					soldier.set_lord(this);
				}
				else{
					cout << "Soldier is already owned by another lord!" << endl;
				}
			}
			else{
				cout << "Soldier is dead!" << endl;
			}
		}
		else{
			cout << get_name() << " is dead! Cannot hire!" << endl;
		}
	}
	virtual double get_str() const{
		double army_str = 0;
		for (size_t i = 0; i< army.size(); i++){
			army_str += army[i]->get_str();
		}
		return army_str;
	}
	virtual void set_str(double factor) { 
		for (size_t i = 0; i < army.size(); i++) {
				//each warrior's new hp is their original value subtracted 
			    //by the original value * ratio
				double modified_hp = army[i] -> get_str() * (1-factor);
				army[i]->set_str(modified_hp);
		}
	}
	void battle_cry() const{ //each protector says their own phrase
		for (size_t i = 0; i < army.size(); i++){
			army[i]->defend();
			//if (army[i]->defend() != "POOF!"){
				//cout << get_name() << endl;
				//sometimes get warning "passing `const Lord' as `this' 
				//argument of `class string Noble::get_name()' discards const"
		}
	}

private:
	vector<Protector*>army;
	Protector* soldier;
	double army_str;
};

class Wizard: public Protector{ //wizard & warrior inherit from Protector
public:
	Wizard(const string& name, double str): Protector(name, str){}
	void defend(){
		cout << "POOF!" << endl;
	}
};
class Warrior: public Protector{ //abstract class
public:
	Warrior(const string& name, double str): Protector(name, str){}
};
class Archer: public Warrior{ //archer and swordsman inherit from warrior
public:
	Archer(const string& name, double str): Warrior(name, str){}
	void defend(){
		cout << "TWANG!  " << get_name() << " says: Take that in the name of my lord, " << endl;
		cout << get_lord()->get_name() << endl;
	}
};
class Swordsman: public Warrior{
public:
	Swordsman(const string& name, double str): Warrior(name, str){}
	void defend(){
		cout << "CLANG!  " << get_name() << " says: Take that in the name of my lord, " << endl;
		cout << get_lord()->get_name() << endl;
	}
};

int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250); 	
    joe.battle(randy);	
    joe.battle(sam);	
    Lord janet("Janet");	
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);	
    janet.hires(stout);	
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);	
    janet.battle(barclay);	
    janet.hires(samantha);	
    Archer pethora("Pethora", 50);	
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);	
    sam.battle(barclay);	
    joe.battle(barclay);
}