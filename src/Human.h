#pragma once

#include "Actor.h"

namespace licf
{
	class Human : public Actor {
		double fist_power = 10;
	public:
		void fight(Actor);
		void pick_up(Object);
		void drop(Object);
		void talk(Actor);
	
		virtual void action();
		virtual std::string name() = 0;
	
		//inherited from Actor
		virtual double max_hp() = 0;
		virtual std::string type() = 0;
	};
}
