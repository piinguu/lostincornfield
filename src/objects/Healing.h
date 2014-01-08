#pragma once

#include "Object.h"

namespace licf {
	class Healing : public Object {
        virtual double weight() const = 0;
        virtual double volume() const = 0;

        virtual double healing_rate() const = 0;

        virtual std::string type() const = 0;
	};
}
