#pragma once

#include "Weapon.h"

namespace licf {
    class Knife : public Weapon {
    public:
    	Knife();
    	Knife(double weight, double volume);

    	double weight();
    	double volume();
    	double attack_rate();
    };
}