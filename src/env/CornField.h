#include "Environment.h"

namespace licf
{
	class CornField : public Environment
	{
	public:
		std::string description() const;
		void enter(Actor *);
		void leave(Actor *);
		bool pick_up(Object *);
		bool drop(Object *);
	};
}
