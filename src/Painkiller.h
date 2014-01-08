#pragma once

#include "Healing.h"

namespace licf {
    class Painkiller : public Healing {
    public:
    	Painkiller();

    	double weight();
    	double volume();
    	double healing_rate();
    };
}
