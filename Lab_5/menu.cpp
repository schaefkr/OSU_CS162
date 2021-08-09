/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			5-5-2019
* Description:		This file contains the source file for the menu function.
******************************************************************************************/

#include "menu.hpp"
#include <iostream>
#include <cctype>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
int mainMenu();	
Description: This function displays the start menu options to the user and then asks the 
user to input an option. The function completes input validation and displays the menu 
again if the user does not enter a valid input.		
******************************************************************************************/
int mainMenu()
{
	string choice;
	int c;

	cout << "1. Print string backwards" << endl; 
	cout << "2. Sum array" << endl; 
	cout << "3. Triangular number" << endl;
	cout << "4. Exit program" << endl;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("1234") !=std::string::npos)
		{
			cout << "Error. Please enter 1, 2, 3 or 4." << endl;
			if (choice.find_first_not_of("1234") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 4))
		{
			cout << "Error. Please enter 1, 2, 3 or 4." << endl;
		}
	} while ((c < 1) || (c > 4));
	return c;
}

/******************************************************************************************
int validateArrayInput();	
Description: This function performs input validation on the integer inputs for the 
sumArray function.  
******************************************************************************************/
int validateArrayInput()
{
	string choice;
	int c;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a positive integer from 1 to 1000." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 1001))
		{
			cout << "Error. Please enter a positive integer from 1 to 1000." << endl;
		}
	} while ((c < 1) || (c > 1001));
	return c;
}

/******************************************************************************************
int validateTriangleInput();	
Description: This function performs input validation on the integer input for the 
triangleNumber function.  
******************************************************************************************/
int validateTriangleInput()
{
	string choice;
	int c;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a positive integer from 1 to 1000." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 1001))
		{
			cout << "Error. Please enter a positive integer from 1 to 1000." << endl;
		}
	} while ((c < 1) || (c > 1001));
	return c;
}
