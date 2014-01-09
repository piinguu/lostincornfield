#compiler variable
CC=g++
#flags
CFLAGS=-std=c++0x -o bin/licf.out
BUILD=g++ -std=c++0x -c -g

all: game

game: base env actors objects
	g++ obj/*.o -o bin/licf.out

base: src/*.cpp
	$(BUILD) src/*.cpp
	mv *.o obj

env: src/env/*.cpp
	$(BUILD) src/env/*.cpp
	mv *.o obj

actors: src/actors/*.cpp
	$(BUILD) src/actors/*.cpp
	mv *.o obj

objects: src/objects/*.cpp
	$(BUILD) src/objects/*.cpp
	mv *.o obj

bin:
	g++ obj/*.o -o bin/licf.out
