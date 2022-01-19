CC=g++
CXX=/usr/bin/g++

default: Utilities day0 main
	g++ -std=c++20 -Wall -g build/*.o -o build/main

main: main.cpp
	g++ -std=c++20 -Wall -g -c main.cpp -o build/main.o

Utilities: Utilities.cpp Utilities.h
	g++ -std=c++20 -Wall -g -c Utilities.cpp -o build/Utilities.o

day0: $(shell find day0 -type f)
	g++ -std=c++20 -Wall -g -c -I ./day0 day0/*.cpp -o build/day0.o

day9: $(shell find day9 -type f)
	g++ -std=c++20 -Wall -g -c -I ./day9 day9/*.cpp -o build/day9.o

day10: $(shell find day10 -type f)
	g++ -std=c++20 -Wall -g -c -I ./day10 day10/*.cpp -o build/day10.o

clean:
	rm build/*
