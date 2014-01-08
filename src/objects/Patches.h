#pragma once

#include "Healing.h"

namespace licf {
    class Patches : public Healing {
    public:
    	Patches();

    	double weight() const;
    	double volume() const;
    	double healing_rate() const;
    	std::string type() const;
    };
}
