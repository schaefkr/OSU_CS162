/***************************************************************************
* Program name:         penguin.cpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the source file for the Penguin class.
*                       It is a derived class of Animal. 
***************************************************************************/

#include "animal.hpp"
#include "penguin.hpp"
#include <iostream>

/***************************************************************************
				Penguin::Penguin()
Description:
***************************************************************************/
Penguin::Penguin() : Animal()
{
	age = 0;
	numBabies = 1;
	cost = 1000.00;
	baseFoodCost = 10.00;
	payoff = 0.10;
}
