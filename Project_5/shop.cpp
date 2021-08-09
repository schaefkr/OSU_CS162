/*****************************************************************************************
* Program name:         shop.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Shop class.
                        The Shop class is a derived class of Space. Each Shop object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Shop object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#include "shop.hpp"
#include "space.hpp"
#include "player.hpp" 
#include "menu.hpp" 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;
using std::cout;
using std::endl;


/*****************************************************************************************
Shop::Shop(Player *playerPtr) : Space()
Description: Constructor. Takes a pointer to a Player object and sets the pointer
accordingly. Also sets the spaceType and printType. 
*****************************************************************************************/
Shop::Shop(Player *playerPtr) : Space()
{
	spaceType = "7-11";
	printType = "    7-11    ";
	player1 = playerPtr;
}

/*****************************************************************************************
bool Shop::spaceEvent(Space *playerPosPtr, Space *headPtr)
Description: This function takes two Space pointers as parameters. This first, a pointer
to the player's current position on the map, the second a pointer to the head pointer of
the map, or the home position. The function gets a random event int from the
genRandomEvent() function and then executes the random event accordingly. 
The function also displays a menu for the user to choose if they would like to buy donuts,
coffee, withdraw money from the atm or continue to work.
*****************************************************************************************/
bool Shop::spaceEvent(Space *playerPosPtr, Space *headPtr)
{
	int num = 0;
	int c = 0;

	// update stopwatch
	player1->setStopwatch(5);

	// generate random event
	num = genRandomEvent();
	// Give $5 to a homeless man outside 
	if ((num == 1) && (player1->getMoney() >= 5))
	{
		cout << "You donate $5 to a homeless man outside." << endl;
		cout << "Wallet: -$5" << endl;
		if (player1->getStress() > 0)
		{
			cout << "Stress Level: -1 pts" << endl;
			player1->setStress(-1);
		}
		player1->setMoney(-5);
	}
 	// else no random event
	
	do
	{
		c = menuShop();
		// Buy coffee 
		if (c == 1)
		{
			if (player1->getMoney() >= 5)
			{
				cout << "You have purchased coffee." << endl;
				cout << "Stress Level: -1 pts" << endl;
				cout << "Wallet: -$5" << endl;
				player1->setStress(-1);
				player1->setMoney(-5);
				player1->addBack(6);
			}
			else
			{
				cout << "You need at least $5 to purchase coffee." << endl; 
				cout << "You have $" << player1->getMoney() << "in your wallet." << endl;
				cout << "Choose the ATM menu option to withdraw cash." << endl; 
			}
		}
		// Buy donuts 
		else if (c == 2)
		{
			if (player1->getMoney() >= 5)
			{
				cout << "You have purchased donuts." << endl;
				cout << "Stress Level: -1 pts" << endl;
				cout << "Wallet: -$5" << endl;
				player1->setStress(-1);
				player1->setMoney(-5);
				player1->addBack(5);
			}
			else
			{
				cout << "You need at least $5 to purchase donuts." << endl; 
				cout << "You have $" << player1->getMoney() << "in your wallet." << endl;
				cout << "Choose the ATM menu option to withdraw cash." << endl; 
			}
		}
		// ATM	
		else if (c == 3)
		{
			if (player1->getMoney() <= 80)
			{	
				cout << "You have withdrawn $20." << endl;
				cout << "You have $" << player1->getMoney() << "in your wallet." << endl;
				player1->setMoney(20);
			}
			else
			{
				cout << "You do not want to have more than $100 in your wallet!" << endl; 
			}
		}	
	} while (c != 4);

	return false;
}

/*****************************************************************************************
int Shop::genRandomEvent()
Description: This function generates a random integer, and returns that integer so a 
random event can be executed in the spaceEvent() function.
*****************************************************************************************/
int Shop::genRandomEvent()
{
	int num = 0;
	num = rand() % 3 + 1;
}
