#include "Knife.h"

namespace licf {
	Knife::Knife() : Weapon() {}

	Knife::Knife(double weight, double volume, double attack_rate) : 
		Weapon(weight, volume, attack_rate) {}

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
		return a;
	}
}

