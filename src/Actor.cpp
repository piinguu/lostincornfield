#include "Actor.h"

namespace licf{
	void Actor::go(Direction dir)
	{
		std::cout << "Actor: Going " << dir << std::endl;
		//move to new environment in given direction, if possible
		environment = environment->neighbor(dir);
	}
	
	void Actor::action()
	{
		std::cout << "Det händer... ingenting.\n";
	}
	
	std::string Actor::name() const
	{
		return "";
	}
	
	void Actor::talk_to(Actor *) const
	{
		std::cout << "(silence)\n";
	}
	
	bool Actor::hitted(double val)
	{
		hp -= val;
		if (hp > 0)
			return true;
		//else, actor is dead
		environment->leave(*this);
		return false;
	}

}
