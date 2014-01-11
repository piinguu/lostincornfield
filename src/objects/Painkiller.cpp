#include "Painkiller.h"

namespace licf {
	Painkiller::Painkiller() {}

	double Painkiller::weight() const {
		return 3;
	}

	double Painkiller::volume() const {
		return 2;
	}

	double Painkiller::healing_rate() const {
		return 28;
	}

	std::string Painkiller::type() const {
		return "värktablett";
	}
}

