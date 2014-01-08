#pragma once

#include "env/Environment.h"
#include "actors/Actor.h"
#include "objects/Object.h"
#include "Direction.h"

namespace licf
{
	struct GameStuff
	{
		std::vector<Environment *> map;
		std::vector<Actor *> actors;
		std::vector<Object *> objects;
		Actor * player;
	};
}
