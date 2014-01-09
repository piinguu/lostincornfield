#include "Bee.h"

#include "Human.h"
#include "Farmer.h"
#include "../env/Environment.h"

namespace licf
{
	void Bee::fight(Actor * a)
	{
		//hit one time, then die
		a->hitted(attack_rate);
		hitted(max_hp());
	}
	
	void Bee::action()
	{
		int r = next_rand(10);
		if (r < 2)//20%. find a human and attack it, unless it's a farmer
			for (auto it = environment->actors.begin(); it != environment->actors.end(); ++it)
				if (dynamic_cast<Human*>(*it) != nullptr) //if human...
					if (dynamic_cast<Farmer*>(*it) == nullptr) //... and not farmer
						return fight(*it);
		else if (r < 6) //40%, go to a random direction
			go_random();
		//else, do nothing
	}
	
	void Bee::talk() const
	{
		std::cout << "Bzzz...\n";
	}
}
