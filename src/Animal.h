#pragma once

#include "Actor.h"

namespace licf
{
	class Animal : public Actor {
		bool pick_up(Object *);
		bool drop(Object *);
	
		virtual void talk() const = 0;
		virtual double max_hp() const = 0;
		virtual std::string type() const = 0;
		virtual void fight(Actor *) = 0;
		virtual void action() = 0;
	};
}
