# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		04-29-2019
# Description:	This is the Makefile for Lab4 OSU information system.

output: main.o university.o building.o person.o student.o instructor.o menu.o
	g++ -std=c++11 main.o university.o building.o person.o student.o instructor.o menu.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

university.o: university.cpp
	g++ -std=c++11 -c university.cpp

building.o: building.cpp building.hpp
	g++ -std=c++11 -c building.cpp

person.o: person.cpp person.hpp
	g++ -std=c++11 -c person.cpp

student.o: student.cpp student.hpp
	g++ -std=c++11 -c student.cpp 

instructor.o: instructor.cpp instructor.hpp
	g++ -std=c++11 -c instructor.cpp
 
menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

clean:
	rm *.o output

