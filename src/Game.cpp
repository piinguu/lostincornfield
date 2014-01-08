#include "Game.h"

#include<iostream>
#include<vector>


using namespace licf;

void generate_map(GameStuff & gs)
{
	Environment * start = new CornField();
	Environment * cf1 = new CornField();
	Environment * end = new CornField();
	gs.map.push_back(start);
	gs.map.push_back(cf1);
	gs.map.push_back(end);
	
	Object * h = new Honey();
	gs.objects.push_back(h);
	
	Actor * farmer = new Farmer("Pelle");
	gs.player = new Player();
	gs.actors.push_back(farmer);
	gs.actors.push_back(gs.player);
	
	//"doors"
	start->add_neighbor(cf1, East);
	cf1->add_neighbor(start, West);
	
	end->add_neighbor(cf1, South);
	cf1->add_neighbor(end, North);
	
	start->pick_up(h);
	
	start->enter(gs.player);
	gs.player->environment = start;
	
	cf1->enter(farmer);
	farmer->environment = cf1;
}

int main()
{
	GameStuff gs;
	generate_map(gs);
	
	Parser p(gs);
	
	while (p.run());
	
	return 0;
}
