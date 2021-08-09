# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		5-12-2019
# Description:	This is the Makefile for Lab6.

output: main.o menu.o node.o doubleLink.o
	g++ -std=c++11 main.o menu.o node.o doubleLink.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

node.o: node.cpp node.hpp
	g++ -std=c++11 -c node.cpp

doubleLink.o: doubleLink.cpp doubleLink.hpp
	g++ -std=c++11 -c doubleLink.cpp

clean:
	rm *.o output
