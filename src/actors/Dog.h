#pragma once

#include "Animal.h"

class Dog : public Animal {
	Dog() : Animal(20){}
	double max_hp() { return 20; }
	std::string type() { return "hund"; }
		
	void fight(Actor);
	void action();
}
