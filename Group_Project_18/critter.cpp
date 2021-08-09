/***************************************************************************************************
* Program name:         critter.cpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the source file for the Critter class for the
* 			Predator-Prey Game.
***************************************************************************************************/

#include "critter.hpp"
#include <iostream>

/***************************************************************************************************
Critter::Critter()
Description: Critter constructor
***************************************************************************************************/
Critter::Critter()
{
    this->gridRow = 20;
    this->gridCol = 20;
    
    numSteps = 0;
    this->type = 2;
}

/***************************************************************************************************
void Critter::move()
Description: Virtual function. For every time step, the move function randomly selects an
adjacent cell and checks the occupancy condition of that cell. Depending on the type of critter,
the critter may or may not move to the adjacent cell. If the adjacent cell is off the grid, the
critter remains in the same cell.
***************************************************************************************************/
void Critter::move(Critter ***array,int,int,int)
{
}


/***************************************************************************************************
void Critter::breed()
Description: Virtual function. If a critter survives a specific amount of steps, an adjacent cell
is randomly selected and checked if it is empty. If it is empty, a new critter will be created
to occupy that cell. If that cell is occupied, the other cells are checked. If no cells are
available, no breeding occurs.
***************************************************************************************************/
void Critter::breed(Critter ***array,int,int,int)
{
}

/***************************************************************************************************
void Critter::setX(int x)
Description: This function takes an integer x, representing the critter's x position on the grid.
***************************************************************************************************/
void Critter::setX(int x)
{
	this->x = x;
}

/***************************************************************************************************
void Critter::setY(int y)
Description: This function takes an integer y, representing the critter's y position on the grid.
***************************************************************************************************/
void Critter::setY(int Y)
{
	this->y = y;
}

/***************************************************************************************************
int Critter::getX()
Description: This function returns an integer x, representing the critter's x position on the grid.
***************************************************************************************************/
int Critter::getX()
{
	return x;
}

/***************************************************************************************************
int Critter::getY()
Description: This function returns an integer y, representing the critter's y position on the grid.
***************************************************************************************************/
int Critter::getY()
{
	return y;
}

/***************************************************************************************************
void Critter::setNumSteps(int numSteps)
Description: This function takes an integer, and sets the critter's numSteps to this value.
***************************************************************************************************/
void Critter::setNumSteps(int numSteps)
{
	this->numSteps = numSteps;
}

/***************************************************************************************************
void Critter::getNumSteps()
Description: This function returns an integer representing the critter's numSteps.
***************************************************************************************************/
int Critter::getNumSteps()
{
	return numSteps;
}

void Critter::setType(char t)
{
    type = t;
}

/***************************************************************************************************
int Critter::getType()
Description: This function returns an integer representing the critter's type. 0 == Ant 1 == doodle
***************************************************************************************************/
char Critter::getType()
{
	return type;
}
void Critter::setTimeSteps(int t)
{
    timeSteps = t;
}

int Critter::getTimeSteps()
{
    return timeSteps;
}
