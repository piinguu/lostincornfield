#include "Bee.h"

namespace licf
{
	void Bee::fight(Actor a)
	{
		//hit one time, then die
		a.hp -= attack_rate;
		hp = 0;
	}
	
	void action();
	void talk();
}
