#ifdef DATA_H_
#define DATA_H_

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
}

struct enemy {
	int health;
	int xpgain;
	int pwr;
	char name[MAXNAME];
}
struct dungeon {
	struct enemy e;
}
struct game {
	struct character p[3];
	struct dungeon *dungeonset;
	struct dungeon *curd;
	char alive;
}

struct game gameset();

#endif
