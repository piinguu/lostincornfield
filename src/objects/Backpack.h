#include "Object.h"

namespace licf
{
	struct Backpack : public Object
	{
		double pack_volume, max_weight;
		
		Backpack(double pv, double mw) : pack_volume(pv), max_weight(mw) {}
		
    	std::string description() const;

        double weight() const { return 1; }
		double volume() const { return 1; }


		std::string type() const { return "ryggsäck"; }
	};
}
