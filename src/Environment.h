#pragma once

#include<vector>
#include<string>

#include"Direction.h"
//#include"Actor.h"
#include"objects/Object.h"
 
namespace licf
{
	class Actor;
	
	class Environment
	{
	public:
		virtual std::vector<Environment*> directions() = 0;
		virtual Environment * neighbor(Direction) = 0;
		virtual std::string description() = 0;
		virtual void enter(Actor &) = 0;
		virtual void leave(Actor &) = 0;
		virtual bool pick_up(Object *) = 0;
		virtual bool drop(Object *) = 0;
	};
}
