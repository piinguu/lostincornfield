#include "Actor.h"

#include <iostream>

namespace licf{
	void Actor::go(Direction dir)
	{
		std::cout << "Actor.go\n";
	}
	
	void Actor::action()
	{
		std::cout << "Det händer... ingenting.\n";
	}
	
	std::string Actor::name()
	{
		return "";
	}

}
