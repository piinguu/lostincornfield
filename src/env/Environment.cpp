#include "Environment.h"

#include<iterator>
#include<sstream>

#include "../actors/Actor.h"
#include "../actors/Player.h"

namespace licf
{
	typedef std::pair<Direction, Environment*> DirEnv;

	bool Environment::add_neighbor(Environment* e, Direction d)
	{
		std::pair<std::map<Direction, Environment*>::iterator, bool> p = 
				neighbors.insert( DirEnv(d, e));
		return p.second;
	}

	std::vector<Direction> Environment::directions() const
	{
		std::vector<Direction> ret;
		for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
			ret.push_back(it->first);
			
		return ret;
	}
	
	Environment * Environment::neighbor(Direction d) const
	{
		auto it = neighbors.find(d);
		if (it == neighbors.end())
			return nullptr;
		return it->second;
	}
	
	void Environment::enter(Actor * a)
	{
		actors.insert( std::make_pair(a->name(), a));
	}
	
	void Environment::leave(Actor * a)
	{
		auto it = actors.find(a->name());
		if (it == actors.end())
			return;
		actors.erase(it);
	}
	
	Actor * Environment::get_actor(const std::string & name) const
	{
		auto it = actors.find(name);
		return it == actors.end() ? nullptr : it->second;
	}
	
	Actor * Environment::get_actor(int number) const
	{
		auto it = actors.begin();
		std::advance(it, number % actors.size());
		return it->second;
	}
	
	Object * Environment::get_object(const std::string & name) const
	{
		for (int i = 0; i < objects.size(); ++i)
			if (objects[i]->type() == name)
				return objects[i];
		return nullptr;
	}

	std::string Environment::description() const {
		std::stringstream ss;
		std::vector<Direction> dirs = directions();
		ss << "Möjliga vägar att välja mellan: ";
		// TODO: detta skriver ut ett tal (0,1,2,3) och inte motsvarande enumvärde.
		for (int i = 0; i < dirs.size() - 1; ++i)
			ss << dirs[i] << ", ";
		ss << dirs[dirs.size() - 1] << '\n';

		if (objects.size() > 0)
		{
			ss << "Det ligger lite prylar på marken: ";
			for (int i = 0; i < objects.size() - 1; ++i)
				ss << objects[i]->type() << ", ";
			ss << objects[objects.size() - 1]->type() << '\n';
		}
		
		if (actors.size() > 1)
		{
			ss << "Du ser minst en annan levande varelse: ";
			auto it = actors.begin();
			
			if (dynamic_cast<Player*>(it->second) != nullptr)
				++it;
			
			ss << it->second->type();
			for (++it; it != actors.end(); ++it)
				if (dynamic_cast<Player*>(it->second) == nullptr)
					ss << ", " << it->second->type();
			ss << std::endl;
		}
		return ss.str();
	}


}
