#include "Parser.h"



#include<iostream>
#include<string>
#include<sstream>

namespace licf
{
	bool Parser::run()
	{
		std::string s;
		std::getline(std::cin, s);

		std::stringstream ss(s);
		ss >> s;
		
		if (s == "quit")
			return false;
		else if (s != "go"){
			std::cout << " illegal inmatning\n";
			return true;
		}
		
		//read direction
		ss >> s;
		
		if (s == "north")
			go(North);
		else if (s == "south")
			go(South);
		else if (s == "west")
			go(West);
		else if (s == "east")
			go(East);
		else{
			std::cout << "ERROR!!!\n";
			return true;
		}
	}
	
	bool Parser::go(Direction dir){
		gs.player->go(dir);
		std::cout << gs.player->environment->description();
	}
}
