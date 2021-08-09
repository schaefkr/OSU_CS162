# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		5-26-2019
# Description:	This is the Makefile for Project4.

output: main.o menu.o character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o game.o team.o loser.o
	g++ -std=c++11 main.o menu.o character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o game.o team.o loser.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

character.o: character.cpp character.hpp
	g++ -std=c++11 -c character.cpp

vampire.o: vampire.cpp vampire.hpp
	g++ -std=c++11 -c vampire.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -std=c++11 -c barbarian.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	g++ -std=c++11 -c bluemen.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -std=c++11 -c medusa.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	g++ -std=c++11 -c harrypotter.cpp

game.o: game.cpp game.hpp
	g++ -std=c++11 -c game.cpp

team.o: team.cpp team.hpp
	g++ -std=c++11 -c team.cpp

loser.o: loser.cpp loser.hpp
	g++ -std=c++11 -c loser.cpp

clean:
	rm *.o output
