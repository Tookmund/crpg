#include "data.h"
// printf/scanf code for importing and exporting a game object
#define SAVEFORMAT "CRPG: "

struct game gameset();
void newgame();
void loadgame();
void savegame();
void quitgame();
int battle(struct game *g);

int main (void) {
	char* menu = "+------------------------+\n"
		     "|   Welcome to C RPG!    |\n"
		     "| A silly adventure in C |\n"
		     "|                        |\n"
		     "| [n] New Game	       |\n"
		     "| [l] Load Game	       |\n"
		     "| [q] Quit Game	       |\n"
		     "+------------------------+\n";
	printf("\n%s",menu);
	int choice;
	choice = getchar();
	switch(choice) {
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
	int success = 1;
	while(success) {
		success = battle(&g);
		g.curd++;
	}
	quitgame();
}

int battle(struct game *g) {
	printf("\n\nThe party enters %s.\n",g->dgnset[g->curd].name);
	printf("The party encounters a %s!\n",g->dgnset[g->curd].e.name);
	int i = 0;
	int psize = sizeof(g->p)/sizeof(struct character);
	while (g->alive) {
		// The party attacks
		for (i = 0; i < psize; i++) {
			printf("What will %s do?\n",g->p[i].name);
			printf("[a] Attack?\n"
			       "[d] Defend?\n"
			       "[n] Nothing?\n");
			switch(getchar()) {
				case 'a':
					printf("%s attacks! %d damage to %s!\n",g->p[i].name,g->p[i].pwr,g->dgnset[g->curd].name);
					g->dgnset[g->curd].e.health -= g->p[i].pwr;
					if (g->dgnset[g->curd].e.health <= 0) {
						printf("The party defeated the %s!",g->dgnset[g->curd].e.name);
						g->alive = 0;
					}
					else {
						printf("The %s has %d health left!\n",g->dgnset[g->curd].name,g->dgnset[g->curd].e.health);
					break;
				case 'd':
					printf("\n%s defends! +%d to defense!\n",g->p[i].name,g->p[i].def);
					g->p[i].def = g->p[i].def + g->p[i].def;
					break;
				case 'n':
				default:
					printf("%s does nothing!\n",g->p[i].name);
			}
		}
		// Now the monster attacks
		printf("%s does nothing!\n",g->dgnset[g->curd].e.name);
	}
	char dead = 0;
	for(i = 0; i < psize; i++) {
		if (g->p[i].health > 0) {
			printf("%s survived the encounter!\n",g->p[i].name);
		}
		else {
			printf("%s died during the battle!",g->p[i].name);
			dead = 1;
		}
	}
	if (dead == 1) {
		printf("One of the party died!\n GAME OVER\n");
		return 0;
	}
	return 1;
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
