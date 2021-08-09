/***************************************************************************************************
* Program name:		inputval.cpp 
* Group:                Group 18 
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the header file for the inputval functions for the 
*                       Predator-Prey Game.
***************************************************************************************************/
#include "inputval.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::atoi;

/***************************************************************************************************
int inputVal(int mini, int maxi)
The following code was found from: https://github.com/jeinhorn787/Langtons-Ant
I modified some of it and added isRange function
Description: This function checks input validation for an integer within a specified range. 
***************************************************************************************************/
int inputVal(int mini, int maxi)
{
	// allowed input range
	int minimum = mini;
	int maximum = maxi;
	bool isInt = false,
	goodRange = false;

	string input = ""; // takes input as string
	int integer = 0; // this int variable will hold the integer value of the converted string

	do
	{
        std::getline(cin, input);
		while (cin.fail() || input.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Please enter a positive integer between " 
		 	     << minimum << " and " 
			     << maximum << endl;
			if (input.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n'); 
			} 
			std::getline(cin, input);
		}
		
        if(isdigit(input[0]))
          {
              integer = std::stoi(input);
          }
		
        if ((integer < minimum) || (integer > maximum))
		{
			cout << "Please enter a positive integer between " 
		 	     << minimum << " and " 
			     << maximum << endl;
		}
        if(integer >= minimum && integer <= maximum)
        {
            goodRange = true;
        }

	} while (goodRange == false && integer < minimum || integer > maximum);
	return integer; 
}

/***************************************************************************************************
bool isUnsignedInt(string input)
Description: This function checks through loop if all characters in string is a number
***************************************************************************************************/
bool isUnsignedInt(string input)
{
    // Bool flag to prevent multiple jumps
	bool truth = false;
    int size = input.size();

	for (int i=0; i < size; i++)
	{
		if (isdigit(input[i]))
			truth = true; // return true if all characters are a number 0-9
		else
			truth = false; // otherwise return false
	}
	return truth;
}
// end of the code

/***************************************************************************************************
bool isRange(int in, int mini, int maxi)
Description: This function checks if input is in range. If it is not in range, it returns false.
***************************************************************************************************/
bool isRange(int in, int mini, int maxi)
{
    // Use a flag variable to prevent multiple returns and
    // conditional jumps.
    bool flag = true;
    int input = in;

    if (input < mini)
    {
        flag = false;
    }

	if (input > maxi)
    {
        flag = false;
    }
	
	return flag;
}
