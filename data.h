#ifndef CRPG_H_
#define CRPG_H_

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
	int def;
};

struct enemy {
	int maxhealth;
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
	struct dungeon dgn[3];
	int curd;
	char alive;
	int score;
};

struct game gameset();
void newgame();
void loadgame();
void savegame();
void quitgame();
int battle(struct game *g);

#endif
