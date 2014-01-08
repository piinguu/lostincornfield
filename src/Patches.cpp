#include "Patches.h"

namespace licf {
	Patches::Patches() {}

	double Patches::weight() {
		return 3;
	}

	double Patches::volume() {
		return 2;
	}

	double Patches::healing_rate() {
		return 28;
	}

	std::string Patches::type() {
		return "patches";
	}
}

