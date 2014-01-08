#pragma once

#include "Object.h"

namespace licf {
    class Weapon : public Object {
    public:
        virtual double attack_rate() const = 0;
        virtual double weight() const = 0;
        virtual double volume() const = 0;
        virtual std::string type() const = 0;
    };
}