#pragma once

#include "Human.h"

namespace licf{
	class Player : public Human{
	public:
		bool winner;
		Player() : Human(100), winner(false) {}
		
		double max_hp() const { return 100; }
		double hold_weight() const { return 20; }
		double hold_volume() const { return 60; }
	
		std::string type() const { return "player"; }
		
		void action();
		bool drop(std::string &);
		
		std::string name() const { return "jag"; }
		std::string get_inventory_description() const;
		Object * get_object(const std::string &) const;
		
		//overriding Actor
		bool hitted(Actor *);
	};
}
