# Program name: Makefile
# Author:	Kristin Schaefer	
# Date:		04-14-2019
# Description	This is the Makefile for Lab2.

output: main.o letters.o
	g++ -std=c++11 main.o letters.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

letters.o: letters.cpp letters.hpp
	g++ -std=c++11 -c letters.cpp

clean:
	rm *.o output
