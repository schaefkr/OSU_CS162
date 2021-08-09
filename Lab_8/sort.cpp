/*****************************************************************************************
* Program name:         sort.cpp
* Author:               Kristin Schaefer
* Date:                 5-26-2019
* Description:          This file contains the source file for the Sort class. It defines
* functions to read values from 4 input files, a simple linear search algorithm, a 
* bubble sort algorithm, and a binary search algorithm.
*****************************************************************************************/

#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream; 


/*****************************************************************************************
Sort::Sort()
Description: Constructor. The constructor initializes the number of values in each array, 
as well as the name of each input file.
*****************************************************************************************/
Sort::Sort()
{
	arrSize = 10;
	inputFileNum = "num.txt";
	inputFileEarly = "early.txt";
	inputFileMiddle = "middle.txt";
	inputFileEnd = "end.txt";
}

/*****************************************************************************************
Sort::~Sort()
Description: Destructor
*****************************************************************************************/
Sort::~Sort()
{

}

/*****************************************************************************************
void Sort::readTxtFiles()
Description: This function reads 4 txt files and puts the values of each file into a 
separate int array.
Sources: Textbook, Ch8, Pg536
https://stackoverflow.com/questions/20042325/c-array-from-file-input 
*****************************************************************************************/
void Sort::readTxtFiles()
{
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << "1. Read Text Files" << endl;	

	// num.txt
	ifstream dataInNum;
	dataInNum.open(inputFileNum);
	for (int i = 0; i < arrSize; i++)
	{
		dataInNum >> numArr[i];
	} 
	dataInNum.close();

	// early.txt
	ifstream dataInEarly;
	dataInEarly.open(inputFileEarly);
	for (int i = 0; i < arrSize; i++)
	{
		dataInEarly >> earlyArr[i]; 
	} 
	dataInEarly.close();

	// middle.txt
	ifstream dataInMiddle;
	dataInMiddle.open(inputFileMiddle);
	for (int i = 0; i < arrSize; i++)
	{
		dataInMiddle >> middleArr[i];
	} 
	dataInMiddle.close();
	
	// end.txt
	ifstream dataInEnd;
	dataInEnd.open(inputFileEnd);
	for (int i = 0; i < arrSize; i++)
	{
		dataInEnd >> endArr[i]; 
	} 
	dataInMiddle.close();

	// print contents
	cout << inputFileNum << " contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << numArr[i];
	}
	cout << endl;
  
	cout << inputFileEarly << " contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << earlyArr[i];
	}
	cout << endl;
  
	cout << inputFileMiddle << " contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << middleArr[i];
	}
	cout << endl;
  
	cout << inputFileEnd << " contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << endArr[i];
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
}

/*****************************************************************************************
void Sort::simpleSearch()
Description: This function performs a simple linear search for an integer input by the user
for each of the 4 arrays containing the txt integer values. A message is printed
indicating whether the value was found for each of the 4 arrays. 
Sources: Week 8 Lecture
*****************************************************************************************/
void Sort::simpleSearch()
{
	int searchVal = 0;
	int count = 0;

	cout << "----------------------------------------------" << endl;
	cout << "2. Simple Search" << endl;
	cout << "Please enter an integer value from -100000 to 100000 to search for." << endl;
	searchVal = validateInput();

	// num.txt 
	cout << inputFileNum << ": ";
	for (int i = 0; i < arrSize; i++)
	{
		if (numArr[i] == searchVal)
		{
			count++;
		}
	}
	if (count)
	{
		cout << "target value found" << endl;
	}
	else 
	{
		cout << "target value not found" << endl;
	}
	count = 0;	

	// early.txt 
	cout << inputFileEarly << ": ";
	for (int i = 0; i < arrSize; i++)
	{
		if (earlyArr[i] == searchVal)
		{
			count++;
		}
	}
	if (count)
	{
		cout << "target value found" << endl;
	}
	else 
	{
		cout << "target value not found" << endl;
	}
	count = 0;	

	// middle.txt 
	cout << inputFileMiddle << ": ";
	for (int i = 0; i < arrSize; i++)
	{
		if (middleArr[i] == searchVal)
		{
			count++;
		}
	}
	if (count)
	{
		cout << "target value found" << endl;
	}
	else 
	{
		cout << "target value not found" << endl;
	}
	count = 0;	

	// end.txt 
	cout << inputFileEnd << ": ";
	for (int i = 0; i < arrSize; i++)
	{
		if (endArr[i] == searchVal)
		{
			count++;
		}
	}
	if (count)
	{
		cout << "target value found" << endl;
	}
	else 
	{
		cout << "target value not found" << endl;
	}
	cout << "----------------------------------------------" << endl;
	cout << endl;
}

/*****************************************************************************************
void Sort::sortTxtFiles()
Description: This function uses a bubble sort algorithm to sort each of the text input
files. The function asks the user to enter the name of the output file to output the 
sorted text file to, then function sorts the input file and then outputs the sorted 
integers to that file. 
Sources: Textbook Ch 9, Pg 615
https://stackoverflow.com/questions/11872302/array-of-strings-to-output-file
*****************************************************************************************/
void Sort::sortTxtFiles()
{
	int temp = 0;
	bool madeSwap;

	cout << "----------------------------------------------" << endl;
	cout << "3. Bubble Sort" << endl;
	cout << "Please enter the name of the file to output the sorted num.txt to." << endl;
	std::getline(cin, outputFileNum); 
	cout << endl;
	cout << "Please enter the name of the file to output the sorted early.txt to." << endl;
	std::getline(cin, outputFileEarly); 
	cout << endl;
	cout << "Please enter the name of the file to output the sorted middle.txt to." << endl;
	std::getline(cin, outputFileMiddle); 
	cout << endl;
	cout << "Please enter the name of the file to output the sorted end.txt to." << endl;
	std::getline(cin, outputFileEnd); 

	// num.txt
	// sort values	
	do
	{
		madeSwap = false;
		for (int i = 0; i < (arrSize - 1); i++)  	
		{
			if (numArr[i] > numArr[i+1])
			{
				temp = numArr[i];
				numArr[i] = numArr[i+1];
				numArr[i+1] = temp;
				madeSwap = true; 
			}
		}
	} while (madeSwap);
	// output sorted values to user-specified file
	ofstream numOut;
	numOut.open(outputFileNum);
	for (int i = 0; i < arrSize; i++)
	{
		numOut << numArr[i] << endl;		
	}
	numOut.close();

	// early.txt
	// sort values	
	do
	{
		madeSwap = false;
		for (int i = 0; i < (arrSize - 1); i++)  	
		{
			if (earlyArr[i] > earlyArr[i+1])
			{
				temp = earlyArr[i];
				earlyArr[i] = earlyArr[i+1];
				earlyArr[i+1] = temp;
				madeSwap = true; 
			}
		}
	} while (madeSwap);
	// output sorted values to user-specified file
	ofstream earlyOut;
	earlyOut.open(outputFileEarly);
	for (int i = 0; i < arrSize; i++)
	{
		earlyOut << earlyArr[i] << endl;		
	}
	earlyOut.close();
	
	// middle.txt
	// sort values	
	do
	{
		madeSwap = false;
		for (int i = 0; i < (arrSize - 1); i++)  	
		{
			if (middleArr[i] > middleArr[i+1])
			{
				temp = middleArr[i];
				middleArr[i] = middleArr[i+1];
				middleArr[i+1] = temp;
				madeSwap = true; 
			}
		}
	} while (madeSwap);
	// output sorted values to user-specified file
	ofstream middleOut;
	middleOut.open(outputFileMiddle);
	for (int i = 0; i < arrSize; i++)
	{
		middleOut << middleArr[i] << endl;		
	}
	middleOut.close();

	// end.txt
	// sort values	
	do
	{
		madeSwap = false;
		for (int i = 0; i < (arrSize - 1); i++)  	
		{
			if (endArr[i] > endArr[i+1])
			{
				temp = endArr[i];
				endArr[i] = endArr[i+1];
				endArr[i+1] = temp;
				madeSwap = true; 
			}
		}
	} while (madeSwap);
	// output sorted values to user-specified file
	ofstream endOut;
	endOut.open(outputFileEnd);
	for (int i = 0; i < arrSize; i++)
	{
		endOut << endArr[i] << endl;		
	}
	endOut.close();

	// print contents
	cout << inputFileNum << " sorted contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << numArr[i];
	}
	cout << endl;
	
	cout << inputFileEarly << " sorted contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << earlyArr[i];
	}
	cout << endl;
	
	cout << inputFileMiddle << " sorted contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << middleArr[i];
	}
	cout << endl;
	
	cout << inputFileEnd << " sorted contents: ";
	for (int i = 0; i < arrSize; i++)
	{
		cout << endArr[i];
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl;
}

/*****************************************************************************************
void Sort::binarySearch()
Description: This function searches the sorted arrays using a binary search algorithm.
Like the simpleSearch() function, a message is printed if the target value is found or not.
Sources: Textbook, Ch9, Pg 607 
*****************************************************************************************/
void Sort::binarySearch()
{
	int search = 0;	
	int count = 0;
	int searchVal = 0;
	
	cout << "----------------------------------------------" << endl;
	cout << "4. Binary Search" << endl;
	cout << "Please enter an integer value from -100000 to 100000 to search for." << endl;
	searchVal = validateInput();
	
	// num.txt
	int first = 0;
	int last = arrSize - 1;
	int middle;
	bool found = false;
	while(!found &&	first <= last)
	{
		middle = (first + last)/2;
		if (numArr[middle] == searchVal)
		{
			found = true;
		}
		else if (numArr[middle] > searchVal)
		{
			last = middle - 1; 
		}
		else 
		{
			first = middle + 1;
		}
	}
	if (found)
	{
		cout << outputFileNum << ": target value found" << endl;
	}
	else 
	{
		cout << outputFileNum << ": target value not found" << endl;
	}
	
	// early.txt
	first = 0;
	last = arrSize - 1;
	middle = 0;
	found = false;
	while(!found &&	first <= last)
	{
		middle = (first + last)/2;
		if (earlyArr[middle] == searchVal)
		{
			found = true;
		}
		else if (earlyArr[middle] > searchVal)
		{
			last = middle - 1; 
		}
		else 
		{
			first = middle + 1;
		}
	}
	if (found)
	{
		cout << outputFileEarly << ": target value found" << endl;
	}
	else 
	{
		cout << outputFileEarly << ": target value not found" << endl;
	}
	
	// middle.txt
	first = 0;
	last = arrSize - 1;
	middle = 0;
	found = false;
	while(!found &&	first <= last)
	{
		middle = (first + last)/2;
		if (middleArr[middle] == searchVal)
		{
			found = true;
		}
		else if (middleArr[middle] > searchVal)
		{
			last = middle - 1; 
		}
		else 
		{
			first = middle + 1;
		}
	}
	if (found)
	{
		cout << outputFileMiddle << ": target value found" << endl;
	}
	else 
	{
		cout << outputFileMiddle << ": target value not found" << endl;
	}
	
	// end.txt
	first = 0;
	last = arrSize - 1;
	middle = 0;
	found = false;
	while(!found &&	first <= last)
	{
		middle = (first + last)/2;
		if (endArr[middle] == searchVal)
		{
			found = true;
		}
		else if (endArr[middle] > searchVal)
		{
			last = middle - 1; 
		}
		else 
		{
			first = middle + 1;
		}
	}
	if (found)
	{
		cout << outputFileEnd << ": target value found" << endl;
	}
	else 
	{
		cout << outputFileEnd << ": target value not found" << endl;
	}
	
	cout << "----------------------------------------------" << endl;
}

/*****************************************************************************************
int Sort::validateInput()
Description: This function checks the user's input value to be an integer within a range
of -100000 to 100000. If it is not, then an error message is printed, and user must 
enter a new value. The valid input is then returned.
*****************************************************************************************/
int Sort::validateInput()
{
	string choice;
	int c;

	// input validation
	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("-0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter integer between -100000 and 100000" << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < -100000) || (c > 100000))
		{
			cout << "Error. Please enter integer between -100000 and 100000" << endl;
		}
	} while ((c < -100000) || (c > 100000));
	return c;
}
