#include "Key.h"

#include <sstream>

#include "../actors/Player.h"
#include "../env/Environment.h"

namespace licf {
	void Key::use(Actor * a)
	{
		//start the car if there is a car in the environment where the actor is
		Object * o = a->environment->get_object("bil");
		if (o == nullptr)
		{
			std::cout << "Finns ingenting att använda nyckeln på...\n";
			return;
		}
		Player * p = dynamic_cast<Player*>(a);
		p->winner = true;
		return;
	}
}
