/***************************************************************************
* Program name:         loadedDie.cpp
* Author:               Kristin Schaefer
* Date:                 04-21-2019
* Description:          This is is the source file LoadedDie class. 
*                       LoadedDie is a derived class of Die.
* Sources:              Textbook, page 132-135, 797.
*                       http://www.cplusplus.com/forum/beginner/132561/                         
***************************************************************************/

#include "loadedDie.hpp"
#include "die.hpp"
#include "game.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;
using std::endl;
using std::cout;

/***************************************************************************
*				LoadedDie()     
* Parameters: Number of sides of the die specified by the user.
* Description: This is the constructor for the derived class LoadedDie.
***************************************************************************/
LoadedDie::LoadedDie(int N) : Die(N)
{
	this->N = N;
	dieType = "loaded";
}

/***************************************************************************
*				int getDieRoll()        
* Parameters: Returns an int representing the die roll.
* Description: This function overloads the Die function by...
***************************************************************************/
int LoadedDie::getDieRoll(int r) 
{
	int round = r;
	
	if (!(round % 3))
	{
		currentSide = rand() % N + 1;
		return currentSide;
	}
	else
	{
		currentSide = N;
		return currentSide;
	}
}

