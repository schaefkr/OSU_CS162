/***************************************************************************************************
** Program name:	main.cpp
** Author:		Kristin Schaefer
** Date:		04-07-2019
** Description:		This file contains the main function for the Matrix Calculator.
			The function asks the user to choose a size of Matrix (2x2 or 3x3),
			and then prompts the user to enter 4 or 9 integers to fill the matrix.
			The function then calculates the determinant of the matrix, and 
			displays the matrix and the determinant to the user.
****************************************************************************************************/

#include "determinant.hpp"
#include "readMatrix.hpp"
#include <iostream>
using std::endl;
using std::cin;
using std::cout;	

int main()
{
	int matrixSize, matrixDeterminant;

	// source for do-while loop format: Starting out with C++, by Gaddis, Walters & Muganda 
	do
	{
		cout << "Please enter the size of matrix you would like to create:" << endl;
		cout << "Enter 2 for a matrix of size 2x2" << endl;
		cout << "Enter 3 for a matrix of size 3x3" << endl;
		cin >> matrixSize;
		
		if (matrixSize < 2 || matrixSize > 3)
		{
			cout << "Please enter a valid input of 2 or 3" << endl;
		}
	} while (matrixSize < 2 || matrixSize > 3);

	// dynamically allocate array and pass to readMatrix
	// then display matrix determinant 
	// source: https://www.youtube.com/watch?v=0BX5heUj0FI	
	int **arrayMatrix = new int* [matrixSize];		// create rows of matrix 
	for (int row = 0; row < matrixSize; row++)
	{
		arrayMatrix[row] = new int[matrixSize];		// create columns of matrix
	}
	readMatrix(arrayMatrix, matrixSize); 

	cout << "The matrix you entered is:" << endl;
	for (int row = 0; row < matrixSize; row++)		
	{
		for (int column = 0; column < matrixSize; column++)
		{ 
			cout << arrayMatrix[row][column];
		}
		cout << endl;
	}
	cout << endl;

	matrixDeterminant = determinant(arrayMatrix, matrixSize);
	cout << "The determinant of the matrix is: " << matrixDeterminant << endl;

	// deallocate pointers
	// source: https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new	
	for (int index = 0; index < matrixSize; ++index)
	{	
		delete [] arrayMatrix[index];
	}
	delete [] arrayMatrix;	
	
	return 0;
}
