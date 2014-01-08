#include "Bee.h"

namespace licf
{
	void Bee::fight(Actor * a)
	{
		//hit one time, then die
		a->hitted(attack_rate);
		hp = 0;
		environment->leave(*this);
	}
	
	void Bee::action(){}
	void Bee::talk(){}
}
