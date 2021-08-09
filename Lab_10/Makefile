# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		6-11-2019
# Description:	This is the Makefile for Lab10.

output: main.o menu.o fibonacci.o 
	g++ -std=c++11 main.o menu.o fibonacci.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

fibonacci.o: fibonacci.cpp fibonacci.hpp
	g++ -std=c++11 -c fibonacci.cpp

clean:
	rm *.o output
