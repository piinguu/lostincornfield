#include "Object.h"

namespace licf {
	class Key : public Object {
	public:
        double weight() const { return 2; }
		double volume() const { return 1; }

		std::string type() const { return "nyckel"; }

		//void use(Actor *);
	};
}
