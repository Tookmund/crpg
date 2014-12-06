#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME 128

#include "data.h"

struct game gameset() {
	struct game g;
	memset(&g,0,sizeof(g));

	// Create Wizard
	struct character wzd;
	wzd.health = 100;
	wzd.level = 1;
	wzd.pwr = 100;
	wzd.def = 1;
	memset(&wzd.name,0,sizeof(wzd.name));
	strcpy(wzd.name,"Wizard");

	// Create Warrior
	struct character war;
	war.health = 150;
	war.level = 1;
	memset(&war.name,0,sizeof(war.name));
	strcpy(war.name,"Warrior");
	war.pwr = 50;
	war.def = 10;

	// Create healer
	struct character hl;
	hl.health = 200;
	hl.level = 1;
	memset(&hl.name,0,sizeof(hl.name));
	strcpy(hl.name,"Squire");
	hl.pwr = 20;
	hl.def = 5;

	g.p[0] = wzd;
	g.p[1] = war;
	g.p[2] = hl;

	//Dungeon 1
	struct dungeon one;
	strcpy(one.name,"One");
	one.e.maxhealth = 200;
	one.e.xpgain = 100;
	one.e.pwr = 50;
	strcpy(one.e.name,"Goblin");

	//Dungeon 2
	struct dungeon two;
	strcpy(two.name,"Two");
	two.e.maxhealth = 300;
	two.e.xpgain = 400;
	two.e.pwr = 70;
	strcpy(two.e.name,"Orc");

	//Dungeon 3
	struct dungeon three;
	strcpy(three.name,"Three");
	three.e.maxhealth = 500;
	three.e.xpgain = 1000;
	three.e.pwr = 80;
	strcpy(three.e.name,"Dragon");

	g.dgn[0] = one;
	g.dgn[1] = two;
	g.dgn[2] = three;
	g.curd = 0;
	return g;
}
