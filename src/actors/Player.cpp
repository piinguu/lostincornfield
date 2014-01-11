#include "Player.h"

#include<sstream>
#include <iostream>

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
				bool success = Human::drop(o);
				if (success) {
					weight -= o->weight();
					volume -= o->volume();
				}
				return success;
			}
		return false;
	}

	bool Player::pick_up(Object * o) {
		// If player can pick up item
		if (weight + o->weight() <= hold_weight() &&
			volume + o->volume() <= hold_volume())
		{
			// If item is picked up
			bool success = Human::pick_up(o);
			if (success) {
				weight += o->weight();
				volume += o->volume();
			}
			else {
			}
			return success;
		}
		std::cout << "Du har inte tillräckligt med plats för detta objekt.\n";
		std::cout << "Använd eller släng något objekt innan du kan ta detta.\n";
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
	
	Object * Player::get_object(const std::string & s) const
	{
		for (auto it = objects.begin(); it != objects.end(); ++it)
			if ((*it)->type() == s)
				return *it;
		return nullptr;
	}
}
