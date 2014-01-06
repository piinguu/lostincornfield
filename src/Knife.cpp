#include "Knife.h"

namespace licf {
	Knife::Knife() : Weapon() {}

	Knife::Knife(double weight, double volume) : Weapon(weight, volume) {}

	double Knife::weight() {
		// TODO
		return w;
	}

	double Knife::volume() {
		// TODO
		return v;
	}

	double Knife::attack_rate() {
		// TODO
		return 0;
	}
}

