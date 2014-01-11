#include "Backpack.h"

#include <sstream>

namespace licf
{
	std::string Backpack::description() const
	{
		std::stringstream ss;
		
		ss << "--- Ryggsäck ---\n";
		ss << "Packvolym: " << pack_volume << std::endl;
		ss << "Maxvikt: " << max_weight << std::endl;
		
		return ss.str();
	}
}
