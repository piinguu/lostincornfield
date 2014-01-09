#include "GameStuff.h"

#include <map>
#include <string>

namespace licf
{
	class Parser
	{
		typedef bool (Parser::*funcptr)(std::string);

		GameStuff gs;
		int n;
		std::map< std::string, funcptr > commands;
		
		bool go(std::string);
		bool command(std::string);
		bool fight(std::string);
	public:
		Parser(GameStuff & g);
		
		bool run();
		bool finished();
	};
}

