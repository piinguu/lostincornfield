#include "Human.h"

#include "../objects/Weapon.h"
#include<cassert>
#include<typeinfo>

namespace licf
{
	void Human::fight(Actor * a)
	{
		/*
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
		*/
		while (hp > 0){
			if (!a->hitted(attack_rate)){
				std::cout << "Motståndaren dog.\n";
				return;
			}
			//motståndaren slår
		}
	}
	
	bool Human::pick_up(Object * o)
	{
		if (environment->drop(o)){ //environment dropped the object -> contained it...
			objects.push_back(o);

			Weapon * w = static_cast<Weapon*>(o);
			if (w->attack_rate() > attack_rate)
				attack_rate = w->attack_rate();

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
					
					double max_power = fist_power;

					for (auto it = objects.begin(); it != objects.end(); ++it){
						Object * o = *it;
						Weapon * w = static_cast<Weapon*>(o);
						//TODO: test if the static_cast behaves as we want it to behave
						if (w->attack_rate() > max_power)
							max_power = w->attack_rate();
					}
					
					if (attack_rate != max_power){
						attack_rate = max_power;
						std::cout << "Bästa vapnet har nu styrkan " << attack_rate << std::endl;
					}
					return true;
				}
				std::cout << "Miljön vill inte ta emot objektet\n";
				return false;
			}
		//couldn't find object
		std::cout << "Finns inget sådant objekt\n";
		return false;
	}
	
	void Human::talk() const
	{
		std::cout << "Hej, jag är en människa.\n";
	}
	
	void Human::action()
	{
		//TODO
	}

}
