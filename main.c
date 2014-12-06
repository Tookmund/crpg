#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "data.h"

#ifdef WIN32
#include <windows.h>
#define SLEEP(x) Sleep(x)
#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#endif

// printf/scanf code for importing and exporting a game object
//#define SAVEFORMAT "CRPG: "

int main (void) {
	srand(time(NULL));
	char* menu = "+------------------------+\n"
		     "|   Welcome to C RPG!    |\n"
		     "| A silly adventure in C |\n"
		     "|                        |\n"
		     "| [n] New Game	         |\n"
		     "| [l] Load Game	         |\n"
		     "| [q] Quit Game	         |\n"
		     "+------------------------+\n";
	printf("\n%s",menu);
	switch(getchar()) {
		case 'n':
			newgame();
			break;
		case 'l':
			loadgame();
			break;
		case 'q':
			quitgame();
			break;
		default:
			printf("Invalid Choice\n");
	}
	return 0;
}

void newgame() {
	printf("newgame\n");
	struct game g = gameset();
	struct game *gptr = &g;
	int success = 1;
	while(success) {
		g.alive = 1;
		success = battle(gptr);
		g.curd++;
		if (g.curd >= (sizeof(g.dgn)/sizeof(struct dungeon))) {
			g.curd = 0;
		}
	}
	quitgame();
}

int battle(struct game *g) {
	printf("\n\nThe party enters %s.\n",g->dgn[g->curd].name);
	//set monster's health
	g->dgn[g->curd].e.health = g->dgn[g->curd].e.maxhealth;
	printf("The party encounters a %s with %d health!\n",g->dgn[g->curd].e.name,g->dgn[g->curd].e.health);
	int i = 0;
	const int psize = sizeof(g->p)/sizeof(struct character);
	while (g->alive) {
		// The party attacks
		for (i = 0; i < psize; i++) {
			if (g->p[i].health <= 0) {
				printf("%s is dead!\n",g->p[i].name);
				g->alive = 0;
				continue;
			}
			printf("\nWhat will %s do?\n",g->p[i].name);
			printf("[a] Attack?\n"
			       "[d] Defend?\n"
			       "[n] Nothing?\n");
			int c;
			do {
				c = getchar();
				switch(c) {
					case 'a':
						printf("%s attacks! %d damage to %s!\n",g->p[i].name,g->p[i].pwr,g->dgn[g->curd].e.name);
						g->dgn[g->curd].e.health -= g->p[i].pwr;
						printf("The %s has %d health left!\n",g->dgn[g->curd].e.name,g->dgn[g->curd].e.health);
						break;
					case 'd':
						printf("\n%s defends! +%d to defense!\n",g->p[i].name,g->p[i].def);
						g->p[i].def = g->p[i].def + g->p[i].def;
						break;
					case 'n':
						printf("%s does nothing!\n",g->p[i].name);
					break;
				}
				if (g->dgn[g->curd].e.health <= 0) {
					printf("The party defeated the %s!\n +%d xp for all!\n",g->dgn[g->curd].e.name,g->dgn[g->curd].e.xpgain);
					int i;
					for (i = 0;i < psize; i++) {
						g->p[i].xp += (g->dgn[g->curd].e.xpgain);
						printf("%s now has %d xp!\n",g->p[i].name,g->p[i].xp);
						if(g->p[i].xp > 1000) {
							g->p[i].level++;
							printf("%s leveled up to level %d!\n",g->p[i].name,g->p[i].level);
							g->p[i].pwr += g->p[i].def;
							printf("%s now has %d power!\n",g->p[i].name,g->p[i].pwr);
							g->p[i].xp = 0;
						}
					}
					g->alive = 0;
					//make sure it doesn't loop again
					c = 'c';
					i = psize + 1;
				}
				//SLEEP(1);
			} while(c == '\n');
		}
		// Now the monster attacks
		int random = rand();
		//printf("\n%d\n",random);
		int picker = random % 4;
		//printf("\n%d\n",picker);
		int ply = 0;
		switch(picker) {
			case 0:
				ply = 0;
				break;
			case 1:
				ply = 2;
				break;
			case 2:
			case 3:
				ply = 1;
				break;
		}
		printf("%s attacks %s! Does %d points of damage!\n",g->dgn[g->curd].e.name,g->p[ply].name,g->dgn[g->curd].e.pwr);
		g->p[ply].health -= g->dgn[g->curd].e.pwr;
		printf("%s now has %d health!\n",g->p[ply].name,g->p[ply].health);

	}
	int dead = 0;
	for(i = 0; i < psize; i++) {
		if (g->p[i].health > 0) {
			printf("%s survived the encounter!\n",g->p[i].name);
		}
		else {
			printf("%s is dead!\n",g->p[i].name);
			dead += 1;
		}
	}
	if (dead == psize) {
		printf("All of the party died!\n GAME OVER\n");
		return(0);
	}
	return(1);
}

void loadgame() {
printf("loadgame");
}

void savegame () {
printf("savegame");
}

void quitgame () {
	printf("Thanks for playing!\n");
	exit(0);
}
