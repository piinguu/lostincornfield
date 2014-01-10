#pragma once

#include "Object.h"

namespace licf {
	class Healing : public Object {
		std::string description() const;
		
        virtual double weight() const = 0;
        virtual double volume() const = 0;

        virtual double healing_rate() const = 0;

        virtual std::string type() const = 0;
        
        void use(Actor *);
	};
}
