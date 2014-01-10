#pragma once

#include <string>

namespace licf {
	class Actor;
	
    class Object {
    public:
    	virtual std::string description() const;

        virtual double weight() const = 0;
		virtual double volume() const = 0;

		virtual std::string type() const = 0;
		
		virtual void use(Actor *) {}
    };
}
