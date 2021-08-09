/******************************************************************************
 * Program name:	main.cpp
 * Author:		Kristin Schaefer
 * Date:		04-14-2019
 * Description:		This is the main file for lab 2. The main
 * 			function ...
 * Sources:	
 * https://stackoverflow.com/questions/1896527/counting-letters-in-a-text-file		
*******************************************************************************/

#include "letters.hpp"
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

int main()
{
	ifstream inFile; 
	const int SIZE = 26;
	int letterCount [SIZE];	
	int *letterCountPtr = letterCount;

	// fill array elements with 0
	for (int i = 0; i < SIZE; i++)
	{
		letterCount[i] = 0;
	}
	count_letters(inFile, letterCountPtr);	
	return 0;
}
