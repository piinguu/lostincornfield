#pragma once

#include "env/Environment.h"
#include "actors/Actor.h"
#include "actors/Player.h"
#include "objects/Object.h"
#include "Direction.h"

namespace licf
{
	struct GameStuff
	{
		std::vector<Environment *> map;
		std::vector<Actor *> actors;
		std::vector<Object *> objects;
		Player * player;
		
		void cleanup()
		{
			while (!map.empty()) delete map.back(), map.pop_back();
			while (!actors.empty()) delete actors.back(), actors.pop_back();
			while (!objects.empty()) delete objects.back(), objects.pop_back();
		}
	};
}
