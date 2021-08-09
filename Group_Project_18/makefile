# Program name: Makefile
# Group : 	18
# Authors:	Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
# Date:		05-12-2019
# Description:	This file contains the makefile for the Critter class for the
#		Predator-Prey Game.

output: main.o critter.o getRandomNumber.o inputval.o ant.o doodlebug.o game.o
	g++ main.o critter.o getRandomNumber.o inputval.o ant.o doodlebug.o game.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

critter.o: critter.cpp critter.hpp
	g++ -std=c++11 -c critter.cpp

getRandomNumber.o: getRandomNumber.cpp getRandomNumber.hpp
	g++ -std=c++11 -c getRandomNumber.cpp

inputval.o: inputval.cpp inputval.hpp
	g++ -std=c++11 -c inputval.cpp

ant.o: ant.cpp ant.hpp
	g++ -std=c++11 -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ -std=c++11 -c doodlebug.cpp

game.o: game.cpp game.hpp
	g++ -std=c++11 -c game.cpp

clean:
	rm *.o output
