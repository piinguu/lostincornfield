#compiler variable
CC=g++
#flags
CFLAGS=-std=c++0x -o bin/licf.out
SRC=src/*.cpp

all:
	$(CC) $(SRC) $(CFLAGS)
