#include "CornField.h"

#include <sstream>

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
			ss << objects[objects.size() - 1] << '\n';
		}
		
		if (actors.size() > 0)
		{
			ss << "Du ser minst en levande varelse: ";
			for (int i = 0; i < actors.size() - 1; ++i)
				ss << actors[i]->type() << ", ";
			ss << actors[actors.size() - 1] << '\n';
		}
		return ss.str();
	}
	
	void CornField::enter(Actor * a)
	{
		actors.push_back(a);
	}
	
	void CornField::leave(Actor * a)
	{
		for (auto it = actors.begin(); it != actors.end(); ++it)
			if (*it == a)
			{
				actors.erase(it);
				return;
			}
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
