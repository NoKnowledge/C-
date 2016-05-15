#include "Noble.h"
#include "Warrior.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace WarriorCraft {
	class Noble;

	Warrior::Warrior(const string& new_name, double new_strength) : warrior_name(new_name), strength(new_strength), boss(nullptr) {}
	string Warrior::get_name() {
		return warrior_name;
	}
	double Warrior::get_hp() const {
		return strength;
	}
	void Warrior::set_hp(double new_hp) {
		strength = new_hp;
	}
	void Warrior::set_hired(Noble* new_boss) {
		boss = new_boss;
	}
	void Warrior::runaway() {
		if (boss != nullptr) {
			cout << warrior_name << " flees in terror, abandoning his lord, " << boss ->get_name() << "!" << endl;
			boss->remove_warrior(warrior_name);
			boss = nullptr;
		}
		else {
			cout << warrior_name << " does not have a lord!" << endl;
		}
	}
}