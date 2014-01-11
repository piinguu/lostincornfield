#include "Coulter.h"

namespace licf {
	Coulter::Coulter() {}

	double Coulter::weight() const {
		return 25;
	}

	double Coulter::volume() const {
		return 10;
	}

	double Coulter::attack_rate() const {
		return 42;
	}

	std::string Coulter::type() const {
		return "lie";
	}
}

