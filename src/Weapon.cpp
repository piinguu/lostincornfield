#include "Weapon.h"

namespace licf {
	Weapon::Weapon() : Object(), a(0) {}

	Weapon::Weapon(double weight, double volume, double attack_rate) : 
		Object(weight, volume), a(attack_rate) {}

}

