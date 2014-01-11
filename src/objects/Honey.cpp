#include "Honey.h"

namespace licf {
	Honey::Honey() {}

	double Honey::weight() const {
		return 3;
	}

	double Honey::volume() const {
		return 2;
	}

	double Honey::healing_rate() const {
		return 28;
	}

	std::string Honey::type() const {
		return "dunderhonung";
	}
}

