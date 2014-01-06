#include "Knife.h"

namespace licf {
	Knife::Knife() : Weapon() {}

	Knife::Knife(double weight, double volume, double attack_rate) : 
		Weapon(weight, volume, attack_rate) {}

	double Knife::weight() {
		return w;
	}

	double Knife::volume() {
		return v;
	}

	double Knife::attack_rate() {
		return a;
	}
}

