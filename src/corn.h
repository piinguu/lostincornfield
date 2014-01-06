#pragma once

#include "Healing.h"

namespace licf {
    class Corn : public Healing {
    public:
    	Corn();

    	double weight();
    	double volume();
    	double healing_rate();
    };
}