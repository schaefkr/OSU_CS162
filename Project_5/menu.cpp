/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			6-11-2019
* Description:		This file contains the source file for the Menu function.
*			It defines a function for the starting menu, menuStart(), a
*			function to get the user's direction choice for the map, 
*			menuDirection(), a function to get the user's shop action choice, 
*			menuShop(), and a validation function, menuValidation(), used by
*			all of the menu functions to check that the user's input is valid.
******************************************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include "space.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
bool menuStart(Game *gamePtr)
Description: This function prints a start menu asking the user if they would like to
1. Play 2. Exit (the program). The function gets the user's choice and validates the input
with the menuValidation() function. If the input = 1 the Game startGame() function is
called to begin the simulation. If the input = 2, a false boolean value is returned.
******************************************************************************************/
bool menuStart(Game *gamePtr)
{
	int input = 0;

	// display menu	
	cout << "1. Play" << endl; 
	cout << "2. Exit" << endl; 

	// validate input
	input = menuValidation(1,2); 
	
	if (input == 1)
	{
		// start game 
		gamePtr->startGame();	
		return true; 	
	} 
	else 
	{
		return false;
	}
}

/******************************************************************************************
int menuDirection(Space *posPtr)
Description: This function prints the menu direction options based on the Game map.
It checks for nullptrs, and if the pointer is equal to nullptr, then the option is not 
printed. The function then uses the menuValidation() function to get the user's direction
selection. A while loop checks that the input is not the direction of a nullptr. Then 
the user's input is returned as an integer value.
******************************************************************************************/
int menuDirection(Space *posPtr)
{
	bool invalid = false;	
	int input = 0;

	// display menu
	cout << "Which direction would you like to go?" << endl;	
	if (posPtr->getUp() != nullptr)
	{
		cout << "1. Up: " << posPtr->getUp()->getSpaceType() << endl; 
	}
	if (posPtr->getRight() != nullptr)
	{
		cout << "2. Right: " << posPtr->getRight()->getSpaceType() << endl; 
	}
	if (posPtr->getDown() != nullptr)
	{
		cout << "3. Down: " << posPtr->getDown()->getSpaceType() << endl; 
	}
	if (posPtr->getLeft() != nullptr)
	{
		cout << "4. Left: " << posPtr->getLeft()->getSpaceType() << endl; 
	}

	input = menuValidation(1,4); 

	// check directions valid for input	
	do
	{
		if ((posPtr->getUp() == nullptr) && (input == 1))
		{
			invalid = true;
			cout << "Error. You cannot move up on the map." << endl;
			input = menuValidation(1,4); 
		}
		else if ((posPtr->getRight() == nullptr) && (input == 2))
		{
			invalid = true;
			cout << "Error. You cannot move right on the map." << endl;
			input = menuValidation(1,4); 
		}
		else if ((posPtr->getDown() == nullptr) && (input == 3))
		{
			invalid = true;
			cout << "Error. You cannot move down on the map." << endl;
			input = menuValidation(1,4); 
		}
		else if ((posPtr->getLeft() == nullptr) && (input == 4))
		{
			invalid = true;
			cout << "Error. You cannot move left on the map." << endl;
			input = menuValidation(1,4); 
		}
		else 
		{
			invalid = false;
		}
	} while (invalid);

	return input;
}

/******************************************************************************************
int menuShop()
Description: This function prints the menu options for the Shop function spaceEvent().
It uses the menuValidation() function to get and to check that the user input is valid and
then returns the user's choice as an integer. 	
******************************************************************************************/
int menuShop()
{
	int input = 0;

	// display menu
	cout << "1. Buy coffee" << endl; 
	cout << "2. Buy donuts" << endl; 
	cout << "3. Withdraw money from the ATM" << endl; 
	cout << "4. Continue on your way to work" << endl; 
	
	// validate input
	input = menuValidation(1,4);	

	return input;
}

/******************************************************************************************
int menuValidation(int min, int max)	
Description: The function gets the user's choice and checks that it is valid and within the
range passes as min and max parameters. If the user's input is invalid or out of range, 
an error message is printed and the user must enter another value until they enter a valid 
a valid choice. After the user enters a valid choice, the int value is returned.
******************************************************************************************/
int menuValidation(int min, int max)	
{
	//Source for input validation: Piazza, Code Sharing: Lab 5, student Nathan Johnson
	int input = 0;
	bool validInput = false;
	
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
			
			if (rangeCheck >= min && rangeCheck <= max)
			{
				input = rangeCheck;
				validInput = true;
			}
			else 
			{
				cout << endl;
				cout << "Please enter " << min <<  " or " << max << "." << endl;
			}
		}
		else
		{
			cout << endl;
			cout << "Please enter " << min <<  " or " << max << "." << endl;
		}
	}
	return input;
}	
