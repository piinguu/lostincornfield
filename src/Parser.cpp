#include "Parser.h"

#include "env/Goal.h"

#include<iostream>
#include<string>
#include<sstream>

namespace licf
{
	Parser::Parser(GameStuff & g) : gs(g), n(0) 
	{
		//std::pair< std::string, bool(*)(std::string) > p = 
		//		std::make_pair("hej", &Parser::command);
		commands.insert( std::make_pair( "go", &Parser::go ) );
		commands.insert( std::make_pair( "fight", &Parser::fight ) );
//		commands.insert( make_pair("hej", &Parser::command) );
	}

	bool Parser::command(std::string s) {
		std::cout << s << '\n';
		return false;
	}

	bool Parser::fight(std::string s) {
		std::cout << '\n' << s << '\n';
		return false;
	}

	bool Parser::run()
	{
		std::string s;
		std::getline(std::cin, s);

		std::stringstream ss(s);
		ss >> s;
		
		//std::cout << "nytt command: " << s << '\n';
		funcptr fp = commands[s];
		std::cout << (this->*fp)(ss.str()) << std::endl;
/*		if (s == "quit")
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
		else
			std::cout << "ERROR!!!\n";
*/
		return !finished();
	}
	
	bool Parser::go(std::string s){
		/*
		Environment * oldenv = gs.player->environment;
		gs.player->go(dir);
		if (oldenv != gs.player->environment)
			std::cout << gs.player->environment->description();
		return oldenv != gs.player->environment;
		*/
		std::cout << '\n' << s << '\n';
		return true;
	}

	bool Parser::finished() {
		if (dynamic_cast<Goal *>(gs.player->environment))
			return true;
		return false;
	}
}
