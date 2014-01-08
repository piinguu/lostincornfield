#pragma once

#include "Animal.h"

namespace licf
{
	class Bee : public Animal {
	public:
		Bee() : Animal(2)
		{
			 attack_rate = 5;
		}
		
		double max_hp() const { return 2; }
		std::string type() const { return "bi"; }
	
		void fight(Actor *);
		void action();
		void talk();
	};
}
