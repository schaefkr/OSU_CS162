/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			6-9-2019
* Description:		This file contains the source file for the Menu functions.
* It defines the starting menu function, menuStart(), and the menu function to get the 
* integer N for the Fibonacci functions, menuN(). Both functions check that the user input
* is valid.  
******************************************************************************************/

#include "menu.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
bool menuStart()
Description: This function prints a start menu asking the user if they would like to
1. Fibonacci Calculation 2. Exit (the program). The function gets the user's choice and
validates the input. If the user's input is invalid an error message is printed and the user
must enter another value until they enter a valid choice of 1 or 2. After the user enters a 
valid choice, the function assigns a boolean value to the user's choice and then returns
that boolean value (1 = true, 2 = false).
Source: Piazza, Code Sharing: Lab 5, student Nathan Johnson
******************************************************************************************/
bool menuStart()
{
	int input = 0;
	bool validInput = false;

	cout << endl;	
	cout << "1. Fibonacci Numbers Calculation" << endl; 
	cout << "2. Exit" << endl; 
	cout << endl;

	// source : Piazza, Code Sharing: Lab 5, student Nathan Johnson	
	while (!validInput)
	{
		bool error = false;
		string tempIn;
		std::getline(cin, tempIn);

		for (unsigned i = 0; i < tempIn.length(); i++)
		{
			char cTemp = tempIn[i];
			if (cTemp < '0' || cTemp > '9')
			{
				error = true;
			}
		}

		if (!error)
		{
			int rangeCheck = 0;
			std::stringstream ss(tempIn);
			ss >> rangeCheck;
			
			if (rangeCheck >= 1 && rangeCheck <= 2)
			{
				input = rangeCheck;
				validInput = true;
			}
			else 
			{
				cout << endl;
				cout << "Please enter 1 or 2." << endl;
			}
		}
		else
		{
			cout << endl;
			cout << "Please enter 1 or 2." << endl;
		}
	}
	
	if (input == 1)
	{
		return true; 	
	} 
	else 
	{
		return false;
	}
}

/******************************************************************************************
int menuN()
Description: This function gets a user input for the integer N to be used for the 
recursive and iterative Fibonacci functions. It checks that the user input is a valid
integer within the range of 1 to 45 and then returns that integer. If the integer is not 
valid an error message is printed and the user must re-enter an integer until it is valid.
Source: Piazza, Code Sharing: Lab 5, student Nathan Johnson
******************************************************************************************/
int menuN()
{
	int input = 0;
	bool validInput = false;
	
	cout << "Please enter a number from 1 to 45 for N." << endl; 

	// source : Piazza, Code Sharing: Lab 5, student Nathan Johnson	
	while (!validInput)
	{
		bool error = false;
		string tempIn;
		std::getline(cin, tempIn);

		for (unsigned i = 0; i < tempIn.length(); i++)
		{
			char cTemp = tempIn[i];
			if (cTemp < '0' || cTemp > '9')
			{
				error = true;
			}
		}

		if (!error)
		{
			int rangeCheck = 0;
			std::stringstream ss(tempIn);
			ss >> rangeCheck;
			
			if (rangeCheck >= 1 && rangeCheck <= 45)
			{
				input = rangeCheck;
				validInput = true;
			}
			else 
			{
				cout << endl;
				cout << "Please enter a number from 1 to 45." << endl;
			}
		}
		else
		{
			cout << endl;
			cout << "Please enter a number from 1 to 45." << endl;
		}
	}
	return input;	
}
