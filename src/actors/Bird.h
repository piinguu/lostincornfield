#pragma once

#include "Animal.h"

class Bird : public Animal {
	Bird() : Animal(5) {}
	double max_hp() { return 5; }
	std::string type() { return "fågel"; }
	
	void fight(Actor);
	void action();
}
