#pragma once

#include "Animal.h"

namespace licf
{
	struct Bird : public Animal
	{
		Bird() : Animal(5) {}
		double max_hp() const { return 5; }
		std::string type() const { return "fågel"; }
	
		void fight(Actor *);
		void action();
		void talk() const;
	};
}
