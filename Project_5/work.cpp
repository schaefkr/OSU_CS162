/*****************************************************************************************
* Program name:         work.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Work class.
                        The Work class is a derived class of Space. Each Work object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Work object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#include "work.hpp"
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
Work::Work(Player *playerPtr) : Space()
Description: Constructor. Takes a pointer to a Player object and sets the pointer
accordingly. Also sets the spaceType and printType. 
*****************************************************************************************/
Work::Work(Player *playerPtr) : Space()
{
	spaceType = "Work";
	printType = "    Work    ";
	player1 = playerPtr;
}

/*****************************************************************************************
bool Work::spaceEvent(Space *playerPosPtr, Space *headPtr)
Description: This function takes two Space pointers as parameters. This first, a pointer
to the player's current position on the map, the second a pointer to the head pointer of
the map, or the home position. The function gets a random event int from the
genRandomEvent() function and then executes the random event accordingly.
*****************************************************************************************/
bool Work::spaceEvent(Space *playerPosPtr, Space *headPtr)
{
	int num = 0;
	num = genRandomEvent();

	cout << "Congratulations! You made it to work!" << endl; 
		
	// Donuts happy 
	if (num == 1)
	{
		cout << "Everybody appreciated your donuts and coffee." << endl;
	}
	// Donuts diet 
	if (num == 2)
	{
		cout << "Everybody is on a diet. You have the donuts to yourself!" << endl;
	}
	return false;
}

/*****************************************************************************************
int Work::genRandomEvent()
Description: This function generates a random integer, and returns that integer so a 
random event can be executed in the spaceEvent() function. 
*****************************************************************************************/
int Work::genRandomEvent()
{
	int num = 0;
	num = rand() % 2 + 1;
}
