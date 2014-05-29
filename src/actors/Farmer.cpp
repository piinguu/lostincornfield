#include "Farmer.h"

#include<iostream>

#include "Bee.h"
#include "../env/Environment.h"
#include "../objects/Honey.h"

namespace licf
{
	void Farmer::action()
	{
		//If there is at least one bee in the same environment, farmer will try to produce honey
		int bees = 0;
		for (auto it = environment->actors.begin(); it != environment->actors.end(); ++it)
		{
			if (dynamic_cast<Bee*>(it->second) != nullptr)
			{
				++bees;
			}
		}
		if (bees)
		{
			Honey * h = new Honey();
			environment->pick_up(h);			
		}		
	}
}
