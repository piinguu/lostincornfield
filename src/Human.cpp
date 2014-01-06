#include "Human.h"

#include "Weapon.h"
#include<cassert>
#include<typeinfo>

namespace licf
{
	void Human::fight(Actor & a)
	{
		double attack = fist_power;
		//find best weapon
		for (auto it = objects.begin(); it != objects.end(); ++it)
		{
			try
			{
				Object * o = *it;
				Weapon * w = static_cast<Weapon*>(o);
				if (w->attack_rate() > attack)
					attack = w->attack_rate();
			}
			catch (const std::bad_cast &) {}
		}
		
		while (hp > 0){
			a.hp -= attack;
			std::cout << "Motståndaren har nu " << a.hp << " hp\n";
			if (a.hp <= 0){
				std::cout << "Motståndaren dog.\n";
				a.environment->leave(a);
			}
		}
	}
	
	bool Human::pick_up(Object * o)
	{
		if (environment->drop(o)){ //environment dropped the object -> contained it...
			objects.push_back(o);
			return true;
		}
		std::cout << "Kan inte plocka upp objektet...\n";
		return false;
	}

	bool Human::drop(Object * o)
	{
		//find the object and remove it
		for (auto it = objects.begin(); it != objects.end(); ++it)
			if ((*it) == o){ //TODO: does this comparison work?
				if (environment->pick_up(o)){
					objects.erase(it);
					return true;
				}
				std::cout << "Miljön vill inte ta emot objektet\n";
				return false;
			}
		//couldn't find object
		std::cout << "Finns inget sådant objekt\n";
		return false;
	}
	
	void Human::talk()
	{
		std::cout << "Hej, jag är en människa.\n";
	}
	
	void Human::action()
	{
		//TODO
	}

}
