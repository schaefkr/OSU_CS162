# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		5-5-2019
# Description:	This is the Makefile for Lab5.

output: main.o menu.o recursive.o
	g++ -std=c++11 main.o menu.o recursive.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

recursive.o: recursive.cpp recursive.hpp
	g++ -std=c++11 -c recursive.cpp

clean:
	rm *.o output

