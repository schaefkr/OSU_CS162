/*****************************************************************************************
* Program name:         sort.hpp
* Author:               Kristin Schaefer
* Date:                 5-26-2019
* Description:          This file contains the header file for the Sort class. It defines
* functions to read values from 4 input files, a simple linear search algorithm, a 
* bubble sort algorithm, and a binary search algorithm.
*****************************************************************************************/

#ifndef SORT_HPP
#define SORT_HPP
#include <string>
using std::string;

class Sort
{
	private:
		int arrSize;
		int numArr[10];
		int earlyArr[10];
		int middleArr[10];
		int endArr[10];
		string inputFileNum; 
		string inputFileEarly; 
		string inputFileMiddle; 
		string inputFileEnd; 
		string outputFileNum; 
		string outputFileEarly; 
		string outputFileMiddle; 
		string outputFileEnd; 

	public:
		Sort();
		~Sort();
		void readTxtFiles();
		void simpleSearch();
		void sortTxtFiles();
		void binarySearch();
		int validateInput();
};
#endif 
