#pragma once

#include "Animal.h"

class Snake : public Animal {
	double max_hp() { return 50; }
	std::string type() { return "orm"; }
	
	void fight(Actor);
	void action();
}
