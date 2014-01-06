#include "Weapon.h"

namespace licf {
	Weapon::Weapon() : Object() {}

	Weapon::Weapon(double weight, double volume, double attack_rate) : 
		Object(weight, volume), a(attack_rate) {}

}

