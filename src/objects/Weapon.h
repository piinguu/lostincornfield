#pragma once

#include "Object.h"

namespace licf {
    class Weapon : public Object {
    public:
        virtual double attack_rate() = 0;
        virtual double weight() = 0;
        virtual double volume() = 0;
        virtual std::string type() = 0;
    };
}