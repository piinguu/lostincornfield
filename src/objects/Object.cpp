#include "Object.h"

#include <sstream>

namespace licf {
	std::string Object::description() const {
		std::stringstream ss;
		ss << type() << ":\n";
		ss << "Vikt: " << weight() << '\n';
		ss << "Volym: " << volume() << '\n';
		return ss.str();
	}
}

