#include "Object.h"

namespace licf {
	class Key : public Object {
	public:
		std::string description() const;

        double weight() const { return 2; }
		double volume() const { return 1; }

		std::string type() const { return "key"; }

		void use(Actor *);
	};
}