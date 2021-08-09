/******************************************************************************************
** Program name:	menu.cpp
** Author:		Kristin Schaefer
** Date:		04-14-2019
** Description:		This file contains the source file for the menu function for the 
			Langton's Ant Simulation.	
******************************************************************************************/

#include "menu.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdint.h>
#include <limits.h>

#include <iomanip>

/*****************************************************************************************
*              				menuStart      	 
* This function displays the start menu options to the user and then asks the user to
* input an int option. The function completes input validation and displays the menu 
* again if the user does not enter a valid input.
* https://stackoverflow.com/questions/18567483/c-checking-for-an-integer#18567586
******************************************************************************************/

// source for do-while loop format: Starting out with C++, by 
// Gaddis, Walters & Muganda, page 265-269
// souce for menu function https://www.youtube.com/watch?v=fxRE5fHTYJg 

bool menuStart()
{
	bool play; 
	int c;	

	cout << "1. Start Langton's Ant Simulation" << endl; 
	cout << "2. Quit" << endl; 

	do
	{
		cin >> std::setw(1) >> c;
		if (std::cin.good())
		{
			if ((c > 2) || (c < 1))
			{
				cout <<	"Please enter 1 or 2." << endl;
			}

			else if (c == 1)
			{
				play = true;
			}

			else if (c == 2)
			{
				play = false;
			}
		}
		else
		{
			cout << "Please enter 1 or 2." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		} 
	} while (!std::cin.good() || (c > 2) || (c < 1));  
	return play;
}

/******************************************************************************************
*                      			 menuPlayAgain        
* This function displays the play again menu options to the user and then asks the user to
* input an int option. The funciton completes input validation and displays the menu again
* if the user does not enter a valid input.
* https://stackoverflow.com/questions/18567483/c-checking-for-an-integer#18567586
******************************************************************************************/

bool menuReplay()
{
	bool playAgain;
	int c;

	do 
	{
		cout << "1. Play again" << endl;
		cout << "2. Quit" << endl;
		cin >> std::setw(1) >> c;
		if (std::cin.good())
		{
			if ((c > 2) || (c < 1))
			{
				cout << "Please enter 1 or 2:" << endl;
			}
			else if (c == 1)
			{
				playAgain = true;
			}	
			else if (c == 2)
			{
				playAgain = false;	
			}
		}
		else
		{
			cout << "Please enter 1 or 2." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	} while (!std::cin.good() || (c > 2) || (c < 1));
	return playAgain;
}
