#include "Painkiller.h"

namespace licf {
	Painkiller::Painkiller() {}

	double Painkiller::weight() {
		return 3;
	}

	double Painkiller::volume() {
		return 2;
	}

	double Painkiller::healing_rate() {
		return 28;
	}

	std::string Painkiller::type() {
		return "painkiller";
	}
}

