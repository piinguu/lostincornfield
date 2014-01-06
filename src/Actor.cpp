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
	
	std::string Actor::name()
	{
		return "";
	}
	
	void Actor::talk_to(Actor &)
	{
		std::cout << "(silence)\n";
	}

}
