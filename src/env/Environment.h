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
		~Environment(){while (!objects.empty()) delete objects.back(), objects.pop_back();}
		std::map<std::string, Actor*> actors;

		bool add_neighbor(Environment*, Direction);
		std::vector<Direction> directions() const;
		Environment * neighbor(Direction) const;

		void enter(Actor *);
		void leave(Actor *);
		
		Actor * get_actor(const std::string & name) const;
		Actor * get_actor(int number) const;
		Object * get_object(const std::string & name) const;

		virtual std::string description() const;
		virtual bool pick_up(Object *) = 0;
		virtual bool drop(Object *) = 0;
	};
}
