#pragma once

#include "Healing.h"

namespace licf {
    class Corn : public Healing {
    public:
    	Corn();

    	double healing_rate() const;
    	double weight() const;
    	double volume() const;
    	std::string type() const;
    };
}
