#include "Player.h"

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
}
