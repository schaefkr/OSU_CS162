# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		04-21-2019
# Description:	This is the Makefile for Lab3.

output: main.o die.o loadedDie.o game.o
	g++ -std=c++11 main.o die.o loadedDie.o game.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

die.o: die.cpp die.hpp
	g++ -std=c++11 -c die.cpp

loadedDie.o: loadedDie.cpp loadedDie.hpp
	g++ -std=c++11 -c loadedDie.cpp

game.o: game.cpp game.hpp
	g++ -std=c++11 -c game.cpp 

clean:
	rm *.o output

