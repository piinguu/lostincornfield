#pragma once

#include "Animal.h"

namespace licf
{
	class Bee : public Animal {
	public:
		Bee() : attack_rate(5) {}
		double max_hp() { return 2; }
		std::string type() { return "bi"; }
	
		void fight(Actor);
		void action();
		void talk();
	};
}
