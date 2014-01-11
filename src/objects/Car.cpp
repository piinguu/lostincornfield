#include "Car.h"

#include<sstream>

namespace licf
{
	std::string Car::description() const {
		std::stringstream ss;
		ss << Object::description();
		ss << "Regnr: KFC 938\n";
		return ss.str();
	}
	
	void use(Actor *)
	{
		std::cout << "Du trevar runt i fickorna... har du nyckeln?\n";
	}
}
