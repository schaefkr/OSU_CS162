# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		5-26-2019
# Description:	This is the Makefile for Lab8.

output: main.o sort.o
	g++ -std=c++11 main.o sort.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

sort.o: sort.cpp sort.hpp
	g++ -std=c++11 -c sort.cpp

clean:
	rm *.o output
