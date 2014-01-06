#include "Human.h"

namespace licf
{
	void Human::fight(Actor a)
	{
		//TODO
		
	}
	
	void Human::pick_up(Object o)
	{
		if (environment.drop(o)){ //environment dropped the object -> contained it...
			objects.push_back(o);
			return true;
		}
		std::cout << "Kan inte plocka upp objektet...\n";
		return false;
	}

	void Human::drop(Object o)
	{
		//find the object and remove it
		for (auto it = objects.begin(); it != objects.end(); ++it)
			if (*it == o){
				if (environment.pick_up(o)){
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
		std::cout << "Human sais: Hej, jag är en människa.\n";
	}
	
	void action()
	{
		//TODO
	}

}
