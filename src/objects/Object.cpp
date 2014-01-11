#include "Object.h"

#include <sstream>
#include <iostream>

namespace licf {
	std::string Object::description() const {
		std::stringstream ss;
		ss << type() << ":\n";
		ss << "Vikt: " << weight() << '\n';
		ss << "Volym: " << volume() << '\n';
		return ss.str();
	}
	
	void Object::use(Actor *)
	{
		std::cout << "Du försöker och försöker, men förstår inte hur du ska "
					<< "använda den här prylen.\n";
	}
}

