#pragma once

#include<string.h>
#include<list>
#include<iostream>

#include "Direction.h"
#include "Object.h"
#include "Environment.h"

namespace licf{

	class Actor{
	public:
		double hp, attack_rate;
		Environment * environment;
		std::list<Object *> objects;
		
		void go(Direction dir);
	
		virtual void action();
		virtual std::string name();
		virtual void talk_to(Actor &);
	
		virtual double max_hp() = 0;
		virtual std::string type() = 0;
		virtual void fight(Actor &) = 0;
		virtual bool pick_up(Object &) = 0;
		virtual bool drop(Object &) = 0;
		virtual void talk() = 0;
	};
}
