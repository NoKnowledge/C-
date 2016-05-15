/* Jimmy Lauchoy
   CS 1124
   HW 04 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Warrior{
private:
string warrior_name;
int strength;

public: 
	Warrior(string new_name, double new_strength): warrior_name(new_name), strength(new_strength){}
	string get_name() const {
		return warrior_name;
	}
	int get_hp() const {
		return strength;
	}
	void set_hp(int new_hp) {
		strength = new_hp;
	} 
};

class Noble{
private:
string noble_name;
vector<Warrior*>army; //vector uses pointer values of Warrior

public: 
	Noble(string new_name): noble_name(new_name){}
	void display() {
		cout << noble_name << " has an army of " << army.size() << endl;
		for (int i = 0; i < army.size(); i++) {
			cout << "\t" << army[i] -> get_name() << " : " << army[i] -> get_hp() << endl;
		}
	}
	//REMEMBER TO PASS BY REFERENCE!!
	void hire(Warrior& warrior) {
		army.push_back(&warrior);
	}
	// to fire a knight, swap element you want to remove with the last element in the vector
	// then use pop_back to remove the element from the vector
	void fire(Warrior& warrior) {
		for (size_t i = 0; i < army.size(); i++) {
			if (army[i] -> get_name() == warrior.get_name()){
				Warrior* temp = army[i];
				army[i] = army[i+1];
				army[i+1] = temp;
				army.pop_back();
			}
		}
		cout << warrior.get_name() << ", you're fired! -- " << noble_name << endl;
	}
	//sets the total amount of strength of the noble using the army's strengths
	int get_army_strength(){
		int total = 0;
		for (size_t i = 0; i < army.size(); i++) {
			total += army[i] -> get_hp();
		}
		return total;
	}
	string get_name() const {
		return noble_name;
	}
	//used to update the strength of the warriors after battle
	void set_army_hp(int new_army_hp) {
		for (size_t i = 0; i < army.size(); i++) {
			army[i] -> set_hp(new_army_hp);
		}
	}
	//pretty similar to the last hw's, with some mods
	void battle(Noble& opponent) {
		cout << noble_name << " battles " << opponent.get_name() << endl;
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
			set_army_hp(0);
			opponent.set_army_hp(0);
			}
		else if (get_army_strength() < opponent.get_army_strength()) {
			cout << opponent.get_name() << " defeats " << get_name() << endl;
			set_army_hp(0);
			int factor = get_army_strength() / opponent.get_army_strength();
			for (size_t i = 0; i < army.size(); i++) {
				int modified_hp = army[i] -> get_hp() * factor;
				army[i] -> set_hp(modified_hp);
			}
			//opponent.set_army_hp(get_army_strength() - opponent.get_army_strength());
			}	 
		else if (get_army_strength() > opponent.get_army_strength()) {
			cout << get_name() << " defeats " << opponent.get_name() << endl;
			opponent.set_army_hp(0);
			int factor = opponent.get_army_strength() / get_army_strength();
			for (size_t i = 0; i < army.size(); i++) {
				int modified_hp = army[i] -> get_hp() * factor;
				army[i] -> set_hp(modified_hp);
			}
			//set_warrior_hp(get_army_strength() - opponent.get_army_strength());
			
		}
	}
};

int main() {
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}
