FILES = data.c main.c data.h ini.c ini.h parser.c parser.h
FLAGS ?= -Wall -Werror -g
CC = gcc

crpg: $(FILES)
	$(CC) $(FILES) $(FLAGS) -o crpg 	

crpg.exe: $(FILES) data.h
	x86_64-w64-mingw32-gcc $(FILES) $(FLAGS) -o crpg.exe


