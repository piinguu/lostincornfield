#include "Environment.h"

#include<iterator>

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
}
