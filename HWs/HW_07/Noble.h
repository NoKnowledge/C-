#ifndef NOBLE_H
#define NOBLE_H

#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft {
	class Warrior;
	class Noble {
	public:
		friend std::ostream& operator << (std::ostream& os, const Noble& noble);
		Noble(const std::string& new_name);
		std::string get_name() const;
		double get_army_strength();
		void display();
		void hire(Warrior& warrior);
		void set_army_hp(double new_army_hp);
		void battle(Noble& opponent);
		void remove_warrior(const std::string& warrior_name);
	private:
		std::string noble_name;
		std::vector<Warrior*>army;
	};
	//std::ostream& operator << (std::ostream& os, const Noble& noble);
}

#endif