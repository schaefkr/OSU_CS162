/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			5-26-2019
* Description:		This file contains the source file for the menu function. It has
* a function for the starting menu of the tournament, startMenu(), a function to get the 
* number of team players per team, menuTeamSize(), a function to get the name of each 
* Character, menuCharacter(), a function to ask the user if they would like to play the
* tournament again, playAgain(), and a function to ask the user if they would like to 
* print the loser pile. 
******************************************************************************************/

#include "menu.hpp"
#include "game.hpp"
#include <iostream>
#include <cctype>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
bool startMenu(Game *gamePtr)
Description: This function prints a start menu asking the user if they would like to
1. Play or 2. Exit (the program). The function then gets the user's choice and validates
the input. If the user's input is invalid an error message is printed and the user must 
enter another value until they enter a valid choice of 1 or 2. After the user enters a 
valid choice, the function assigns a boolean value to the user's choice and then returns
that value.
******************************************************************************************/
bool startMenu()
{
	string choice;
	int c;

	cout << "1. Play" << endl; 
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

	// play game
	if (c == 1)
	{
		return true;
	}
	// exit game
	else
	{
		return false;
	}
}

/******************************************************************************************
int menuTeamSize()
Description: This function prints a menu asking the user to enter the number of team 
players for both teams. The function validates the user's input. If the user does not enter
a valid input, an error message is printed and the user must enter their choice until it is 
valid.
******************************************************************************************/
int menuTeamSize()
{
	string choice;
	int c;
	
	cout << "Please enter the number of players for each team." << endl; 
	cout << "The minimum number of players per team is 1." << endl; 
	cout << "The maximum number of players per team is 20." << endl; 
	
	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a positive integer." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n'); 
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 20))
		{
			cout << "Error. Please enter a positive integer." << endl;
		}
	} while ((c < 1) || (c > 20));
	return c;
} 

/******************************************************************************************
int menuCharacter(int playerNum)
Description: This function prints a menu asking the user to enter the number of Character 
type for all players. The function validates the user's input. If the user does not enter
a valid input, an error message is printed and the user must enter their choice until it is 
valid. 
******************************************************************************************/
int menuCharacter(int playerNum)
{
	string choice;
	int c;
	int index = playerNum;

	cout << "Please choose the player type for Player " << index << ":" << endl; 

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

/******************************************************************************************
string menuPlayerName(int playerNum)
Description: This function gets the user's input for each Character name for each player. 
******************************************************************************************/
string menuPlayerName(int playerNum)
{
	string choice;
	int index = playerNum;

	cout << "Please enter the name for Player " << index << ":" << endl;
	std::getline(cin, choice);
	return choice; 
}

/******************************************************************************************
bool playAgain()
Description: This function asks the user if they would like to play the 
game again and returns a boolean value indicating their choice.
******************************************************************************************/
bool playAgain()
{
	string choice;	
	int c = 0;

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
		return true;	
	}	
	else 
	{	
		return false;
	}
}


/******************************************************************************************
bool menuPrintLoserPile()
Description: This function prints a menu asking the user to enter 1.Print loser pile 
or 2.Exit. The function validates the user's input. If the user does not enter
a valid input, an error message is printed and the user must enter their choice until it is 
valid.
******************************************************************************************/
bool menuPrintLoserPile()
{
	string choice;	
	int c = 0;

	cout << endl;
	cout << "Would you like to print the loser pile?" << endl;	
	cout << "1. Yes" << endl; 
	cout << "2. No" << endl; 

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
		return true;	
	}	
	else 
	{	
		return false;
	}
}
