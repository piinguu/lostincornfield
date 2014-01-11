#include "Direction.h"

namespace licf
{
	std::ostream & operator<<(std::ostream & os, const Direction & dir)
	{
		if (dir == North)
			os << "nord";
		else if (dir == West)
			os << "väst";
		else if (dir == South)
			os << "syd";
		else if (dir == East)
			os << "öst";
	
		return os;
	}
}
