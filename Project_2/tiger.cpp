/***************************************************************************
* Program name:         tiger.cpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the source file for the Tiger class.
*                       It is a derived class of Animal. 
***************************************************************************/

#include "animal.hpp"
#include "tiger.hpp"
#include <iostream>

/***************************************************************************
				Tiger::Tiger()
Description:
***************************************************************************/
Tiger::Tiger() : Animal()
{
	age = 0;
	numBabies = 1;
	cost = 10000.00;
	baseFoodCost = 50.00;
	payoff = 0.20;
}
