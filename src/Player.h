#pragma once

#include "Actor.h"

namespace licf{
	class Player : public Actor{
		double max_hp() { return 100; }
		double hold_weight() { return 20; }
		double hold_volume() { return 60; }
	
		std::string type() { return "player"; }
	};
}
