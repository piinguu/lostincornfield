#pragma once

#include "Animal.h"

class Dog : public Animal {
	double max_hp() { return 20; }
	std::string type() { return "hund"; }
		
	void fight(Actor);
	void action();
}
