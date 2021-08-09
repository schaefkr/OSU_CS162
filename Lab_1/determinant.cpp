/****************************************************************************************************
** Name:        	determinant.cpp
** Author:              Kristin Schaefer
** Date:                04-07-2019
** Description:         This is the source file for the determinant function for the Matrix 
                        Calculator.
****************************************************************************************************/

#include "determinant.hpp"

/***********************************************************
 * 			determinant	
 * This function takes a pointer to a 2d dynamic array
 * and the size of the selected matrix (2x2 or 3x3) as
 * parameters and then calculates and returns the 
 * determinant of the user's matrix. 
***********************************************************/

int determinant(int** mPtr, int size)
{
	int det;
	
	if (size == 2)
	{
		det = mPtr[0][0] * mPtr[1][1] - mPtr[0][1] * mPtr[1][0];
	}
	
	else 
	{	
		det = mPtr[0][0] * (mPtr[1][1] * mPtr[2][2] - mPtr[1][2] * mPtr[2][1]) -  
		      mPtr[0][1] * (mPtr[1][0] * mPtr[2][2] - mPtr[1][2] * mPtr[2][0]) +
	              mPtr[0][2] * (mPtr[1][0] * mPtr[2][1] - mPtr[1][1] * mPtr[2][0]);
	}
	return det;
}
