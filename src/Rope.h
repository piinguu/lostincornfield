#pragma once

#include "Weapon.h"

namespace licf {
    class Rope : public Weapon {
    public:
    	Rope();
    	Rope(double weight, double volume, double attack_rate);

    	double weight();
    	double volume();
    	double attack_rate();
    };
}