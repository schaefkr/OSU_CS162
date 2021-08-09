# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		6-11-2019
# Description:	This is the Makefile for Final_Project.

output: main.o menu.o space.o home.o work.o shop.o bus.o train.o walk.o player.o game.o 
	g++ -std=c++11 main.o menu.o space.o home.o work.o shop.o bus.o train.o walk.o player.o game.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

space.o: space.cpp space.hpp
	g++ -std=c++11 -c space.cpp

home.o: home.cpp home.hpp
	g++ -std=c++11 -c home.cpp

work.o: work.cpp work.hpp
	g++ -std=c++11 -c work.cpp

shop.o: shop.cpp shop.hpp
	g++ -std=c++11 -c shop.cpp

bus.o: bus.cpp bus.hpp
	g++ -std=c++11 -c bus.cpp

train.o: train.cpp train.hpp
	g++ -std=c++11 -c train.cpp

walk.o: walk.cpp walk.hpp
	g++ -std=c++11 -c walk.cpp

player.o: player.cpp player.hpp
	g++ -std=c++11 -c player.cpp

game.o: game.cpp game.hpp
	g++ -std=c++11 -c game.cpp

clean:
	rm *.o output
