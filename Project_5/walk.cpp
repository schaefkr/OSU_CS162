/*****************************************************************************************
* Program name:         walk.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Walk class.
                        The Walk class is a derived class of Space. Each Walk object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Walk object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#include "walk.hpp"
#include "space.hpp"
#include "player.hpp" 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;
using std::endl;
using std::cout;


/*****************************************************************************************
Walk::Walk(Player *playerPtr) : Space()
Description: Constructor. Takes a pointer to a Player object and sets the pointer
accordingly. Also sets the spaceType and printType. 
*****************************************************************************************/
Walk::Walk(Player *playerPtr) : Space()
{
	spaceType = "Walk";
	printType = "    Walk    ";
	player1 = playerPtr;
}

/*****************************************************************************************
bool Walk::spaceEvent(Space *playerPosPtr, Space *headPtr)
Description: This function takes two Space pointers as parameters. This first, a pointer
to the player's current position on the map, the second a pointer to the head pointer of
the map, or the home position. The function gets a random event int from the
genRandomEvent() function and then executes the random event accordingly. 
*****************************************************************************************/
bool Walk::spaceEvent(Space *playerPosPtr, Space *headPtr)
{
	int num = 0;
	num = genRandomEvent();
	Space *positionPtr = playerPosPtr;

	// Take walk
	cout << "Time: +10 minutes" << endl;
	player1->setStopwatch(10);
	
	// Lose top item in bag 
	if ((num == 1) && (player1->getItemCount() >= 1))
	{
		cout << "Oh no! You lost your " << player1->getFront() << " from your bag." << endl;
		if (player1->getFront() == "wallet")
		{
			int tempVal = player1->getMoney();
			tempVal *= -1;
			player1->setMoney(tempVal);
			cout << "Wallet: $" << player1->getMoney() << endl; 
		}
		if (player1->getFront() == "transit pass")
		{
			int tempVal = player1->getTransitMoney();
			tempVal *= -1;
			player1->setTransitMoney(tempVal);
			cout << "Transit Pass: $" << player1->getTransitMoney() << endl; 
		}
		cout << "Stress Level: +2 pts" << endl;
		player1->removeFront();
		player1->setStress(2); 
		return false;
	}
	//You found $5 on the sidewalk
	else if (num == 2)
	{
		cout << "It's your lucky day. You found $5 on the ground." << endl;
		cout << "Wallet: +$5." << endl;
		player1->setMoney(5);
		return false;
	}
	// Your boss called and said he's running late 
	else if ((num == 3) && (player1->getStopwatch() >= 10))
	{
		cout << "Your boss called and said they're running late." << endl;
		cout << "Time: +10 minutes" << endl;
		player1->setStopwatch(-10);
		if (player1->getStress() >= 1)
		{
			cout << "Stress Level: -1 pts" << endl;
			player1->setStress(-1);
		}
		return false;
	}
	// You left your laptop at home
	else if (num == 4)
	{
		cout << "You forgot your laptop at home." << endl;
		cout << "You must go home and get it." << endl;
		cout << "Time: +10 minutes" << endl;
		cout << "Stress Level: +2 pts" << endl;
		player1->setStopwatch(10);
		player1->setStress(2);
		return true;
	}
	// You left your phone at home
	else if (num == 5)
	{
		cout << "You left your phone at home." << endl;
		cout << "You must go home and get it." << endl;
		cout << "Time: +10 minutes" << endl;
		cout << "Stress Level: +2 pts" << endl;
		player1->setStopwatch(10);
		player1->setStress(2);
		return true;
	}
	// Cute dog
	else if (num == 6)
	{
		cout << "You see a cute dog and stop to pet it." << endl;
		cout << "Time: +5 minutes" << endl;
		player1->setStopwatch(5);
		if (player1->getStress() >= 1)
		{
			cout << "Stress Level: -1 pts" << endl;
			player1->setStress(-1);
		}
		return false;
	}
	// no random event occurs
	else
	{
		return false;
	}	
}

/*****************************************************************************************
int Walk::genRandomEvent()
Description: This function generates a random integer, and returns that integer so a 
random event can be executed in the spaceEvent() function.
*****************************************************************************************/
int Walk::genRandomEvent()
{
	int num = 0;
	num = rand() % 8 + 1;
}
