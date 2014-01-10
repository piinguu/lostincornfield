#pragma once

#include "Actor.h"

namespace licf
{
	class Animal : public Actor {
	public:
		Animal(double max_hp) : Actor(max_hp){}

		bool pick_up(Object *);
		bool drop(Object *);
		std::string name() const { return type(); }
	
		virtual void talk() const = 0;
		virtual double max_hp() const = 0;
		virtual std::string type() const = 0;
		virtual void fight(Actor *) = 0;
		virtual void action() = 0;
	};
}
