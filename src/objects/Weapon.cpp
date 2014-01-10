#include "Weapon.h"

#include <sstream>

namespace licf {
	std::string Weapon::description() const {
		std::stringstream ss;
		ss << Object::description();
		ss << "Attackstyrka: " << attack_rate() << '\n';
		return ss.str();
	}
}

