#include "Corn.h"

namespace licf {
	Corn::Corn() {}

	double Corn::weight() const {
		return 3;
	}

	double Corn::volume() const {
		return 2;
	}

	double Corn::healing_rate() const {
		return 28;
	}

	std::string Corn::type() const {
		return "corn";
	}
}

