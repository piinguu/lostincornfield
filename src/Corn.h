#pragma once

#include "Healing.h"

namespace licf {
    class Corn : public Healing {
    public:
    	Corn();

    	double healing_rate();
    	double weight();
    	double volume();
    	std::string type();
    };
}
