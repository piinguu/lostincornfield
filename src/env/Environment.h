#pragma once

#include<map>
#include<vector>
#include<string>

#include "../Direction.h"
#include "../objects/Object.h"
 
namespace licf
{
	class Actor;
	
	class Environment
	{
	protected:
		std::map<Direction, Environment*> neighbors;
		std::vector<Object*> objects;
	public:
		std::map<std::string, Actor*> actors;

		bool add_neighbor(Environment*, Direction);
		std::vector<Direction> directions() const;
		Environment * neighbor(Direction) const;

		void enter(Actor *);
		void leave(Actor *);
		
		Actor * get_actor(std::string name) const;
		Actor * get_actor(int number) const;

		virtual std::string description() const = 0;
		virtual bool pick_up(Object *) = 0;
		virtual bool drop(Object *) = 0;
	};
}
