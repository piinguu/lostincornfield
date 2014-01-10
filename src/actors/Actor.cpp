#include "Actor.h"

#include "../env/Environment.h"

namespace licf{
	void Actor::go(Direction dir)
	{
		std::cout << "Actor: Going " << dir << std::endl;
		//move to new environment in given direction, if possible
		Environment * env = environment->neighbor(dir);
		if (env == nullptr)
			return;
		
		environment->leave(this);
		environment = env;
		environment->enter(this);
	}
	
	void Actor::go_random()
	{
		std::vector<Direction> directions = environment->directions();
		go(directions[next_rand(directions.size())]);
	}
	
	/* Default action : nothing happens. Should be overridden by any class that can perform an action */
	void Actor::action() {}
	
	std::string Actor::name() const
	{
		return "";
	}
	
	void Actor::talk_to(Actor *) const
	{
		std::cout << "(silence)\n";
	}
	
	bool Actor::hitted(Actor * a)
	{
		hp -= a->attack_rate;
		if (hp > 0)
			return true;
		//else, actor is dead
		environment->leave(this);
		return false;
	}
	
	int Actor::next_rand(int limit)
	{
		return rand() % limit;
	}
	
	Actor * Actor::random_actor()
	{
		return environment->get_actor(next_rand(RAND_MAX));
	}
}
