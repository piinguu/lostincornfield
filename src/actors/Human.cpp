#include "Human.h"

#include "../objects/Weapon.h"
#include<cassert>
#include<typeinfo>

#include "../env/Environment.h"

namespace licf
{
	void Human::fight(Actor * a)
	{
		double prev_hp = a->hp;
		std::cout << "Du slår en gång... ";
		a->hitted(this);
		if (a->hp > 0)
			std::cout << "fienden förlorar " << (prev_hp - a->hp) << std::endl;
		else
		{
			std::cout << "fienden dör\n";
			return;
		}
		prev_hp = hp;
		std::cout << "Fienden slår tillbaka... ";
		Actor::hitted(a);
		if (hp > 0)
			std::cout << "du förlorar " << (prev_hp - hp) << std::endl;
		else
			std::cout << "du dör.\n";
	}
	
	bool Human::pick_up(Object * o)
	{
		if (environment->drop(o)){ //environment dropped the object -> contained it...
			objects.push_back(o);

			Weapon * w = dynamic_cast<Weapon*>(o);
			if (w != nullptr && w->attack_rate() > attack_rate)
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
			if ((*it) == o){
				if (environment->pick_up(o)){
					objects.erase(it);
					
					double max_power = fist_power;

					for (auto it = objects.begin(); it != objects.end(); ++it){
						Object * o = *it;
						Weapon * w = dynamic_cast<Weapon*>(o);
						if (w && w->attack_rate() > max_power)
							max_power = w->attack_rate();
					}

					double diff = attack_rate - max_power;
					if ((diff < 0.1) && (-diff < 0.1)){ //drop changed attack rate
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
}
