#pragma once

#include "Actor.h"

class Player : public Actor{
	double max_hp() = 100;
	double hold_weight() = 20;
	double hold_volume() = 60;
	
	std::string type() = "player";
	void fight(Actor);
	bool pick_up(Object);
	bool drop(Object);
	void talk_to(Actor);
};
