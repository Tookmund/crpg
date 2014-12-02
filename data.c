#include "data.h"

struct game gameset() {
	struct game g;
	memset(&g,0,sizeof(g));

	// Create Wizard
	struct character wzd;
	wzd.health = 50;
	wzd.level = 1;
	wzd.pwr = 100;
	strcpy("Wizard\0",wzd.name);

	// Create Warrior
	struct character war;
	war.health = 100;
	war.level = 1;
	strcpy("Warrior\0",war.name);
	war.pwr = 50;

	// Create healer
	struct character hl;
	hl.health = 150;
	hl.level = 1;
	strcpy("Healer\0",hl.name);
	hl.pwr = 20;

	g.p[0] = wzd;
	g.p[1] = war;
	g.p[2] = hl;

	struct dungeon one;
	one.e.health = 200;
	one.e.xpgain = 100;
	one.e.pwr = 150;
	strcpy("Goblin\0",one.e.name);

	struct dungeon two;
	two.e.health = 300;
	two.e.xpgain = 400;
	two.e.pwr = 200;
	strcpy("Orc\0",two.e.name);

	struct dungeon three;
	three.e.health = 500;
	three.e.xpgain = 1000;
	three.e.pwr = 500;
	strcpy("Dragon\0",three.e.name);

	g.dgnset[0] = one;
	g.dgnset[1] = two;
	g.dgnset[2] = three;
	g.curd = &g.dgnset[0];
	return g;
}
