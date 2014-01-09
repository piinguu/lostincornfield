#include "Bee.h"

namespace licf
{
	void Bee::fight(Actor * a)
	{
		//hit one time, then die
		a->hitted(attack_rate);
		hitted(max_hp());
	}
	
	void Bee::action(){}
	void Bee::talk() const{}
}
