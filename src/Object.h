#pragma once

namespace licf {
    class Object {
    public:
    	Object();
    	Object(double weight, double volume);

        double weight() { return w; }
		double volume() { return v; }

    protected:
    	double w;
    	double v;
    };
}
