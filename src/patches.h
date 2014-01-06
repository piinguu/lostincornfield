#pragma once

#include "Healing.h"

namespace licf {
    class Patches : public Healing {
    public:
    	Patches();

    	double weight();
    	double volume();
    	double healing_rate();
    };
}