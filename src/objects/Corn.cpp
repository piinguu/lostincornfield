#include "Corn.h"

namespace licf {
	Corn::Corn() {}

	double Corn::weight() {
		return 3;
	}

	double Corn::volume() {
		return 2;
	}

	double Corn::healing_rate() {
		return 28;
	}

	std::string Corn::type() {
		return "corn";
	}
}

