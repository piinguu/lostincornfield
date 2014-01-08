#pragma once

#include "Weapon.h"

namespace licf {
    class Rope : public Weapon {
    public:
    	Rope();

    	double weight() const;
    	double volume() const;
    	double attack_rate() const;
    	std::string type() const;
    };
}