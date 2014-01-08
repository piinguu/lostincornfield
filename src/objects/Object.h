#pragma once

#include <string>

namespace licf {
    class Object {
    public:

        virtual double weight() = 0;
		virtual double volume() = 0;

		virtual std::string type() = 0;
    };
}
