#include "Car.h"

#include<sstream>

namespace licf
{
	std::string Car::description() const {
		std::stringstream ss;
		ss << Object::description();
//		ss << "Attackstyrka: " << attack_rate() << '\n';
		return ss.str();
	}
}
