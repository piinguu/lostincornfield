#pragma once

#include "Animal.h"

namespace licf
{
	struct Snake : public Animal {
		Snake() : Animal(50) {}
		double max_hp() { return 50; }
		std::string type() { return "orm"; }
	
		void fight(Actor *);
		void action();
		void talk() const;
	};
}
