#pragma once

#include "Human.h"

namespace licf{
	class Player : public Human{
		double weight;
		double volume;
		bool backpack;
	public:
		Player() : Human(100), weight(0), volume(0) backpack(false) {}
		double max_hp() const { return 100; }
		double hold_weight() const { return 20; }
		double hold_volume() const { return 60; }
	
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
