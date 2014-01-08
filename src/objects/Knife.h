#pragma once

#include "Weapon.h"

namespace licf {
    class Knife : public Weapon {
    public:
    	Knife();

    	double attack_rate() const;
    	double weight() const;
    	double volume() const;
    	std::string type() const;
    };
}