#include "Coulter.h"

namespace licf {
	Coulter::Coulter() : Weapon() {}

	Coulter::Coulter(double weight, double volume, double attack_rate) : 
		Weapon(weight, volume, attack_rate) {}

	double Coulter::weight() {
		return w;
	}

	double Coulter::volume() {
		return v;
	}

	double Coulter::attack_rate() {
		return a;
	}
}

