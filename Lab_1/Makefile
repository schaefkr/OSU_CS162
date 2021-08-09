# Program name: Makefile
# Author:	Kristin Schaefer
# Date:		04-07-2019
# Description:  This is the Makefile for matrixCalculator.

# source: https://www.youtube.com/watch?v=_r7i5X0rXJk

matrixCalculator: main.o readMatrix.o determinant.o
	g++ main.o readMatrix.o determinant.o -o matrixCalculator 

main.o: main.cpp
	g++ -c main.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp 

determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

clean:
	rm *.o matrixCalculator 



