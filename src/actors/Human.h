#pragma once

#include "Actor.h"

namespace licf
{
	class Human : public Actor {
		double fist_power;
		
	public:
		Human(double max_hp) : Actor(max_hp), fist_power(10)
		{
			attack_rate = fist_power;
		}
		
		void fight(Actor *);
		bool pick_up(Object *);
		bool drop(Object *);
		void talk() const;
	
		//inherited from Actor
		virtual void action() = 0;
		virtual double max_hp() const = 0;
		virtual std::string type() const = 0;
	};
}
