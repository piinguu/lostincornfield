#pragma once

#include "Actor.h"

class Animal : public Actor {
	bool pick_up(Object);
	bool drop(Object);
	void talk_to(Actor);
	
	virtual double max_hp() = 0;
	virtual std::string type() = 0;
	virtual void fight(Actor) = 0;
	virtual void action() = 0;
};
