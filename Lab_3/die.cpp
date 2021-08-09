/***************************************************************************
* Program name:		die.cpp
* Author:		Kristin Schaefer
* Date:			04-21-2019
* Description:		This is is the source file for the Die class.
* Sources:		Textbook, page 132-135, 797.
* 			http://www.cplusplus.com/forum/beginner/132561/				
***************************************************************************/

#include "die.hpp"
#include "game.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;

/***************************************************************************
			 	      Die()	
Parameters: The constructor takes an int N representing the number of sides
of the die.	 
Description: The constructor sets the number of sides of the die and
assigns a string describing the type of die. 
***************************************************************************/
Die::Die(int N)
{
	this->N = N;
	dieType = "normal";	
}

/***************************************************************************
				int getDieRoll()			 		
Parameters: Returns an int representing the die roll.
Description: This function returns a random integer between 1 and N as the 
result of rolling the die once. 
***************************************************************************/
int Die::getDieRoll(int r)
{
	int round = r; 
	currentSide = rand() % N + 1;
	return currentSide;	
}

/***************************************************************************
				string getDieType()			 		
Parameters: Returns string type of normal or loaded.
Description: This function returns the type of die (normal or loaded).
***************************************************************************/
string Die::getDieType()
{
	return dieType;
}

/***************************************************************************
				int getCurrentSide()			 		
Parameters: Returns an integer of the current side of the die. 
Description: This function returns the current side of the  die.
***************************************************************************/
int Die::getCurrentSide()
{
	return currentSide;
}

/***************************************************************************
				void setNumSides()	
Parameters: Takes an integer specified by user in the main file.
Description: This function sets the number of sides of the die.
***************************************************************************/
void Die::setNumSides(int N)
{
	this->N = N;
} 

/***************************************************************************
				~Die()
Description:	
***************************************************************************/
Die::~Die()
{

}
