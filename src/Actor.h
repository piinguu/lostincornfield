#pragma once

#include<string.h>

#include "Direction.h"
#include "Actor.h"
#include "Object.h"

class Actor{
public:
	double hp;
	double void go(Direction dir);
	
	virtual void action();
	virtual std::string name();
	
	virtual double max_hp() = 0;
	virtual std::string type() = 0;
	virtual void fight(Actor) = 0;
	virtual bool pick_up(Object) = 0;
	virtual bool drop(Object) = 0;
	virtual void talk_to(Actor) = 0;
};
