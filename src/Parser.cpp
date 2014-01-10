#include "Parser.h"

#include "env/Goal.h"
#include "actors/Actor.h"
#include "actors/Player.h"

#include<iostream>
#include<string>
#include<sstream>

namespace licf
{
	Parser::Parser(GameStuff & g) : gs(g), n(0) 
	{
		// Fill map containing all valid directions
		dirs.insert( std::make_pair( "ost", East ) );
		dirs.insert( std::make_pair( "väst", West ) );
		dirs.insert( std::make_pair( "nord", North ) );
		dirs.insert( std::make_pair( "syd", South ) );
		dirs.insert( std::make_pair( "öster", East ) );
		dirs.insert( std::make_pair( "väster", West ) );
		dirs.insert( std::make_pair( "norr", North ) );
		dirs.insert( std::make_pair( "söder", South ) );

		// Fill the map containing commands give each a function pointer
		commands.insert( std::make_pair( "gå", &Parser::go ) );		
		commands.insert( std::make_pair( "flytta", &Parser::go ) );
		commands.insert( std::make_pair( "anfall", &Parser::fight ) );
		commands.insert( std::make_pair( "attackera", &Parser::fight ) );
		commands.insert( std::make_pair( "plocka", &Parser::pick ) );
		commands.insert( std::make_pair( "kasta", &Parser::drop ) );
		commands.insert( std::make_pair( "prata", &Parser::talk ) );
		//commands.insert( std::make_pair( "använd", &Parser::use ) );
	}

	bool Parser::run()
	{
		std::cout << "> ";
		std::string s;
		std::getline(std::cin, s); // read a line from shell

		std::stringstream ss(s); 
		ss >> s; // read first word from line
		
		// Find the command given
		std::map< std::string, funcptr >::iterator it = commands.find(s);
		// If it doesn't exist, let the player try again.
		if (it == commands.end()) {
			std::cout << "Felaktigt kommando!\n";
			return true;
		}

		// Call the function corresponding to the command. TODO: this allows only two-word commands
		ss >> s;
		(this->*(it->second))(s);

		// Check if the player has won the game.
		return !finished();
	}

	/**
	 * Check if the player has won the game.
	 * Return true if the game is won, false otherwise.
	 */
	bool Parser::finished() {
		// TODO: update with winning criteria
		if (dynamic_cast<Goal *>(gs.player->environment))
			return true;
		return false;
	}
	
	bool Parser::go(std::string s){
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
		Actor * a = gs.player->environment->get_actor(s);
		if (a == nullptr)
			std::cout << "Finns ingen sådan person...\n";
		else
			gs.player->fight(a);
		// TODO:
		std::cout << '\n' << s << '\n';
		return false;
	}
	
	bool Parser::drop(std::string s)
	{
		bool ret = gs.player->drop(s);
		if (!ret)
			std::cout << "Den gubben gick inte...\n";
		return ret;
	}
	
	bool Parser::pick(std::string s)
	{
		Object * o = gs.player->environment->get_object(s);
		if (o == nullptr)
		{	
			std::cout << "Finns inget sådant objekt\n";
			return false;
		}
		bool ret = gs.player->pick_up(o);
		if (!ret)
			std::cout << "Kunde inte plocka upp objektet ifråga\n";
		return ret;
	}
	
	bool Parser::talk(std::string){return false;}
		
}
