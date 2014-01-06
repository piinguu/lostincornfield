#pragma once

#include<string.h>
#include<list>

#include "Direction.h"
#include "Actor.h"
#include "Object.h"
#include "Environment.h"

namespace licf{
	class Actor{
	public:
		double hp;
		Environment environment;
		list<Objects> objects;
		
		void go(Direction dir);
	
		virtual void action();
		virtual std::string name();
		virtual void talk_to(Actor);
	
		virtual double max_hp() = 0;
		virtual std::string type() = 0;
		virtual void fight(Actor) = 0;
		virtual bool pick_up(Objects) = 0;
		virtual bool drop(Objects) = 0;
		virtual void talk() = 0;
	};
}
