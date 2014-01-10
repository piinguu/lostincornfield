#include "Object.h"

namespace licf
{
	class Car : public Object
	{
		std::string description() const;

		double weight() const { return 1500; }
		double volume() const { return 3000; }

		std::string type() const { return "racerbil"; }
	
		//void use(Actor *);
	};
}
