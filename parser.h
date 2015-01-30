#ifndef PARSER_H_
#define PARSER_H_

struct game setupgame();
void setupplayer(struct game* g, int plynum, const char* name, const char* value);
void setupdungeon(struct game* g, int dgnnum, const char* name, const char* value);
int handler(void* user, const char* section, const char* name, const char* value);

#endif
