#pragma once

#include "Animal.h"

namespace licf
{
	struct Snake : public Animal {
		Snake() : Animal(50)
		{
			attack_rate = 25; 
		}
		double max_hp() const { return 50; }
		std::string type() const { return "orm"; }
	
		void fight(Actor *);
		void action();
		void talk() const;
	};
}
