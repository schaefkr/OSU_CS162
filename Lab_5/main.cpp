/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			5-5-2019
* Description:		This file contains the main function for Lab5.
* Sources:
* Textbook ch 3, ch 14
* https://www.geeksforgeeks.org/reverse-a-string-using-recursion/
* https://stackoverflow.com/questions/15801957/recursive-sum-of-an-array-in-c
*****************************************************************************************/

#include "menu.hpp"
#include "recursive.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	int c, arrSize, num, sum = 0;
	string inputString; 

	do
	{
		c = mainMenu();
		if (c == 1)
		{
			// prompt the user to enter a string 
			// program recursively prints string backwards
			cout << "Please enter the string you would like to print in reverse." << endl;	
			std::getline(cin, inputString);
			cout << "Your string in reverse is: " << endl;
			reverseString(inputString);
			cout << endl;
			cout << endl;
		}
		else if (c == 2)
		{
			// prompt the user to input an integer for the array size
			// and to enter the integers to fill the array
			cout << "How many integers would you like to sum?" << endl;
			arrSize = validateArrayInput();
			int userArray[arrSize];
			int *userArrayPtr = userArray; 
			cout << "Please enter " << arrSize << " integers." << endl;
			for (int i = 0; i < arrSize; i++)
			{
 				userArray[i] = validateArrayInput(); 
			}
			sum = sumIntArray(userArrayPtr, arrSize);
			cout << "The sum is " << sum << "." << endl;
			cout << endl;
		}
		else if (c == 3)
		{
			// prompt the user to input an integer 
			// print the triangular number 
			cout << "Please enter the integer you would like to calculate the "
			     << "triangular number of." << endl;
			num = validateTriangleInput();
			cout << "The triangular number of " << num << " is "
			     << triangleNumber(num) << "." << endl;
			cout << endl;
		}
		else 
		{
			return 0;
		}	
	} while ((c >= 1) && (c < 4)); 

	return 0;
}
