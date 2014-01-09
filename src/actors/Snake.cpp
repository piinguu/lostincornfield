#include "Snake.h"

namespace licf
{
	void Snake::fight(Actor * a)
	{
		//std::cout << "Ormen gör plötsligt ett utfall.";
		a->hitted(attack_rate);
		if (a->hp > 0)
		{
			//std::cout << " Du slår tillbaka.";
			hitted(a->attack_rate);
		}
	}
	
	void Snake::action()
	{
		int r = next_rand(4);
		if (r == 0)
			go_random();
		else if (r == 1)
			fight(random_actor());
	}
	
	void Snake::talk() const
	{
		std::cout << "Zzzzzz...\n";
	}
}
