/***********************************************************************
Program name:        letters.hpp
Author:              Kristin Schaefer
Date:                04-14-2019
Description:         This is the source file for lab 2. It provides
                     the function definitions for the functions
                     count_letters() and output_letters().   
***********************************************************************/

#include "letters.hpp"
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

/***********************************************************************
             		      count_letters
Parameters: The count_letters function takes an input file stream 
variable and a pointer to an array of integers that contains the letter
frequencies. 
Description: This function reads the paragraph string from the input
file stream, then counts the letter frequencies of that paragraph and 
stores the frequencies of the characters in the array. It disregards
the case of the letters. 
***********************************************************************/

void count_letters(ifstream& inFile, int* letterArray)
{
	char ch;
	string line;
	string inputFileName;
	ofstream outFile;	

	// asks user for the filename to output to and open file
	// while error, ask for new filename 
	do
	{
		cout << "Please enter the name of the input file" << 
			", including the .txt extension." << endl;
		cin >> inputFileName;
		inFile.open(inputFileName);

		if (!inFile)
		{
			cout << "Error opening file." << endl;
		}
	} while(!inFile);
	
	// reads the paragraph string from the input file stream 
	// counts the letter frequencies of the paragraph and stores
	while(!inFile.eof()) 	
	{
		getline(inFile, line);
		// loop through line 
		for (int i = 0; i < line.length(); i++)
		{
			if (islower(line[i]))
			{
				char tempChar = line[i];
				int tempInt = static_cast<int>(tempChar) - 97;
				letterArray[tempInt]++;
			} 	
			else if (isupper(line[i]))
			{
				line[i] = tolower(line[i]);
				char tempChar = line[i];
				int tempInt = static_cast<int>(tempChar) - 97;
				letterArray[tempInt]++; 
			}
		}
		// output_letters and set array elements to 0 
		output_letters(outFile, letterArray);
		clear_array(letterArray);	
	}
	inFile.close();
}

/***********************************************************************
             		      output_letters
Parameters: The output_letters function takes an output file stream 
variable and a pointer to an array of integers that contains the letter
frequencies.   
Description: This function asks the user for the filename the user 
would like to output to, then outputs the frequencies of letters to the 
output file.   
***********************************************************************/

void output_letters(ofstream& outFile, int* charArray)
{
	char ch;
	string outputFileName;
 
	// asks user for the filename to output to and open file
	// while error, ask for new filename 
	do
	{
		cout << "Please enter the name of the output file" 
			", including the .txt. extension." << endl;
		cin >> outputFileName;
		outFile.open(outputFileName);

		if(!outFile)
		{
			cout << "Error opening file." << endl;
		} 
	} while(!outFile);
 
	// output the frequencies of letters to the output file
	for (int i = 0; i < 26; i++)
	{
		int tmpInt = i + 97;
		char tmpCh = static_cast<char>(tmpInt);
		outFile << tmpCh << ": " << charArray[i] << "\n" << endl;
	}
	outFile.close();
}

/***********************************************************************
			    clear_array
Parameters: The output_letters function takes a point to an array of 
an array of integers that contains the letter frequenies.
Description: This function clears the letter frequency count of the 
previous paragraph by setting each array element to 0.
***********************************************************************/

void clear_array(int* letArray)
{
	for (int i = 0; i < 26; i++)
	{
		letArray[i] = 0;
	}	  
}



