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
		std::map< std::string, Direction > dirs;
		
		bool go(std::string);
		bool fight(std::string);
		bool drop(std::string);
		bool pick(std::string);
		bool talk(std::string);
		//bool use(std::string);
		bool quit(std::string);
		bool info(std::string);
		bool help(std::string);
		bool look(std::string);

	public:
		Parser(GameStuff & g);
		
		bool run();
		bool finished();
	};
}

