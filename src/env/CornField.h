#include "Environment.h"

namespace licf
{
	class CornField : public Environment
	{
	public:
		std::string description() const;
		bool pick_up(Object *);
		bool drop(Object *);
	};
}
