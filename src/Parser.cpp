#include "Parser.h"

#include "env/Goal.h"

#include<iostream>
#include<string>
#include<sstream>

namespace licf
{
	Parser::Parser(GameStuff & g) : gs(g), n(0) 
	{
		// Fill map containing all valid directions
		dirs.insert( std::make_pair( "east", East ) );
		dirs.insert( std::make_pair( "west", West ) );
		dirs.insert( std::make_pair( "north", North ) );
		dirs.insert( std::make_pair( "south", South ) );

		// Fill the map containing commands give each a function pointer
		commands.insert( std::make_pair( "go", &Parser::go ) );
		commands.insert( std::make_pair( "gå", &Parser::go ) );
		commands.insert( std::make_pair( "fight", &Parser::fight ) );
	}

	bool Parser::run()
	{
		std::string s;
		std::getline(std::cin, s); // read a line from shell

		std::stringstream ss(s); 
		ss >> s; // read first word from line
		
		funcptr fp = commands[s];
		std::cout << (this->*fp)(ss.str()) << std::endl;
/*		if (s == "quit")
			return false;
		else if (s != "go"){
			std::cout << " illegal inmatning\n";
			return true;
		}
		
*/
		return !finished();
	}

	/**
	 * Check if the player has won the game.
	 * Return true if the game is won, false otherwise.
	 */
	bool Parser::finished() {
		if (dynamic_cast<Goal *>(gs.player->environment))
			return true;
		return false;
	}
	
	bool Parser::go(std::string s){
		std::stringstream ss(s);
		ss >> s; // overwrite s with the first word in the command
		ss >> s; // s will now containg the direction to move

		// Find the corresponding direction from Direction enum.
		std::map< std::string, Direction >::iterator dir = dirs.find(s);
		// If it doesn't exist, return
		if (dir == dirs.end()) {
			std::cout << "Riktning finns inte!\n";
			return false;
		}

		// Save the old environment and try moving the player
		Environment * oldenv = gs.player->environment;
		gs.player->go(dir->second);

		// If the old and new environment are different, the move was succesful
		if (oldenv != gs.player->environment) {
			std::cout << gs.player->environment->description();
			return true;
		}

		// The move was not succesful
		// TODO: write something to std::cout??
		return false;
	}

	bool Parser::fight(std::string s) {
		// TODO:
		std::cout << '\n' << s << '\n';
		return false;
	}
}
