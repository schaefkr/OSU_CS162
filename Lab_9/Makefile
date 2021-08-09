# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		6-2-2019
# Description:	This is the Makefile for Lab9.

output: main.o buffer.o palindrome.o menu.o 
	g++ -std=c++11 main.o buffer.o palindrome.o menu.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

buffer.o: buffer.cpp buffer.hpp
	g++ -std=c++11 -c buffer.cpp

palindrome.o: palindrome.cpp palindrome.hpp
	g++ -std=c++11 -c palindrome.cpp

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -c menu.cpp

clean:
	rm *.o output
