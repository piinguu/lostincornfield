#pragma once

#include <iostream>

namespace licf
{
	enum Direction { North, West, South, East };
	
	std::ostream & operator<<(std::ostream & os, const Direction & dir);
}
