#include "Bird.h"

namespace licf
{
	void Bird::fight(Actor * a)
	{
		//hit and run...
		a.hitted(attack_rate);
	}
	
	void Bird::action()
	{
		int r = next_rand(20);
		if (r == 0)
			fight(random_actor());
		if (r < 3) //fly away
			go_random();
		if (r < 5) //fly away again (note: flying two times if r < 3
			go_random();
	}
	
	void talk() const
	{
		std::cout << "Kviddevitt\n";
	}
}
