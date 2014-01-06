#pragma once

namespace licf {
    class Object {
    public:
    	Object();
    	Object(double weight, double volume);

        virtual double weight() = 0;

        virtual double volume() = 0;

    protected:
    	double w;
    	double v;
    };
}