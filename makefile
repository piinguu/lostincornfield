#compiler variable
CC=g++
#flags
CFLAGS=-std=c++0x -o bin/licf.out

all:
	$(CC) src/*.cpp src/actors/*.cpp src/env/*.cpp src/objects/*.cpp $(CFLAGS)
