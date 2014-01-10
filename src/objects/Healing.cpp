#include "Healing.h"

#include <sstream>

namespace licf {
		std::string Healing::description() const {
		std::stringstream ss;
		ss << Object::description();
		ss << "Läkekraft: " << healing_rate() << '\n';
		return ss.str();
	}
}
