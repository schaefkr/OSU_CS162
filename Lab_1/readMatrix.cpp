/****************************************************************************************************
** Name:                readMatrix.cpp
** Author:              Kristin Schaefer
** Date:                04-07-2019
** Description:         This is the source file for the readMatrix function for the Matrix 
                        Calculator.
****************************************************************************************************/

#include "readMatrix.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/***********************************************************
*                      readMatrix
* This function takes a pointer to a 2d dynamic array
* and the size of the selected matrix (2x2 or 3x3) as
* parameters and asks the user to enter the numbers to 
* fill the matrix.
***********************************************************/

void readMatrix(int** matrixPtr, int mSize)
{
        for (int r = 0; r < mSize; r++)
        {
                cout << "Enter " << mSize << " numbers for row " << r << " : " << endl;
                for (int c = 0; c < mSize; c++)
                {
                        cin >> matrixPtr[r][c];
                }
                cout << endl;
        }
}
