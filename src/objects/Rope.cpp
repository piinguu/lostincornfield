#include "Rope.h"

namespace licf {
	Rope::Rope() {}

	double Rope::weight() const {
		return 18;
	}

	double Rope::volume() const {
		return 12;
	}

	double Rope::attack_rate() const {
		return 8;
	}

	std::string Rope::type() const {
		return "rep";
	}
}

