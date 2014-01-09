#include "Environment.h"

namespace licf
{
	class Goal : public Environment
	{
	public:
		std::string description() const;
		void enter(Actor *) {};
		void leave(Actor *) {}
		bool pick_up(Object *) { return false; }
		bool drop(Object *) { return false; }
	};
}
