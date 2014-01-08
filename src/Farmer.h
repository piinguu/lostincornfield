#pragma once

#include "Human.h"

namespace licf
{
	class Farmer : public Human {
		std::string _name;
	
	public:
		Farmer(const std::string & name) : _name(name) {};

		double max_hp() const { return 100; }
		std::string type() const { return "farmer"; }
		std::string name() const { return _name; };
	
		void action();
	};
}
