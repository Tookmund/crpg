#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXNAME 128

struct character {
	int health;
	int xp;
	int level;
	char name[MAXNAME];
	// amount of damage character can inflict
	int pwr;
};

struct enemy {
	int health;
	int xpgain;
	int pwr;
	char name[MAXNAME];
};

struct dungeon {
	struct enemy e;
	char name[MAXNAME];
};

struct game {
	struct character p[3];
	struct dungeon dgnset[3];
	struct dungeon *curd;
	char alive;
};

