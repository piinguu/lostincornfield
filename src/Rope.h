#pragma once

#include "Weapon.h"

namespace licf {
    class Rope : public Weapon {
    public:
    	Rope();

    	double weight();
    	double volume();
    	double attack_rate();
    };
}