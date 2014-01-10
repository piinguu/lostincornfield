#include "Healing.h"

#include <sstream>

namespace licf {
		std::string Healing::description() const {
		std::stringstream ss;
		ss << type() << ":\n";
		ss << "Vikt: " << weight() << '\n';
		ss << "Volym: " << volume() << '\n';
		ss << "Läkekraft: " << healing_rate() << '\n';
		return ss.str();
	}
}
