#pragma once

#include "Actor.h"

namespace licf{
	class Player : public Actor{
		double max_hp() const { return 100; }
		double hold_weight() const { return 20; }
		double hold_volume() const { return 60; }
	
		std::string type() const { return "player"; }
	};
}
