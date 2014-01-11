#include "Player.h"

#include "../objects/Backpack.h"

#include<sstream>
#include <iostream>

namespace licf
{
	void Player::action()
	{
		
	}
	
	bool Player::hitted(Actor * a)
	{
		double prev_hp = hp;
		std::cout << "Du blir attackerad av en " << a->type()  << "! ";
		
		bool ret = Actor::hitted(a);
		
		if (hp > 0)
			std::cout << "Du tar " << (prev_hp - hp) << " skada\n";
		
		return ret;
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

					if (o->type() == "ryggsäck") {
						hvolume -= dynamic_cast<Backpack*>(o)->pack_volume;
						hweight -= dynamic_cast<Backpack*>(o)->max_weight;
						backpack = false;
					}
				}
				return success;
			}
		return false;
	}

	bool Player::pick_up(Object * o) {
		// Did we pick up a backpack?
		if (o->type() == "ryggsäck") {
			hweight += dynamic_cast<Backpack*>(o)->pack_volume;
			hvolume += dynamic_cast<Backpack*>(o)->max_weight;
			backpack = true;
		}

		// If player can pick up item
		if ((backpack || objects.size() < 2) &&
			weight + o->weight() <= hold_weight() &&
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
