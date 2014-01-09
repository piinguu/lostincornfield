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
		
		double max_hp() const { return 20; }

		std::string type() const;
		
		void fight(Actor *);
		void action();
		void talk() const;
	};
}
