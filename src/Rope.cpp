#include "Rope.h"

namespace licf {
	Rope::Rope() : Weapon() {}

	Rope::Rope(double weight, double volume, double attack_rate) : 
		Weapon(weight, volume, attack_rate) {}

	double Rope::weight() {
		return w;
	}

	double Rope::volume() {
		return v;
	}

	double Rope::attack_rate() {
		return a;
	}
}

