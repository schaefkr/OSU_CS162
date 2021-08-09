/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			5-26-2019
* Description:		This file contains the main function for Lab8. It creates a
* Sort object, then calls the functions to read in the txt files, perform a simple 
* search, sort the txt files and then perform a binary search.
*****************************************************************************************/

#include "sort.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Sort sortFiles;
	sortFiles.readTxtFiles();
	sortFiles.simpleSearch();
	sortFiles.sortTxtFiles();
	sortFiles.binarySearch();
	return 0;
}
