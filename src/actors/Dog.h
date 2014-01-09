#pragma once

#include "Animal.h"

namespace licf
{
	class Dog : public Animal {
	private:
		int aggression_level;
	public:	
		Dog(int agg) : Animal(20), aggression_level(agg)
		{
			attack_rate = 30;
		}
		
		double max_hp() { return 20; }
		std::string type() { return "hund"; }
		
		void fight(Actor *);
		void action();
		void talk() const;
	};
}
