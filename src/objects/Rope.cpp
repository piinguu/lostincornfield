#include "Rope.h"

namespace licf {
	Rope::Rope() {}

	double Rope::weight() {
		return 18;
	}

	double Rope::volume() {
		return 12;
	}

	double Rope::attack_rate() {
		return 8;
	}

	std::string Rope::type() {
		return "rope";
	}
}

