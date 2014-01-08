#include "Coulter.h"

namespace licf {
	Coulter::Coulter() {}

	double Coulter::weight() {
		return 25;
	}

	double Coulter::volume() {
		return 10;
	}

	double Coulter::attack_rate() {
		return 42;
	}

	std::string Coulter::type() {
		return "coulter";
	}
}

