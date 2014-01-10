#include "Weapon.h"

#include <sstream>

namespace licf {
	std::string Weapon::description() const {
		std::stringstream ss;
		ss << type() << ":\n";
		ss << "Vikt: " << weight() << '\n';
		ss << "Volym: " << volume() << '\n';
		ss << "Attackstyrka: " << attack_rate() << '\n';
		return ss.str();
	}
}

