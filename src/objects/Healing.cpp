#include "Healing.h"

#include <sstream>
#include "../actors/Actor.h"
#include "../env/Environment.h"

namespace licf {
	std::string Healing::description() const {
		std::stringstream ss;
		ss << Object::description();
		ss << "Läkekraft: " << healing_rate() << '\n';
		return ss.str();
	}
	
	void Healing::use(Actor * a)
	{
		a->hp += healing_rate();
		if (a->hp > a->max_hp())
			a->hp = a->max_hp();
		//actor drops to ground
		a->drop(this);
		//remove from environment
		a->environment->drop(this);
		//delete
		delete this;
	}
}
