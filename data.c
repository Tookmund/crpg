#include "data.h"

struct game gameset() {
	struct game g;
	memset(&g,0,sizeof(g));

	// Create Wizard
	struct character wzd;
	wzd.health = 50;
	wzd.level = 1;
	wzd.pwr = 100;

	// Create Warrior
	struct character war;
	war.health = 100;
	war.level = 1;
	war.name = "Warrior\0";
	war.pwr = 50;

	// Create healer
	struct character hl;
	hl.health = 150;
	hl.level = 1;
	hl.name = "Healer\0";
	hl.pwr = 20;

	g.p[0] = wizard;
	g.p[1] = war;
	g.p[2] = hl;

	struct dungeon one;
	one.e.health = 200;
	one.e.xpgain = 100;
	one.e.power = 150;
	one.e.name = "Goblin\0";

	struct dungeon two;
	two.e.health = 300;
	two.e.xpgain = 400;
	two.e.power = 200;
	two.e.name = "Orc\0";

	struct dungeon three;
	three.e.health = 500;
	three.e.xpgain = 1000;
	three.e.power = 500;
	three.e.name = "Dragon\0";

	g.dungeonset = {one,two,three};
	return g;
}
