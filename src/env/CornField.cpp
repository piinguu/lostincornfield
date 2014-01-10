#include "CornField.h"

#include <sstream>

#include "../actors/Actor.h"

namespace licf
{
	std::string CornField::description() const
	{
		std::stringstream ss;
		ss << "Du står mitt i ett majsfält...\n";
		if (objects.size() > 0)
		{
			ss << "Det ligger lite prylar på marken: ";
			for (int i = 0; i < objects.size() - 1; ++i)
				ss << objects[i]->type() << ", ";
			ss << objects[objects.size() - 1]->type() << '\n';

		}
		
		if (actors.size() > 0)
		{
			ss << "Du ser minst en annan levande varelse: ";
			auto it = actors.begin();
			ss << it->second->type();
			for (++it; it != actors.end(); ++it)
				ss << ", " << it->second->type();
			ss << std::endl;
		}
		return ss.str();
	}
	
	bool CornField::pick_up(Object * o)
	{
		objects.push_back(o);
		return true;
	}
	
	bool CornField::drop(Object * o)
	{
		for (auto it = objects.begin(); it != objects.end(); ++it)
			if (*it == o)
			{
				objects.erase(it);
				return true;
			}
		return false;
	}
}
