#pragma once

#include<map>
#include<vector>
#include<string>

#include"../Direction.h"
#include"../objects/Object.h"
 
namespace licf
{
	class Actor;
	
	class Environment
	{
	protected:
		std::vector<Object*> objects;
		std::vector<Actor*> actors;
		std::map<Direction, Environment*> neighbors;
	public:
		bool add_neighbor(Environment*, Direction);
		std::vector<Direction> directions() const;
		Environment * neighbor(Direction) const;

		virtual std::string description() const = 0;
		virtual void enter(Actor *) = 0;
		virtual void leave(Actor *) = 0;
		virtual bool pick_up(Object *) = 0;
		virtual bool drop(Object *) = 0;
	};
}
