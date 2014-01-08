#pragma once

#include "Healing.h"

namespace licf {
    class Painkiller : public Healing {
    public:
    	Painkiller();

    	double weight() const;
    	double volume() const;
    	double healing_rate() const;
    	std::string type() const;
    };
}
