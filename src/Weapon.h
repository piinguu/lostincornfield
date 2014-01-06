#pragma once

#include "Object.h"

namespace licf {
    class Weapon : public Object {
    public:
    	Weapon();
    	Weapon(double weight, double volume);

        virtual double attack_rate() = 0;

        virtual double weight() = 0;

        virtual double volume() = 0;

    };
}