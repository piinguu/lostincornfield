#include "Farmer.h"

#include<iostream>

#include "Bee.h"
#include "../env/Environment.h"

namespace licf
{
	void Farmer::action()
	{
		//If there is at least one bee in the same environment, farmer will try to produce honey
		int bees = 0;
		for (auto it = environment->actors.begin(); it != environment->actors.end(); ++it)
		{
			if (dynamic_cast<Bee*>(*it) != nullptr)
			{
				++bees;
			}
		}
		//TODO: create honey if bees > 1?
		
	}
}
