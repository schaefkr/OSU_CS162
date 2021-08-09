/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			5-12-2019
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

	cout << "1. Vampire" << endl; 
	cout << "2. Barbarian" << endl; 
	cout << "3. Blue Men" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Harry Potter" << endl;
	cout << endl;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("12345") !=std::string::npos)
		{
			cout << "Error. Please enter 1, 2, 3, 4 or 5." << endl;
			if (choice.find_first_not_of("12345") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n'); 
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 5))
		{
			cout << "Error. Please enter 1, 2, 3, 4 or 5." << endl;
		}
	} while ((c < 1) || (c > 5));
	return c;
}

/***************************************************************************
bool playAgain()
Description: This function asks the user if they would like to play the 
game again and returns a boolean value indicating their choice.
***************************************************************************/
bool playAgain()
{
	string choice;	
	int c = 0;
	bool playAgain;

	cout << endl;
	cout << "Would you like to keep playing?" << endl;	
	cout << "1. Play again." << endl; 
	cout << "2. Exit" << endl; 

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("12") !=std::string::npos)
		{
			cout << "Error. Please enter 1 or 2." << endl;
			if (choice.find_first_not_of("12") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 2))
		{
			cout << "Error. Please enter 1 or 2." << endl;
		}
	} while ((c < 1) || (c > 2));	
	
	if (c == 1)
	{
		playAgain = true;
	}	
	else 
	{	
		playAgain = false;
	}
	return playAgain;
}
