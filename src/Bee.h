#pragma once

#include "Animal.h"

class Bee : public Animal {
	double max_hp() { return 2; }
	std::string type() { return "bi"; }
	
	void fight(Actor);
	void action();
}
