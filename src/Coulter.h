#pragma once

#include "Weapon.h"

namespace licf {
    class Coulter : public Weapon {
    public:
    	Coulter();
    	Coulter(double weight, double volume, double attack_rate);

    	double weight();
    	double volume();
    	double attack_rate();
    };
}