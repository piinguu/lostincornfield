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
		commands.insert( std::make_pair( "använd", &Parser::use ) );
		commands.insert( std::make_pair( "avsluta", &Parser::quit ) );
		commands.insert( std::make_pair( "info", &Parser::info ) );
		commands.insert( std::make_pair( "hjälp", &Parser::help ) );
		commands.insert( std::make_pair( "titta", &Parser::look ) );
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
		return (this->*(it->second))(s);
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
		if (dir == dirs.end())
		{
			std::cout << "Riktning finns inte!\n";
			return true;
		}

		// Save the old environment and try moving the player
		Environment * oldenv = gs.player->environment;
		gs.player->go(dir->second);

		// If the old and new environment are different, the move was succesful
		if (oldenv != gs.player->environment) {
			std::cout << gs.player->environment->description();
			return !finished();
		}

		// The move was not succesful
		std::cout << "Du möter en vägg av majsplantor: 'the way is shut' som döda kungen sa.\n";
		return true;
	}

	bool Parser::fight(std::string s) {
		Actor * a = gs.player->environment->get_actor(s);
		if (a == nullptr)
			std::cout << "Finns ingen sådan person...\n";
		else
		{
			gs.player->fight(a);
			if (gs.player->hp >= 0)
				return true;
			//else, player is dead
			std::cout << "Du orkar inte mer, benen viker sig och allt blir svart...\n";
			std::cout << "Game over\n";
			return false;
		}
		return true;
	}
	
	bool Parser::drop(std::string s)
	{
		if (!gs.player->drop(s))
			std::cout << "Den gubben gick inte...\n";
		return true;
	}
	
	bool Parser::pick(std::string s)
	{
		Object * o = gs.player->environment->get_object(s);
		if (o == nullptr)
		{
			std::cout << "Finns inget sådant objekt\n";
			return true;
		}
		if (!gs.player->pick_up(o))
			std::cout << "Kunde inte plocka upp objektet ifråga\n";
		return true;
	}
	
	bool Parser::talk(std::string){return true;}
	
	bool Parser::quit(std::string)
	{
		return false;
	}
	
	bool Parser::info(std::string)
	{
		std::cout << "--- Info ---\n";
		std::cout << "Hälsa: " << gs.player->hp << "/" << gs.player->max_hp() << std::endl;
		std::cout << "Attackstyrka: " << gs.player->attack_rate << std::endl;
		std::cout << "Saker: " << gs.player->get_inventory_description() << std::endl;
		std::cout << "------------\n";
		return true;
	}
	
	bool Parser::help(std::string)
	{
		std::cout << "--- Hjälp ---";
		std::cout << "\nFöljande kommandon finns tillgängliga:\n";
		auto it = commands.begin();
		std::cout << it->first;
		for (++it; it != commands.end(); ++it)
			std::cout << ", " << it->first;
		std::cout << "\n-------------\n";
		return true;
	}
	
	bool Parser::look(std::string s)
	{
		if (s == "titta")
			std::cout << gs.player->environment->description() << std::endl;
		else
		{
			Object * eo = gs.player->environment->get_object(s);
			Object * po = gs.player->get_object(s);

			if (eo == nullptr && po == nullptr)
				std::cout << "Finns inget sådant objekt.\n";
			else {
				if (eo != nullptr) {
					std::cout << "Objektet finns på marken.\n";
					std::cout << eo->description() << std::endl;
				}
				if (po != nullptr) {
					std::cout << "Objektet finns hos dig.\n";
					std::cout << po->description() << std::endl;
				}
			}
		}
		return true;
	}
	
	bool Parser::use(std::string s)
	{
		Object * o = gs.player->get_object(s);
		if (o == nullptr)
			std::cout << "Finns inte.\n";
		else
			o->use(gs.player);
		return true;
	}

}
