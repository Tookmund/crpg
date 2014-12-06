FILES = data.c main.c
FLAGS ?= -Wall -Werror -g
CC = gcc

crpg: $(FILES) data.h
	$(CC) $(FILES) $(FLAGS) -o crpg 	

crpg.exe: $(FILES) data.h
	x86_64-w64-mingw32-gcc $(FILES) $(FLAGS) -o crpg.exe


