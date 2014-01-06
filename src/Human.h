#pragma once

#include "Actor.h"

namespace licf
{
	class Human : public Actor {
		double fist_power;
	public:
		Human() : fist_power(10) {};
		
		void fight(Actor &);
		bool pick_up(Object *);
		bool drop(Object *);
		void talk();
	
		virtual void action();
		virtual std::string name() = 0;
	
		//inherited from Actor
		virtual double max_hp() = 0;
		virtual std::string type() = 0;
	};
}
