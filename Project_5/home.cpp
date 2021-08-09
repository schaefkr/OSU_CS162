/*****************************************************************************************
* Program name:         home.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Home class.
                        The Home class is a derived class of Space. Each Home object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Home object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#include "home.hpp"
#include "space.hpp"
#include "player.hpp" 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;
using std::cout;
using std::endl;

/*****************************************************************************************
Home::Home(Player *playerPtr) : Space()
Description: Constructor. Takes a pointer to a Player object and sets the pointer
accordingly. Also sets the spaceType and printType. 
*****************************************************************************************/
Home::Home(Player *playerPtr) : Space()
{
	spaceType = "Home";
	printType = "    Home    ";
	player1 = playerPtr;
}

/*****************************************************************************************
bool Home::spaceEvent(Space *playerPtr, Space *headPtr)
Description: This function takes two Space pointers as parameters. This first, a pointer
to the player's current position on the map, the second a pointer to the head pointer of
the map, or the home position. The function gets a random event int from the
genRandomEvent() function and then executes the random event accordingly. 
*****************************************************************************************/
bool Home::spaceEvent(Space *playerPtr, Space *headPtr)
{
	int num = 0;
	num = genRandomEvent();
	
	// You overslept your alarm. Only for beginning of program.  
	if ((num == 1) && (player1->getStopwatch() < 10))
	{
		cout << "Oh no! You overslept your alarm." << endl;
		cout << "Time: +10 minutes" << endl;
		cout << "Stress Level: +2 pts" << endl;
		player1->setStopwatch(10);	
		player1->setStress(2);	
	}
	// You found $5 in your jean pockets
	else if (num == 2)
	{
		cout << "Awesome! You found $5 in your coat pocket." << endl;
		cout << "Wallet: +$5" << endl;
		player1->setMoney(5);
	}
	// else no random event occurs
	return false;	
}

/*****************************************************************************************
int Home::genRandomEvent()
Description: This function generates a random integer, and returns that integer so a 
random event can be executed in the spaceEvent() function.
*****************************************************************************************/
int Home::genRandomEvent()
{
	int num = 0;
	num = rand() % 3 + 1;
}
