# Program name: Makefilels# Author:	Kristin Schaefer
# Date:		04-14-2019
# Description:  This is the Makefile for Project 1 Langton's Ant.

# source: https://www.youtube.com/watch?v=_r7i5X0rXJk

output: main.o menu.o ant.o
	g++ -std=c++11 main.o menu.o ant.o -o output 

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp 

ant.o: ant.cpp ant.hpp
	g++ -std=c++11 -c ant.cpp

clean:
	rm *.o output
