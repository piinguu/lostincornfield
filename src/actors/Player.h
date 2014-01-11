#pragma once

#include "Human.h"

namespace licf{
	class Player : public Human{
		double weight, volume, hweight, hvolume;
		bool backpack;
	public:
		bool winner;
		Player() : Human(100), weight(0), volume(0), backpack(false),
					winner(false), hweight(10), hvolume(30) {}

		double max_hp() const { return 100; }
		double hold_weight() const { return hweight; }
		double hold_volume() const { return hvolume; }
	
		std::string type() const { return "player"; }
		
		void action();
		bool drop(std::string &);
		bool pick_up(Object *);
		
		std::string name() const { return "jag"; }
		std::string get_inventory_description() const;
		Object * get_object(const std::string &) const;
		
		//overriding Actor
		bool hitted(Actor *);
	};
}
