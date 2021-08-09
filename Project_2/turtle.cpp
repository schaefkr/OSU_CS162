/***************************************************************************
* Program name:         turtle.cpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the source file for the Turtle class.
*                       It is a derived class of Animal. 
***************************************************************************/

#include "animal.hpp"
#include "turtle.hpp"
#include <iostream>

/***************************************************************************
				Turtle::Turtle()
Description:
***************************************************************************/
Turtle::Turtle() : Animal()
{
	age = 0;
	numBabies = 10;
	cost = 100.00;
	baseFoodCost = 5.00;
	payoff = 0.05;
}
