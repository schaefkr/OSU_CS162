/*****************************************************************************************
* Program name:         space.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Space class.
                        The Space class is an abstract class, with it's derived classes
                        being Home, Work, Walk, Train, Bus and Shop. Each Space object is
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for setters and getters to the Space object 
                        pointers. It also has two pure virtual functions spaceEvent() and 
                        genRandomEvent().
*****************************************************************************************/

#include "space.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
using std::string;

/*****************************************************************************************
void Space::setUp(Space *upSpace)
Description: This function takes a pointer to a Space object representing the up node in 
the linked list. It then sets the private member up pointer accordingly. 
*****************************************************************************************/
void Space::setUp(Space *upSpace)
{
	up = upSpace;	
}

/*****************************************************************************************
void Space::setUp(int val)
Description: This function takes a pointer to a Space object representing the up node 
in the linked list. It then sets the private member up pointer accordingly. 
*****************************************************************************************/
void Space::setUp(int val)
{
	if (val == 0)
	{
		up = nullptr;
	}	
}

/*****************************************************************************************
Space * Space::getUp()
Description: This function returns the pointer to the up Space object.
*****************************************************************************************/
Space * Space::getUp()
{
	return up;	
}

/*****************************************************************************************
void Space::setRight(Space *rightSpace)
Description: This function takes a pointer to a Space object representing the right node 
in the linked list. It then sets the private member right pointer accordingly. 
*****************************************************************************************/
void Space::setRight(Space *rightSpace)
{
	right = rightSpace;	
}

/*****************************************************************************************
void Space::setRight(int val)
Description: This function takes a pointer to a Space object representing the right node 
in the linked list. It then sets the private member right pointer accordingly. 
*****************************************************************************************/
void Space::setRight(int val)
{
	if (val == 0)
	{
		right = nullptr;
	}	
}

/*****************************************************************************************
Space * Space::getRight()
Description: This function returns the pointer to the right Space object.
*****************************************************************************************/
Space * Space::getRight()
{
	return right;	
}

/*****************************************************************************************
void Space::setDown(Space *downSpace)
Description: This function takes a pointer to a Space object representing the down node 
in the linked list. It then sets the private member down pointer accordingly. 
*****************************************************************************************/
void Space::setDown(Space *downSpace)
{
	down = downSpace;	
}

/*****************************************************************************************
void Space::setDown(int val)
Description: This function takes an int (0) parameter and sets the down Space pointer to 
nullptr.
*****************************************************************************************/
void Space::setDown(int val)
{
	if (val == 0)
	{
		down = nullptr;
	}
}

/*****************************************************************************************
Space * Space::getDown()
Description: This function returns the pointer to the down Space object.
*****************************************************************************************/
Space * Space::getDown()
{
	return down;	
}

/*****************************************************************************************
void Space::setLeft(Space *leftSpace)
Description: This function takes a pointer to a Space object representing the left node 
in the linked list. It then sets the private member left pointer accordingly. 
*****************************************************************************************/
void Space::setLeft(Space *leftSpace)
{
	left = leftSpace;	
}

/*****************************************************************************************
void Space::setLeft(int val)
Description: This function takes an int (0) parameter and sets the left Space pointer to 
nullptr.
*****************************************************************************************/
void Space::setLeft(int val)
{
	if (val == 0)
	{
		left = nullptr;
	}
}

/*****************************************************************************************
Space * Space::getLeft()
Description: This function returns the pointer to the left Space object.
*****************************************************************************************/
Space * Space::getLeft()
{
	return left;	
}

/*****************************************************************************************
string Space::getSpaceType()
Description: This function returns a string representing the space type: Work, Home, 
Walk, Train, Bus or Shop.
*****************************************************************************************/
string Space::getSpaceType()
{
	return spaceType;	
}

/*****************************************************************************************
string Space::getPrintType()
Description: This function returns a string representing the print type: Work, Home, 
Walk, Train, Bus or Shop. The string is formatted for the printMap() function in the 
Game class.
*****************************************************************************************/
string Space::getPrintType()
{
	return printType;	
}
