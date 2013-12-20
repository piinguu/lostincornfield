#pragma once

#include "Human.h"

class Farmer : public Human {
	std::string _name;
	
public:
	Human(std::string name) : _name(name) {};

	double max_hp() { return 100; }
	std::string type() { return "farmer"; }
	std::string name() { return _name; };
	
	void action();
};
