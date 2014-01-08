#pragma once

#include "Weapon.h"

namespace licf {
    class Coulter : public Weapon {
    public:
    	Coulter();

    	double attack_rate();
    	double weight();
    	double volume();
    	std::string type();
    };
}