/***************************************************************************************************
* Program name:         ant.cpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the source file for the Ant class for the
* 			Predator-Prey Game.
***************************************************************************************************/

#include "ant.hpp"
#include "doodlebug.hpp"
#include "critter.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

using std::swap;
using std::cout;
using std::endl;

/***************************************************************************************************
Ant::Ant()
Ant::Ant(int x, int y, int numSteps, int timeSteps, int row, int col)
Description: Ant constructors
***************************************************************************************************/
Ant::Ant()
{
	x=0;
	y=0;
	numSteps = 0;
	timeSteps = 0;
	type = 'a';
	gridRow = 20;
	gridCol = 20;
}

Ant::Ant(int x, int y, int numSteps, int timeSteps, int row, int col)
{
    this->gridRow = row;
    this->gridCol = col;
    this->numSteps = numSteps;
    this->x = x;
    this->y = y;
    this->timeSteps = timeSteps;
    type = 'a';
}

/***************************************************************************************************
void Ant::move()
Description: Virtual function. For every time step, the move function randomly selects an
adjacent cell and checks the occupancy condition of that cell. If the adjacent cell selected is
occupied by a doodlebug, the ant stays in the same cell. If the adjacent cell is off the grid,
the ant remains in the same cell.
***************************************************************************************************/
void Ant::move(Critter ***array,int i, int j,int t)
{
    int dir = getRandomNumber(1,4); // randomly choose direction

if (t >= getTimeSteps()) // prevent ant from moving more than once in one time step
{
    setNumSteps(getNumSteps()+1); // increase number of step by 1

    if (dir == 1 && getY()+1 >= 0 && getY()+1 < gridCol) // move right
    {
        if (array[getX()][getY()+1] == NULL) // if the cell is empty
        {
            array[getX()][getY()+1] = new Ant(getX(),getY()+1,getNumSteps(),t+1, gridRow, gridCol); 
            // create new ant in new cell, pass previous ant's data
            delete array[i][j];
            array[i][j] = NULL; // delete the ant in previous location
        }
        else // staying in current cell
        {
            setTimeSteps(t+1); // update timeStep so that they can't move again until the next step
        }
    }
    else if (dir == 2 && getY()-1 >= 0 && getY()-1 < gridCol) // move left
    {
        if (array[getX()][getY()-1] == NULL) // if the cell is empty
        {
            array[getX()][getY()-1] = new Ant(getX(),getY()-1,getNumSteps(),t+1, gridRow, gridCol);
            delete array[i][j];
            array[i][j] = NULL;
        }
        else // staying in current cell
        {
            setTimeSteps(t+1); // update timeStep
        }
    }
    else if (dir == 3 && getX()-1 >= 0 && getX()-1 < gridRow) // move up
    {
        if (array[getX()-1][getY()] == NULL) // if the cell is empty
        {
            array[getX()-1][getY()] = new Ant(getX()-1,getY(),getNumSteps(),t+1, gridRow, gridCol);
            delete array[i][j];
            array[i][j] = NULL;
        }
        else // staying in current cell
        {
            setTimeSteps(t+1); // update timeStep
        }
    }
    else if (dir == 4 && getX()+1 >= 0 && getX()+1 < gridRow) // move down
    {
        if (array[getX()+1][getY()] == NULL) // if the cell is empty
        {
            array[getX()+1][getY()] = new Ant(getX()+1,getY(),getNumSteps(),t+1, gridRow, gridCol);
            delete array[i][j];
            array[i][j] = NULL;
        }
        else // staying in current cell
        {
            setTimeSteps(t+1); // update timeStep
        }
    }
    else // could not move because of the wall
    {
        setTimeSteps(t+1); // update timeStep
    }
}

}

/***************************************************************************************************
void Ant::breed()
Description: Virtual function. If the ant survives 3 time steps, an adjacent cell
is randomly selected and checked if it is empty. If it is empty, a new ant will be created
to occupy that cell. If that cell is occupied, the other cells are checked. If no cells are
available, no breeding occurs.
***************************************************************************************************/
void Ant::breed(Critter ***array, int i, int j, int t)
{
    if (getNumSteps()%3 == 0 && getNumSteps() >= 3) // breed when numStep == 3,6,9,12,.....
    {
        int count = 0;
        int check = 0;
        int dir = getRandomNumber(1,4);

        while (count != 1 && check != 30) // exit loop when new ant is born or at least 30 attempt to check for empty cell
        {
            int dir = getRandomNumber(1,4); // pick random cell

            if (dir == 1 && getY()+1 >= 0 && getY()+1 < gridCol)
            {
                if (array[getX()][getY()+1] == NULL) // empty cell
                {
                    array[getX()][getY()+1] = new Ant(getX(),getY()+1,0,t+1, gridRow, gridCol); // new ant
                    count +=1; // exit loop
                }
                check += 1;
            }
            else if (dir == 2 && getY()-1 >= 0 && getY()-1 < gridCol)
            {
                if (array[getX()][getY()-1] == NULL)
                {
                    array[getX()][getY()-1] = new Ant(getX(),getY()-1,0,t+1, gridRow, gridCol);
                    count += 1;
                }
                check += 1;
            }
            else if (dir == 3 && getX()-1 >= 0 && getX()-1 < gridRow)
            {
                if (array[getX()-1][getY()] == NULL)
                {
                    array[getX()-1][getY()] = new Ant(getX()-1,getY(),0,t+1, gridRow, gridCol);
                    count += 1;
                }
                check += 1;
            }
            else if (dir == 4 && getX()+1 >= 0 && getX()+1 < gridRow)
            {
                if (array[getX()+1][getY()] == NULL)
               	{ 
                    array[getX()+1][getY()] = new Ant(getX()+1,getY(),0,t+1, gridRow, gridCol);
                    count += 1;
                }
                check += 1;
            }
        }
    }
}

