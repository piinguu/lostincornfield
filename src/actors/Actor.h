#pragma once

#include<string.h>
#include<list>
#include<iostream>
#include<stdlib.h>
#include<time.h>

#include "../Direction.h"
#include "../objects/Object.h"

namespace licf{
	class Environment;
	
	class Actor{
	protected:
		std::list<Object *> objects;
		
		int next_rand(int limit);

	public:
		~Actor(){while (!objects.empty()) delete objects.back(), objects.pop_back();}
		Environment * environment;
		double hp, attack_rate;
		
		Actor(double max_hp) : hp(max_hp)
		{
			//initialize randomizer
			srand(time(NULL));
		}
		
		void go(Direction dir);
		void go_random();
		
		Actor * random_actor();
		
		virtual bool hitted(Actor *);
		virtual void action();
		virtual std::string name() const = 0;
		virtual void talk_to(Actor *) const;
	
		virtual double max_hp() const = 0;
		virtual std::string type() const = 0;
		virtual void fight(Actor *) = 0;
		virtual bool pick_up(Object *) = 0;
		virtual bool drop(Object *) = 0;
		virtual void talk() const = 0;
	};
	std::ostream & operator<<(std::ostream & os, const Actor * actor);
}
