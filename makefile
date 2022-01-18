CC=g++
CXX=/usr/bin/g++

default: Utilities day9 main
	g++ -std=c++20 -Wall -g build/*.o -o build/main

main: main.cpp
	g++ -std=c++20 -Wall -g -c main.cpp -o build/main.o

Utilities: Utilities.cpp Utilities.h
	g++ -std=c++20 -Wall -g -c Utilities.cpp -o build/Utilities.o

day9: $(shell find day9 -type f)
	g++ -std=c++20 -Wall -g -c -I ./day9 day9/*.cpp -o build/day9.o

clean:
	rm build/*

