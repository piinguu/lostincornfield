#include "Game.h"

#include<iostream>
#include<algorithm>

using namespace licf;

void generate_map(GameStuff & gs);
void generate_presentation_map(GameStuff & gs);
void mappa(Environment * e, Actor * a); 
void print_introduction();

int main()
{
	//initialize
	GameStuff gs;
	generate_presentation_map(gs);
	//generate_map(gs);
	
	Parser p(gs);
	
	//run the game
	print_introduction();
	while (p.run())
		std::for_each(gs.actors.begin(), gs.actors.end(),
			[] (Actor * actor) {			
				if (actor->hp > 0)
					actor->action();
				});
	
	//wrap up
	gs.cleanup();	
	return 0;
}

void generate_presentation_map( GameStuff & gs) 
{
	// Generate environment
	Environment * c00 = new CornField();
	Environment * c01 = new CornField();
	Environment * c02 = new CornField();
	Environment * c03 = new CornField();
	Environment * c10 = new CornField();
	Environment * c11 = new CornField();
	Environment * c13 = new CornField();
	Environment * c20 = new CornField();
	Environment * c21 = new CornField();
	Environment * c22 = new CornField();
	Environment * c23 = new CornField();
	Environment * c24 = new CornField();
	Environment * c30 = new CornField();
	Environment * c31 = new CornField();
	Environment * c32 = new CornField();
	Environment * c33 = new CornField();
	Environment * c34 = new CornField();
	Environment * c40 = new CornField();
	Environment * c41 = new CornField();
	Environment * c42 = new CornField();
	Environment * c43 = new CornField();
	Environment * c44 = new CornField();
	
	gs.map.push_back(c00);
	gs.map.push_back(c01);
	gs.map.push_back(c02);
	gs.map.push_back(c03);
	gs.map.push_back(c10);
	gs.map.push_back(c11);
	gs.map.push_back(c13);
	gs.map.push_back(c20);
	gs.map.push_back(c21);
	gs.map.push_back(c22);
	gs.map.push_back(c23);
	gs.map.push_back(c24);
	gs.map.push_back(c30);
	gs.map.push_back(c31);
	gs.map.push_back(c32);
	gs.map.push_back(c33);
	gs.map.push_back(c34);
	gs.map.push_back(c40);
	gs.map.push_back(c41);
	gs.map.push_back(c42);
	gs.map.push_back(c43);
	gs.map.push_back(c44);

	// Generate actors
	gs.player = new Player();
	Actor * s1 = new Snake();
	Actor * s2 = new Snake();
	Actor * f1 = new Farmer("Folke");
	Actor * f2 = new Farmer("Melker");
	Actor * b1 = new Bee();
	Actor * d1 = new Dog(4);
	Actor * bird = new Bird();

	gs.actors.push_back(gs.player);
	gs.actors.push_back(s1);
	gs.actors.push_back(s2);
	gs.actors.push_back(f1);
	gs.actors.push_back(f2);
	gs.actors.push_back(b1);
	gs.actors.push_back(d1);
	gs.actors.push_back(bird);

	// Generate objects
	Object * key = new Key();
	Object * backpack = new Backpack(75, 50);
	Object * honey1 = new Honey();
	Object * honey2 = new Honey();
	Object * honey3 = new Honey();
	Object * knife = new Knife();
	Object * car = new Car();
	Object * coulter = new Coulter();

	gs.objects.push_back(key);
	gs.objects.push_back(backpack);
	gs.objects.push_back(honey1);
	gs.objects.push_back(honey2);
	gs.objects.push_back(honey3);
	gs.objects.push_back(knife);
	gs.objects.push_back(car);
	gs.objects.push_back(coulter);

	// Generate all neighbors and place all actors and objects

	// Neighbors
	c00->add_neighbor(c01, East);
	c01->add_neighbor(c00, West);
	c01->add_neighbor(c02, East);
	c02->add_neighbor(c01, West);
	c02->add_neighbor(c03, East);
	c03->add_neighbor(c02, West);

	c01->add_neighbor(c11, South);
	c11->add_neighbor(c01, North);
	c03->add_neighbor(c13, South);
	c13->add_neighbor(c03, North);
	
	c10->add_neighbor(c11, East);
	c11->add_neighbor(c10, West);
	
	c10->add_neighbor(c20, South);
	c20->add_neighbor(c10, North);
	c11->add_neighbor(c21, South);
	c21->add_neighbor(c11, North);
	c13->add_neighbor(c23, South);
	c23->add_neighbor(c13, North);

	c20->add_neighbor(c30, South);
	c30->add_neighbor(c20, North);
	c22->add_neighbor(c32, South);
	c32->add_neighbor(c22, North);
	c24->add_neighbor(c34, South);
	c34->add_neighbor(c24, North);

	c30->add_neighbor(c31, East);
	c31->add_neighbor(c30, West);
	c31->add_neighbor(c32, East);
	c32->add_neighbor(c31, West);
	c32->add_neighbor(c33, East);
	c33->add_neighbor(c32, West);
	c33->add_neighbor(c34, East);
	c34->add_neighbor(c33, West);

	c32->add_neighbor(c42, South);
	c42->add_neighbor(c32, North);
	c34->add_neighbor(c44, South);
	c44->add_neighbor(c34, North);

	c40->add_neighbor(c41, East);
	c41->add_neighbor(c40, West);
	c41->add_neighbor(c42, East);
	c42->add_neighbor(c41, West);
	c42->add_neighbor(c43, East);
	c43->add_neighbor(c42, West);
	c43->add_neighbor(c44, East);
	c44->add_neighbor(c43, West);

	// Place actors
	mappa(c00, s1);
	mappa(c11, f1);
	mappa(c22, gs.player);
	mappa(c33, s2);
	mappa(c40, f2);
	mappa(c41, b1);
	mappa(c41, d1);
	mappa(c32, bird);


	// Place objects
	c00->pick_up(key);
	c02->pick_up(honey2);
	c21->pick_up(backpack);
	c23->pick_up(honey1);
	c30->pick_up(knife);
	c31->pick_up(honey3);
	c40->pick_up(car);
	c44->pick_up(coulter);
}

void mappa(Environment * e, Actor * a) 
{
	e->enter(a);
	a->environment = e;
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
