# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		5-19-2019
# Description:	This is the Makefile for Lab7.

output: main.o menu.o queue.o
	g++ -std=c++11 main.o menu.o queue.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

queue.o: queue.cpp queue.hpp
	g++ -std=c++11 -c queue.cpp

clean:
	rm *.o output
