/***************************************************************************
* Program name:         recursive.cpp
* Author:               Kristin Schaefer
* Date:                 05-05-2019
* Description:		This is the source file for the recursive functions.
***************************************************************************/

#include "recursive.hpp"
#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::cout;

/***************************************************************************
void reverseString(string reverse)
Description: This function asks the user to input a string they would like
to print backwards. The function takes the input string and then
recursively prints it backwards. 
***************************************************************************/
void reverseString(string reverse)
{
	if (reverse.size() == 0)
	{	
		return; 
	}
	reverseString(reverse.substr(1));
	cout << reverse[0];
}

/***************************************************************************
void sumIntArray(int *intArr, int size)
Description: This function asks the user to input an integer for the size
of the array they would like to sum, and then the integers to sum. The 
function then recursively calculates the sum of the array of integers and
then prints the sum.
***************************************************************************/
int sumIntArray(int *intArr, int size)
{
	if (size <= 0)
	{
		return size;
	} 
	return (intArr[size-1] + sumIntArray(intArr, size-1));  
}

/***************************************************************************
int triangleNumber(int N)
Description:
***************************************************************************/
int triangleNumber(int N)
{
	if (N == 1)
	{
		return N;
	}
	else 
	{
		return (N + triangleNumber(N - 1));
	}
}
