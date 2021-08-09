# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		04-29-2019
# Description:	This is the Makefile for Project2 Zoo Tycoon.

output: main.o animal.o tiger.o turtle.o penguin.o zoo.o 
	g++ -std=c++11 main.o animal.o tiger.o turtle.o penguin.o zoo.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

animal.o: animal.cpp
	g++ -std=c++11 -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -std=c++11 -c tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -std=c++11 -c turtle.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -std=c++11 -c penguin.cpp 

zoo.o: zoo.cpp zoo.hpp
	g++ -std=c++11 -c zoo.cpp 

clean:
	rm *.o output

