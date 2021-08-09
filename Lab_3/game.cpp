/******************************************************************************************
* Program name:		game.cpp
* Author:		Kristin Schaefer
* Date:			04-21-2019
* Description:		This file contains the source file for the Game class.
* Sources:
* https://stackoverflow.com/questions/18567483/c-checking-for-an-integer#18567586
* https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
******************************************************************************************/

#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
#include <iostream>
#include <cctype>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*****************************************************************************************
*                      			 Game()        
* Parameters: The constructor takes two pointers to two Die objects created in main.
* Description: This is the default constructor for a Game object.  
******************************************************************************************/
Game::Game(Die *player1, Die *player2)
{
	ptrDie1 = player1;
	ptrDie2 = player2; 
}

/*****************************************************************************************
*              				gameMenu()      	 
* Description: This function displays the start menu options to the user and then asks the 
* user to input an int option. The function completes input validation and displays the 
* menu again if the user does not enter a valid input.
******************************************************************************************/
bool Game::gameMenu()
{
	string choice;
	int c;
	bool play;
	
	cout << "1. Play dice war game" << endl; 
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
		play = true;
	}	
	else 
	{	
		play = false;
	}
	return play;
}

/******************************************************************************************
*                      			 setRounds()        
* Description: This function asks the user to input a integer number of rounds and tests
* the input validity. If the user does not enter a valid input, an error message is
* displayed, and the user is asked to enter a new input. 
******************************************************************************************/
void Game::setRounds()
{
	string inRounds;
	
	cout << "Please enter the number of rounds you would like to play (max 10000)." << endl;
	do
	{
		std::getline(cin, inRounds);
		while (std::cin.fail() || inRounds.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a positive number from 1 to 10000." << endl;
			if (inRounds.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, inRounds);
		}
		rounds = std::stoi(inRounds);
		if ((rounds < 1) || (rounds > 10001))
		{
			cout << "Error. Please enter a positive number from 1 to 10000." << endl;
		}
	} while ((rounds < 1) || (rounds > 10001));
}

/******************************************************************************************
*                      			 setDieType()        
* Description: This function asks the user to enter the die type, 1 for normal or 2 for
* loaded, and tests the input validity. If the user does not enter a valid input, an error
* message is displayed, and the user is asked to enter a new input. 
******************************************************************************************/
void Game::setDieType()
{
	string p1Type;
	string p2Type;

	// Player 1
	cout << "Please enter the die type for Player 1." << endl;
	cout << "1.Normal\n2.Loaded" << endl;
	do
	{
		std::getline(cin, p1Type);
		while (std::cin.fail() || p1Type.find_first_not_of("12") !=std::string::npos)
		{
			cout << "Error. Please enter 1 or 2." << endl;
			if (p1Type.find_first_not_of("12") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, p1Type);
		}
		p1DieType = std::stoi(p1Type);
		if ((p1DieType < 1) || (p1DieType > 2))
		{
			cout << "Error. Please enter 1 or 2." << endl;
		} 
	} while ((p1DieType < 1) || (p1DieType > 2));

	if (p1DieType == 2)
	{
		ptrDie1 = new LoadedDie(1);	
	}

	// Player 2 
	cout << "Please enter the die type for Player 2." << endl;
	cout << "1.Normal\n2.Loaded" << endl;
	do
	{
		std::getline(cin, p2Type);
		while (std::cin.fail() || p2Type.find_first_not_of("12") !=std::string::npos)
		{
			cout << "Error. Please enter 1 or 2." << endl;
			if (p2Type.find_first_not_of("12") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, p2Type);
		}
		p2DieType = std::stoi(p2Type);
		if ((p2DieType < 1) || (p2DieType >2))
		{
			cout << "Error. Please enter 1 or 2." << endl;
		}	
	} while ((p2DieType < 1) || (p2DieType > 2));

	if (p2DieType == 2)
	{
		ptrDie2 = new LoadedDie(1);	
	}
}

/******************************************************************************************
*                      			 setNumSides()        
* Description: This function asks the user to enter the number of sides of the die.
* If the user does not enter a valid input, an error message is displayed, and the user is
* asked to enter a new input. 
******************************************************************************************/
void Game::setNumSides()
{
	string p1Sides;
	string p2Sides;
	
	// Player 1
	cout << "Please enter the number of sides for the die of Player 1." << endl; 
	do
	{
		std::getline(cin, p1Sides);
		while (std::cin.fail() || p1Sides.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a positive number from 1 to 10000." << endl;
			if (p1Sides.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, p1Sides);
		}
		p1NumSides = std::stoi(p1Sides);
		if ((p1NumSides < 1) || (p1NumSides > 10001))
		{
			cout << "Error. Please enter a positive number from 1 to 10000." << endl;
		}
	} while ((p1NumSides < 1) || (p1NumSides > 10001));
	ptrDie1->setNumSides(p1NumSides);
	
	// Player 2 
	cout << "Please enter the number of sides for the die of Player 2." << endl; 
	do
	{
		std::getline(cin, p2Sides);
		while (std::cin.fail() || p2Sides.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a positive number from 1 to 10000." << endl;
			if (p2Sides.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, p2Sides);
		}
		p2NumSides = std::stoi(p2Sides);
		if ((p2NumSides < 1) || (p2NumSides > 10001))
		{
			cout << "Error. Please enter a positive number from 1 to 10000." << endl;
		} 
	} while ((p2NumSides < 1) || (p2NumSides > 10001));
	ptrDie2->setNumSides(p2NumSides);
}

/******************************************************************************************
*                      			 playGame()        
* Description: This function contains all of the function calls used to play the war game.
* After each round, the current results of the game are displayed. At the end of the game, 
* the final scores and the winner are displayed.
******************************************************************************************/
void Game::playGame()
{
	p1Score = 0;
	p2Score = 0;

	// roll dice
	for (currentRound = 1; currentRound < rounds + 1 ; currentRound++)
	{
		ptrDie1->getDieRoll(currentRound);
		ptrDie2->getDieRoll(currentRound);

		// update score
		p1Score += ptrDie1->getCurrentSide();
		p2Score += ptrDie2->getCurrentSide(); 			

		// round output
		cout << "*****************************" << endl;
		cout << "Round " << currentRound << endl;
		cout << endl;
		cout << "Player 1:\n" << "Die type: " << ptrDie1->getDieType() << endl;
		cout << "Number of sides: " << p1NumSides << endl;
		cout << "Number rolled: " << ptrDie1->getCurrentSide() << endl;
		cout << "Score: " << p1Score << endl;
		cout << endl;
		cout << "Player 2:\n" << "Die type: " << ptrDie2->getDieType() << endl;
		cout << "Number of sides: " << p2NumSides << endl;
		cout << "Number rolled: " << ptrDie2->getCurrentSide() << endl;
		cout << "Score: " << p2Score << endl;
		cout << "*****************************" << endl;
		cout << endl;
	} 
	
	// final score output
	cout << "*****************************" << endl;
	cout << "Final Results" << endl;
	cout << endl;
	cout << "Player 1: " << p1Score << endl;
	cout << "Player 2: " << p2Score << endl; 	
	if (p1Score > p2Score)
	{
		cout << "The winner is ";
		cout << "Player 1." << endl;
	}
	else if (p2Score > p1Score)
	{
		cout << "The winner is ";
		cout << "Player 2." << endl;
	} 
	else 
	{
		cout << "Tie game." << endl;
	}
	cout << "*****************************" << endl;
}

/******************************************************************************************
*                      			~Game()       
* Description: This is the destructor for Game. It deallocates the memory for the
* loadedDie pointers and sets the die pointers to null. 
******************************************************************************************/
Game::~Game()
{
	if (p1DieType == 1)
	{
		ptrDie1 = NULL;
	}
	else if (p1DieType == 2)
	{
		delete ptrDie1;
		ptrDie1 = NULL;	
	}
	if (p2DieType == 1)
	{
		ptrDie2 = NULL;
	}
	else if (p2DieType == 2)
	{
		delete ptrDie2;
		ptrDie2 = NULL;
	}
}

