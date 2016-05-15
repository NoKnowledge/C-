#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft {
	class Noble;
	class Warrior {
	public:
		Warrior(const std::string& new_name, double new_strength);
		std::string get_name();
		double get_hp()const;
		void set_hp(double new_hp);
		void set_hired(Noble* new_boss);
		void runaway();
	private:
		std::string warrior_name;
		double strength;
 		Noble* boss;
	};
}

#endif
