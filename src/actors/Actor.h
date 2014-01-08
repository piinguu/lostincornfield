#pragma once

#include<string.h>
#include<list>
#include<iostream>

#include "Direction.h"
#include "objects/Object.h"
#include "Environment.h"

namespace licf{

	class Actor{
	public:
		double hp, attack_rate;
		Environment * environment;
		std::list<Object *> objects;
		
		void go(Direction dir);
		bool hitted(const double val);
	
		virtual void action();
		virtual std::string name() const;
		virtual void talk_to(Actor *) const;
	
		virtual double max_hp() const = 0;
		virtual std::string type() const = 0;
		virtual void fight(Actor *) = 0;
		virtual bool pick_up(Object *) = 0;
		virtual bool drop(Object *) = 0;
		virtual void talk() const = 0;
	};
}
