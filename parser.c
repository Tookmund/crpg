#include <string.h>

#include "ini.h"
#include "data.h"
#include "parser.h"

#define MATCH(s, n) (strcmp(section, s) == 0 && strcmp(name, n) == 0)

void setupplayer(struct game* g, int plynum, const char* name, const char* value) {
	if (strcmp(name, "name") == 0) {
		strncat(g->p[plynum].name,value,sizeof(g->p[plynum].name));
	} else if (strcmp(name, "health") == 0) {
		g->p[plynum].health = atoi(value);
	} else if (strcmp(name, "level")) {
		g->p[plynum].level = atoi(value);
	} else if (strcmp(name, "pwr")) {
		g->p[plynum].pwr = atoi(value);
	} else if (strcmp(name,"def")) {
		g->p[plynum].def = atoi(value);
	}
}
void setupdungeon(struct game* g, int dgnnum, const char* name, const char* value) {
	if (strcmp(name,"name") == 0) {
		strncat(g->dgn[dgnnum].name,value,sizeof(g->dgn[dgnnum].name));
		printf("default: %s",value);
		printf("outputed: %s",g->dgn[dgnnum].name);
	} else if (strcmp(name,"emaxhealth") == 0) {
		g->dgn[dgnnum].e.maxhealth = atoi(value);
	} else if (strcmp(name,"expgain") == 0) {
		g->dgn[dgnnum].e.xpgain = atoi(value);
	} else if (strcmp(name,"epwr") == 0) {
		g->dgn[dgnnum].e.pwr = atoi(value);
	} else if (strcmp(name,"ename") == 0) {
		strncat(g->dgn[dgnnum].e.name,value,sizeof(g->dgn[dgnnum].e.name));
	}
}
int handler(void* user, const char* section, const char* name, const char* value) {
	//printf("Section: (%s)\nName: (%s)\nValue: (%s)\n",section,name,value);
	struct game* g = (struct game*)user;
	if (strcmp(section, "party0") == 0) {
		setupplayer(g,0,name,value);
	} else if (strcmp(section, "party1") == 0) {
		setupplayer(g,1,name,value);
	} else if (strcmp(section,"party2")) {
		setupplayer(g,2,name,value);
	}
	else if (strcmp(section,"dungeon0") == 0) {
		setupdungeon(g,0,name,value);
	} else if (strcmp(section,"dungeon1") == 0) {
		setupdungeon(g,1,name,value);
	} else if (strcmp(section,"dungeon2") == 0) {
		setupdungeon(g,2,name,value);
	}
	else {
		return 0;
	}
	return 1;
}

struct game* setupgame() {
	struct game g;
	struct game* gptr = &g;
	int rtn = ini_parse("default.ini",handler,gptr);
	if (rtn < 0) {
		printf("Failed to load default.ini!\n");
		exit(0);
	}
	printf("dugeon name: (%s)\n",gptr->dgn[0].name);
	return gptr;
}
