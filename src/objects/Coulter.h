#pragma once

#include "Weapon.h"

namespace licf {
    class Coulter : public Weapon {
    public:
    	Coulter();

    	double attack_rate() const;
    	double weight() const;
    	double volume() const;
    	std::string type() const;
    };
}