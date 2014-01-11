#include "Patches.h"

namespace licf {
	Patches::Patches() {}

	double Patches::weight() const {
		return 3;
	}

	double Patches::volume() const {
		return 2;
	}

	double Patches::healing_rate() const {
		return 28;
	}

	std::string Patches::type() const {
		return "plåster";
	}
}

