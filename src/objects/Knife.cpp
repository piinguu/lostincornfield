#include "Knife.h"

namespace licf {
	Knife::Knife() {}

	double Knife::weight() const {
		return 3;
	}

	double Knife::volume() const {
		return 2;
	}

	double Knife::attack_rate() const {
		return 28;
	}

	std::string Knife::type() const {
		return "knife";
	}
}

