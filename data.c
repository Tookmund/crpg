#include "data.h"

struct game gameset() {
	struct game g;
	memset(&g,0,sizeof(g));

	// Create Wizard
	struct character wzd;
	wzd.health = 50;
	wzd.level = 1;
	wzd.pwr = 100;
	wzd.def = 1;
	strcpy("Wizard",wzd.name);

	// Create Warrior
	struct character war;
	war.health = 100;
	war.level = 1;
	strcpy("Warrior",war.name);
	war.pwr = 50;
	war.def = 10;

	// Create healer
	struct character hl;
	hl.health = 150;
	hl.level = 1;
	strcpy("Healer",hl.name);
	hl.pwr = 20;
	hl.def = 5;

	g.p[0] = wzd;
	g.p[1] = war;
	g.p[2] = hl;

	//Dungeon 1
	struct dungeon one;
	strcpy("One",one.name);
	one.e.health = 200;
	one.e.xpgain = 100;
	one.e.pwr = 150;
	strcpy("Goblin",one.e.name);

	//Dungeon 2
	struct dungeon two;
	strcpy("Two",two.name);
	two.e.health = 300;
	two.e.xpgain = 400;
	two.e.pwr = 200;
	strcpy("Orc",two.e.name);

	//Dungeon 3
	struct dungeon three;
	strcpy("Three",three.name);
	three.e.health = 500;
	three.e.xpgain = 1000;
	three.e.pwr = 500;
	strcpy("Dragon",three.e.name);

	g.dgnset[0] = one;
	g.dgnset[1] = two;
	g.dgnset[2] = three;
	g.curd = 0;
	return g;
}
