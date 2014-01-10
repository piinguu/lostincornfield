#include "Player.h"

#include<sstream>

namespace licf
{
	void Player::action()
	{
	
	}
	
	bool Player::hitted(Actor * a)
	{
		std::cout << "Du blir attackerad av en " << a->type() << "!\n";
		
		return Actor::hitted(a);
	}
	
	bool Player::drop(std::string & s)
	{
		for (auto it = objects.begin(); it != objects.end(); ++it)
			if ((*it)->type() == s)
			{
				Object * o = *it;
				return Human::drop(o);
			}
		return false;
	}
	
	std::string Player::get_inventory_description() const
	{
		if (objects.size() == 0)
			return "(tom)";
			
		std::stringstream ss;
		auto it = objects.begin();
		ss << (*it)->type();
		for (++it; it != objects.end(); ++it)
			ss << ", " << (*it)->type();
		return ss.str();
	}
}
