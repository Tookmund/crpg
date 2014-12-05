#include "data.h"
// printf/scanf code for importing and exporting a game object
#define SAVEFORMAT "CRPG: "

struct game gameset();
void newgame();
void loadgame();
void savegame();
void quitgame();

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

	while (g.alive) {
		
	}
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
