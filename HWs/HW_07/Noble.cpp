#include "Warrior.h"
#include "Noble.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace WarriorCraft {

	ostream&  operator << (ostream& os, const Noble& noble) {
		os << noble.get_name() << " has an army of " << noble.army.size() << endl;
		for (size_t i = 0; i < noble.army.size(); i++) {
			os << "\t" << noble.army[i]->get_name() << " : " << noble.army[i]->get_hp() << endl;
		}
		return os;
	}
	Noble::Noble(const string& new_name) : noble_name(new_name) {}
	
	string Noble::get_name() const {
		return noble_name;
	}
	void Noble::display() {
		cout << noble_name << " has an army of " << army.size() << endl;
		for (int i = 0; i < army.size(); i++) {
			cout << "\t" << army[i]->get_name() << " : " << army[i]->get_hp() << endl;
		}
	}
	//REMEMBER TO PASS BY REFERENCE!!
	void Noble::hire(Warrior& warrior) {
		Warrior* warrior_ptr = new Warrior(warrior);
		army.push_back(warrior_ptr);
		warrior.set_hired(this);		
	}
	//sets the total amount of strength of the noble using the army's strengths
	double Noble::get_army_strength() {
		double total = 0;
		for (size_t i = 0; i < army.size(); i++) {
			total += army[i]->get_hp();
		}
		return total;
	}
	void Noble::remove_warrior(const string& warrior_name) {
		for (size_t i = 0; i < army.size(); i++) {
			if (army[i]->get_name() == warrior_name) {
				army[i] = army[army.size() - 1];
				army.pop_back();
			}
		}
	}
	//used to update the strength of the warriors after battle
	void Noble::set_army_hp(double new_army_hp) {
		for (size_t i = 0; i < army.size(); i++) {
			army[i]->set_hp(new_army_hp);
		}
	}
	//pretty similar to the last hw's, with some mods
	void Noble::battle(Noble& opponent) {
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
			double factor = get_army_strength() / opponent.get_army_strength();
			for (size_t i = 0; i < army.size(); i++) {
				double modified_hp = army[i]->get_hp() * factor;
				army[i]->set_hp(modified_hp);
			}
		}
		else if (get_army_strength() > opponent.get_army_strength()) {
			cout << get_name() << " defeats " << opponent.get_name() << endl;
			opponent.set_army_hp(0);
			double factor = opponent.get_army_strength() / get_army_strength();
			for (size_t i = 0; i < army.size(); i++) {
				double modified_hp = army[i]->get_hp() * factor;
				army[i]->set_hp(modified_hp);
			}
		}
	}
}