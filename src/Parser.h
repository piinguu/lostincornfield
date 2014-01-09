#include "GameStuff.h"

namespace licf
{
	class Parser
	{
		GameStuff gs;
		int n;
		
		bool go(Direction);
	public:
		Parser(GameStuff & g) : gs(g), n(0) {}
		
		bool run();
		bool finished();
	};
}

