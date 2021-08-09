/*****************************************************************************************
* Program name:         game.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Game class.
			The Game class controls the overall Game simulation. It has a 
			dynamic 2D array of Space pointers representing the Game map. 
			In addition to having getters and setters for the map Spaces, 
			it defines functions to create the map, setMap(), to print the 
		 	map, printMap(), and to print the current round information, 
			printRound().  	
*****************************************************************************************/

#include "game.hpp"
#include "menu.hpp"
#include "space.hpp"
#include "home.hpp"
#include "work.hpp"
#include "shop.hpp"
#include "bus.hpp"
#include "train.hpp"
#include "walk.hpp"	
#include "player.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*****************************************************************************************
Game::Game()
Description: Constructo. Sets the values for the number of rows and columns of the map, 
sets the bool values atWork and stress to false, sets the Player pointer to the Player
object, and sets the printType for the player's map space.  
*****************************************************************************************/
Game::Game()
{
	rows = 4;
	cols = 4;
	atWork = false;
	stress = false;
	time = true;
	playerPtr = &player1;
	printType = "    You     ";		
}

/*****************************************************************************************
Game::~Game()
Description: Destructor. Deletes the dynamic 2D array of Space pointers. 
*****************************************************************************************/
Game::~Game()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			delete map[r][c];
		}
	}

	for (int r = 0; r < rows; r++)
	{
		delete [] map[r]; 
	}
	
	delete [] map;
}

/*****************************************************************************************
void Game::setMap()
Description: This function creates the array of Spaces representing the map. It then 
sets the up, right, down and left pointers. 
*****************************************************************************************/
void Game::setMap()
{	
	// set array rows
	map = new Space**[rows];
	// set array cols
	for (int i = 0; i < rows; i++)
	{
		map[i] = new Space*[cols]; 
	}	

	int tempNum = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			// make new Home object as starting point
			if ((r == 0) && (c == 0))
			{
				map[r][c] = new Home(playerPtr);
			} 
			// make new Shop object to have at least 1 on map
			else if ((r == 0) && (c == 1))
			{
				map[r][c] = new Shop(playerPtr);
			} 
			// make new Work object as end point
			else if ((r == (rows-1)) && (c == (cols-1)))
			{
				map[r][c] = new Work(playerPtr);
			} 
			// make new Shop, Train, Bus or Walk object randomly
			// to fill in rest of map 
			else 
			{
				tempNum = genRandomNum();
				if (tempNum == 1)
				{
					map[r][c] = new Shop(playerPtr);	
				}
				else if (tempNum == 2)
				{	
				 	map[r][c] = new Train(playerPtr); 
				}	
				else if (tempNum == 3)
				{
					map[r][c] = new Bus(playerPtr);
				}
				else
				{
					map[r][c] = new Walk(playerPtr);
				}
			}
		}
	} 

	// assign up, right, down and left pointers
	for (int ro = 0; ro < rows; ro++)
	{
		for (int co = 0; co < cols; co++)
		{
			// top ptrs
			if (ro == 0)
			{
				map[ro][co]->setUp(0);
			} 
			else
			{
				map[ro][co]->setUp(map[ro-1][co]);	
			}
			// bottom ptrs
			if (ro == (rows-1))
			{
				map[ro][co]->setDown(0);
			}
			else 
			{
				map[ro][co]->setDown(map[ro+1][co]);
			}
			// left ptrs
			if (co == 0)
			{
				map[ro][co]->setLeft(0); 
			}
			else
			{
				map[ro][co]->setLeft(map[ro][co-1]);
			}
			// right ptrs
			if (co == (cols-1))
			{
				map[ro][co]->setRight(0);
			}
			else
			{
				map[ro][co]->setRight(map[ro][co+1]);
			}		
		} 
	}
	
	// set head, tail and playerPos pointers
	head = map[0][0];
	tail = map[rows-1][cols-1];
	playerPos = head;	
}

/*****************************************************************************************
void Game::setHead(Space *headPtr)
Description: This function takes as a parameter a pointer to a Space object and then 
sets the head pointer accordingly. 
*****************************************************************************************/
void Game::setHead(Space *headPtr)
{
	 head = headPtr;
}

/*****************************************************************************************
Space * Game::getHead()
Description: This function returns a Space pointer to the head node. 
*****************************************************************************************/
Space * Game::getHead()
{
	 return head;
}

/*****************************************************************************************
void Game::setTail(Space *tailPtr)
Description: This function takes as a parameter a pointer to a Space object and then 
sets the tail pointer accordingly. 
*****************************************************************************************/
void Game::setTail(Space *tailPtr)
{
	tail = tailPtr;
}

/*****************************************************************************************
Space * Game::getTail()
Description: This function returns a Space pointer to the tail node. 
*****************************************************************************************/
Space * Game::getTail()
{
	 return tail;
}

/*****************************************************************************************
void Game::setPlayerPos(Space *playerPosPtr)
Description: This function takes as a parameter a pointer to a Space object and then 
sets the Player's position pointer accordingly. 
*****************************************************************************************/
void Game::setPlayerPos(Space *playerPosPtr)
{
	 playerPos = playerPosPtr;
}

/*****************************************************************************************
Space * Game::getPlayerPos()
Description: This function returns a Space pointer to the Player's position node. 
*****************************************************************************************/
Space * Game::getPlayerPos()
{
	 return playerPos; 
}

/*****************************************************************************************
void Game::printMap()
Description: This function loops through the 2D array of Space pointers and prints the 
map. When the Player's position equals the current index, the Player's printType is 
printed instead in order to represent the Player's current position on the map.
*****************************************************************************************/
void Game::printMap()
{
	for (int r = 0; r < rows; r++)
	{
		cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
		cout << "|           |           |           |           |" << endl;
		for (int c = 0; c < cols; c++)
		{
			if (map[r][c] == playerPos)
			{
				cout << printType;
			}
			else
			{
				cout << map[r][c]->getPrintType();
			}
		}
		cout << endl;
		cout << "|_ _ _ _ _ _|_ _ _ _ _ _|_ _ _ _ _ _|_ _ _ _ _ _|" << endl;
	}	
}

/*****************************************************************************************
void Game::startGame()
Description: This function controls the overall Game simulation. It prints the Game 
objectives, then creates the map with the setMap() function. The function then starts the 
round simulation with a while loop. The loop continues until the Player reaches work, 
exceeds their stress level (10pts) or runs out of time (1hr). This is set with bool 
variables. To move the Player to the next Space on the map, a menu function,
menuDirection() is called. The Player's position is then updated on the map. Then an 
event based on the derived Space type is called. 
*****************************************************************************************/
void Game::startGame()
{
	int dir = 0;

	// Start instructions 
	cout << "--------------------------------------------------------------" << endl;
	cout << "                   GET TO WORK ON TIME!" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "Welcome to Get to Work on Time." << endl;
	cout << "Your objective is to get to work before 9:00am." << endl;
	cout << "In order to enter your office," << endl; 
	cout << "you must have donuts and coffee in your bag." << endl;
	cout << "You can purchase them at 7-11." << endl; 
	cout << "Currently in you bag your have: ";
	playerPtr->printBag();
	cout << endl;
	cout << "You cannot have more than 10 items in your bag." << endl;
	cout << "You need to watch out for your stress level." << endl;
	cout << "If your stress level exceeds 10pts the game will end." << endl;
	cout << "In your wallet you have: $20." << endl; 
	cout << "On your transit card you have: $10." << endl;	
	cout << "You have 1 hour to complete your mission. Get going!" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << endl;
	
	// make map
	setMap();

	// home gen random event
	cout << "At Home: " << endl;
	playerPos->spaceEvent(playerPos, getHead());	

	// round simulation
	while (!atWork && !stress && time)
	{
		cout << endl;
		cout << "--------------------------------------------------------------" << endl;
		// print round
		printRound();
		cout << endl;
		
		// print map
		printMap();
		cout << endl;
		
		// get player direction selection and update position
		dir = menuDirection(playerPos);
		if (dir == 1)
		{
			playerPrevPos = playerPos;
			playerPos = playerPos->getUp();
		}	
		if (dir == 2)
		{
			playerPrevPos = playerPos;
			playerPos = playerPos->getRight();
		}	
		if (dir == 3)
		{
			playerPrevPos = playerPos;
			playerPos = playerPos->getDown();
		}	
		if (dir == 4)
		{
			playerPrevPos = playerPos;
			playerPos = playerPos->getLeft();
		}
		cout << endl;
	
		// check conditions if Space type is work
		if (playerPos->getSpaceType() == "Work")
		{	
			// has coffee 
			if (!playerPtr->checkBag(6))
			{
				cout << "You need coffee to go to work." << endl;
				playerPos = playerPrevPos;	
			}
			// has donuts	
			if (!playerPtr->checkBag(5))
			{
				cout << "You need donuts to go to work." << endl;
				playerPos = playerPrevPos;	
			}	
		}	

		// generate random space event
		if (playerPos != playerPrevPos)
		{
			bool goHome = false;
			goHome = playerPos->spaceEvent(playerPos, getHead());
			if (goHome)
			{
				playerPos = head;	
			}
		}

		// check atWork, stress and time
		if (playerPos->getSpaceType() == "Work")
		{
			atWork = true;
		} 	
		if (playerPtr->getStress() >= 10)
		{
			stress = true;
			cout << "Oh no! Your stress level exceeded a healthy level." << endl;
			cout << "You must go to the doctor instead of to work." << endl;
			cout << "Game over." << endl; 
		}
		if (playerPtr->getStopwatch() >= 60)
		{
			time = false;
			cout << "Oh no! You are out of time!" << endl;
			cout << "Game over." << endl; 
		}
		cout << "--------------------------------------------------------------" << endl;
	}
}

/*****************************************************************************************
int Game::genRandomNum()
Description: This function generates a random integer from 1 to 4 and then returns that
integer.
*****************************************************************************************/
int Game::genRandomNum()
{
	int randomNum = 0;
	randomNum = rand() % 4 + 1;
	return randomNum; 
}

/*****************************************************************************************
void Game::printRound()
Description: This function prints the current round information including the Player's
money in their wallet, money on their transit card, current stress level and the time.
It also prints the items in the Player's bag. 
*****************************************************************************************/
void Game::printRound()
{
	cout << "* COMMUTE VITALS" << endl;
	cout << "* Wallet: $" << playerPtr->getMoney() << endl;
	cout << "* Transit Card: $" << playerPtr->getTransitMoney() << endl;
	cout << "* Stress Level: " << playerPtr->getStress() << " pts" << endl;
	if (playerPtr->getStopwatch() < 10)
	{
		cout << "* Time: 8:0" << playerPtr->getStopwatch() << "am" << endl;
	}
	else
	{
		cout << "* Time: 8:" << playerPtr->getStopwatch() << "am" << endl;
	}		
	cout << "* Bag contents: "; 
	playerPtr->printBag();
	cout << endl;
}
