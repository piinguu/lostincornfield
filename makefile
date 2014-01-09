#compiler variable
CC=g++
#flags
CFLAGS=-std=c++0x -o bin/licf.out
BUILD=g++ -std=c++0x -c -g

all: game

game: base env actors objects
	mv *.o obj
	g++ -g obj/*.o -o bin/licf.out

base: src/*.cpp
	$(BUILD) src/*.cpp

env: src/env/*.cpp
	$(BUILD) src/env/*.cpp

actors: src/actors/*.cpp
	$(BUILD) src/actors/*.cpp

objects: src/objects/*.cpp
	$(BUILD) src/objects/*.cpp
