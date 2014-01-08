#include "Honey.h"

namespace licf {
	Honey::Honey() {}

	double Honey::weight() {
		return 3;
	}

	double Honey::volume() {
		return 2;
	}

	double Honey::healing_rate() {
		return 28;
	}

	std::string Honey::type() {
		return "honey";
	}
}

