#include "Game.h"

#include<iostream>

using namespace licf;

void generate_map(GameStuff & gs);
void print_introduction();

int main()
{
	//initialize
	GameStuff gs;
	generate_map(gs);
	
	Parser p(gs);
	
	//run the game
	print_introduction();
	while (p.run())
		for (auto it = gs.actors.begin(); it != gs.actors.end(); ++it)
			if ((*it)->hp > 0)
				(*it)->action();
	
	//wrap up
	gs.cleanup();	
	return 0;
}

void generate_map(GameStuff & gs)
{
	Environment * start = new CornField();
	Environment * cf1 = new CornField();
	Environment * end = new CornField();
	Environment * goal = new Goal();
	gs.map.push_back(start);
	gs.map.push_back(cf1);
	gs.map.push_back(end);
	gs.map.push_back(goal);
	
	Object * h = new Honey();
	gs.objects.push_back(h);
	
	Actor * farmer = new Farmer("Pelle"); //TODO: this causes memory leak. WHYYY??
	Actor * bee = new Bee();
	gs.player = new Player();
	gs.actors.push_back(farmer);
	gs.actors.push_back(gs.player);
	gs.actors.push_back(bee);
	
	//"doors"
	start->add_neighbor(cf1, East);
	cf1->add_neighbor(start, West);
	
	end->add_neighbor(cf1, South);
	cf1->add_neighbor(end, North);

	end->add_neighbor(goal, East);
	
	start->pick_up(h);
	
	start->enter(gs.player);
	gs.player->environment = start;
	
	cf1->enter(farmer);
	farmer->environment = cf1;
	
	cf1->enter(bee);
	bee->environment = cf1;
}

void print_introduction()
{
	//general introduction
	std::cout 	<< "Du vaknar upp, och har ingen aning om var \n"
				<< "du befinner. Du ligger på rygg, och ser en \n"
				<< "klarblå himmel, och några höga, märkliga \n"
				<< "träd... Vid närmare inspektion är det inte \n"
				<< "träd utan majsplantor: du befinner dig mitt \n"
				<< "i en majsodling med tre meter hög vegetation \n"
				<< "runtomkring dig. Hur ska du hitta hem?\n\n";
	//how to win
	std::cout 	<< "För att vinna, ta dig till närmaste väg och\n"
				<< "hoppas på att en bil råkar passera (det händer\n"
				<< "titt som tätt.\n";
	//commands
	std::cout	<< "För att förflytta dig i spelet, ge kommandot\n"
				<< "'gå norr' för att gå norrut etc. Interagera\n"
				<< "med objekt genom 'plocka honung', 'kasta plåster'\n"
				<< "etc., och med personer genom t.ex. 'anfall orm'\n"
				<< "eller 'prata bonde'.\n";
	//final wishing good luck
	std::cout	<< "Lycka till, och kom ihåg att i ett majsfält finns\n"
				<< "det sällan någon som hör dig ropa...\n\n";
}
