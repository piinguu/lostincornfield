#include "CornField.h"

#include <sstream>

#include "../actors/Actor.h"

namespace licf
{
	std::string CornField::description() const
	{
		std::stringstream ss;
		ss << "Du står mitt i ett majsfält...\n";
		ss << Environment::description();
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
