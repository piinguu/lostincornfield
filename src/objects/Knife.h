#pragma once

#include "Weapon.h"

namespace licf {
    class Knife : public Weapon {
    public:
    	Knife();

    	double attack_rate();
    	double weight();
    	double volume();
    	std::string type();
    };
}