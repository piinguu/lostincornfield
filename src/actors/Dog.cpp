#include "Dog.h"

namespace licf
{
	void Dog::fight(Actor * a)
	{
		while (hp > 0 && a->hp > 0)
		{
			//fight until someone dies...
			a->hitted(attack_rate);
			if (a->hp > 0)
				hitted(a->attack_rate);
		}
	}
	
	void Dog::action()
	{
		aggression_level += next_rand(5) - 2;
		if (aggression_level < 0)
			aggression_level = 0;
		if (aggression_level > 10)
			aggression_level = 10;
	}

	void Dog::talk() const
	{
		if (aggression_level > 5)
			std::cout << "Grrrrrr...\n";
		else
			std::cout << "Voff!\n";
	}
}
