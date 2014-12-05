FILES = data.c main.c
FLAGS ?= -Wall -Werror -g
CC = gcc

crpg: $(FILES) data.h
	$(CC) $(FILES) $(FLAGS) -o crpg 	
