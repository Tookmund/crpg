FILES = data.c main.c
FLAGS ?= -Wall -Werror
CC = gcc

crpg: $(FILES) data.h
	$(CC) $(FILES) $(FLAGS) -o crpg 	
