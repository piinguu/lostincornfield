#pragma once

#include "Healing.h"

namespace licf {
    class Honey : public Healing {
    public:
    	Honey();

    	double weight() const;
    	double volume() const;
    	double healing_rate() const;
    	std::string type() const;
    };
}
