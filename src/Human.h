#pragma once

#include "Actor.h"

class Human : public Actor {
public:
	void fight(Actor);
	void pick_up(Object);
	void drop(Object);
	void talk_to(Actor);
	
	virtual void action();
	virtual std::string name() = 0;
	
	//inherited from Actor
	virtual double max_hp() = 0;
	virtual std::string type() = 0;
};
