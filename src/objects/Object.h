#pragma once

#include <string>

namespace licf {
    class Object {
    public:
    	virtual std::string description() const = 0;

        virtual double weight() const = 0;
		virtual double volume() const = 0;

		virtual std::string type() const = 0;
		
		//virtual void use(Actor *) = 0;
    };
}
