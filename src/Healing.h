#pragma once

#include "Object.h"

namespace licf {
	class Healing : public Object {
        virtual double weight() = 0;
        virtual double volume() = 0;

        virtual double healing_rate() = 0;
	};
}
