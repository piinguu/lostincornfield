#pragma once

#include "Healing.h"

namespace licf {
    class Honey : public Healing {
    public:
    	Honey();

    	double weight();
    	double volume();
    	double healing_rate();
    	std::string type();
    };
}
