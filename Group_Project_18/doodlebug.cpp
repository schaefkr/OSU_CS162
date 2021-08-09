/***************************************************************************************************
* Program name:         doodlebug.cpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the source file for the Doodlebug class for the
* 			Predator-Prey Game.
***************************************************************************************************/

#include "doodlebug.hpp"
#include "critter.hpp"
#include <iostream>
using std::cout;
using std::endl;

/***************************************************************************************************
Doodlebug::Doodlebug()
Description: Doodlebug constructor
***************************************************************************************************/
Doodlebug::Doodlebug()
{
    this->gridRow = 20;
    this->gridCol = 20;
	numSteps = 0;
	timeSteps = 0;
	sp = 0;
    type = 'd';
}

Doodlebug::Doodlebug(int x, int y, int n, int sp, int timeSteps, int row, int col)
{
    this->gridRow = row;
    this->gridCol = col;
    this->x = x;
    this->y = y;
    this->timeSteps = timeSteps;
    numSteps = n;
    this->sp = sp;
    setType('d');

}

/***************************************************************************************************
void Doodlebug::move()
Description: Virtual function. For every time step, the move function randomly selects an
adjacent cell and checks the occupancy condition of that cell. If there are ant(s) in the adjacent
cell, the doodlebug will move to that cell. If the adjacent cell is empty the doodlebug will not
move to that cell. If the adjacent cell is off the grid, the doodlebug remains in the same cell.
***************************************************************************************************/
void Doodlebug::move(Critter*** array, int i, int j, int t)
{
    int count = 0;
    int check = 0;

if (t >= getTimeSteps())
{
    while (count != 1 && check != 30) // attempt to find ant in adjacent cell for at least 30 times
    {
        int dir = getRandomNumber(1,4); // pick random cell

        if (dir == 1 && getY()+1 >= 0 && getY()+1 < gridCol)
        {
            if (array[getX()][getY()+1] != NULL) // if adjacent cell is not empty, there must be some critter
            {
                if(array[getX()][getY()+1]->getType() == 'a') // if there is ant
                {
                    // Delete the critter and ptr
                    delete array[i][j+1];
                    array[i][j+1] = NULL; // eat ant
                    // move doodlebug to new cell
                    array[i][j+1] = new Doodlebug(i,j+1,getNumSteps()+1,0,t+1, gridRow, gridCol); 
                    // Delete the old critter
                    delete array[i][j];
                    array[i][j] = NULL; // previous cell is now empty
                    count += 1; // exit the while loop
                }
            }
            check += 1;
        }
        else if (dir == 2 && getY()-1 >= 0 && getY()-1 < gridCol)
        {
            if (array[getX()][getY()-1] != NULL)
            {
                if(array[getX()][getY()-1]->getType() == 'a')
                {
                    // Delete the ant critter and it's pointer
                    delete array[i][j-1];
                    array[i][j-1] = NULL;
                    // Move the doodlebug and delete the old one
                    array[i][j-1] = new Doodlebug(i,j-1,getNumSteps()+1,0,t+1, gridRow, gridCol);
                    delete array[i][j];
                    array[i][j] = NULL;
                    count += 1;
                }
            }
            check += 1;
        }
        else if (dir == 3 && getX()-1 >= 0 && getX()-1 < gridRow)
        {
            if (array[getX()-1][getY()] != NULL)
            {
                if(array[getX()-1][getY()]->getType() == 'a')
                {
                    // Delete the critter and then the ptr
                    delete array[i-1][j];
                    array[i-1][j] = NULL;
                    // Create a new doodlebug and delete the old one
                    array[i-1][j] = new Doodlebug(i-1,j,getNumSteps()+1,0,t+1, gridRow, gridCol);
                    delete array[i][j];
                    array[i][j] = NULL;
                    count += 1;
                }
            }
            check += 1;
        }
        else if (dir == 4 && getX()+1 >= 0 && getX()+1 < gridRow)
        {
            if (array[getX()+1][getY()] != NULL)
            {
                if(array[getX()+1][getY()]->getType() == 'a')
                {
                    // If an ant is found delete the critter and pointer to it
                    delete array[i+1][j];
                    array[i+1][j] = NULL;
                    
                    // Update the doodlebug and its pointers    
                    array[i+1][j] = new Doodlebug(i+1,j,getNumSteps()+1,0,t+1, gridRow, gridCol);
                    delete array[i][j];
                    array[i][j] = NULL;
                    count += 1;
                }
            }
            check += 1;
        }
    }

    if (count == 0) // If no ants in adjacent cells, then bugs move according to the same rules as the ant
    {
        int dir = getRandomNumber(1,4); // randomly choose direction
        setNumSteps(getNumSteps()+1); // update numStep

        if (dir == 1 && getY()+1 >= 0 && getY()+1 < gridCol) // move right
        {
            if (array[getX()][getY()+1] == NULL) // if the cell is empty
            {
                array[getX()][getY()+1] = new Doodlebug(getX(),getY()+1,getNumSteps(),getSP()+1,t+1, gridRow, gridCol);
                delete array[i][j];
                array[i][j] = NULL;
            }
            else // staying in current cell
            {
                setSP(getSP()+1); // update SP
                setTimeSteps(t+1); // update timeStep
            }
        }
        else if (dir == 2 && getY()-1 >= 0 && getY()-1 < gridCol) // move left
        {
            if (array[getX()][getY()-1] == NULL) // if the cell is empty
            {
                array[getX()][getY()-1] = new Doodlebug(getX(),getY()-1,getNumSteps(),getSP()+1,t+1, gridRow, gridCol);
                delete array[i][j]; 
                array[i][j] = NULL;
            }
            else // staying in current cell
            {
                setSP(getSP()+1); // update SP
                setTimeSteps(t+1); // update timeStep
            }
        }
        else if (dir == 3 && getX()-1 >= 0 && getX()-1 < gridRow) // move up
        {
            if (array[getX()-1][getY()] == NULL) // if the cell is empty
            {
                array[getX()-1][getY()] = new Doodlebug(getX()-1,getY(),getNumSteps(),getSP()+1,t+1, gridRow, gridCol);
                // Delete critter and ptr.
                delete array[i][j];
                array[i][j] = NULL;
            }
            else // staying in current cell
            {
                setSP(getSP()+1); // update SP
                setTimeSteps(t+1); // update timeStep
            }
        }
        else if (dir == 4 && getX()+1 >= 0 && getX()+1 < gridRow) // move down
        {
            if (array[getX()+1][getY()] == NULL) // if the cell is empty
            {
                array[getX()+1][getY()] = new Doodlebug(getX()+1,getY(),getNumSteps(),getSP()+1,t+1, gridRow, gridCol);
                delete array[i][j];
                array[i][j] = NULL;
            }
            else // staying in current cell
            {
                setSP(getSP()+1); // update SP
                setTimeSteps(t+1); // update timeStep
            }
        }
        else
        {
            setSP(getSP()+1); // update SP
            setTimeSteps(t+1); // update timeStep
        }
    }

}
}

/***************************************************************************************************
void Doodlebug::breed()
Description: Virtual function. If a doodlebug survives 8 steps, an adjacent cell
is randomly selected and checked if it is empty. If it is empty, a new doodlebug will be created
to occupy that cell. If that cell is occupied, the other cells are checked. If no cells are
available, no breeding occurs.
***************************************************************************************************/
void Doodlebug::breed(Critter*** array, int i, int j,int t)
{
    if (starve(array,i,j,getSP()) == 1) // check starving point first before breeding
    {
        // doodlebug dies if SP == 3
    }

    else if (starve(array,i,j,getSP()) == 0) // If no starving occurred, then try to breed
    {

    if (getNumSteps()%8 == 0 && getNumSteps() >= 8) // survived for eight time steps
    {
        int count = 0;
        int check = 0;
        int dir = getRandomNumber(1,4);

        while (count != 1 && check != 30) // exit loop when new bug is born or at least 30 attempt to check for empty cell
        {
            int dir = getRandomNumber(1,4); // pick random cell

            if (dir == 1 && getY()+1 >= 0 && getY()+1 < gridCol)
            {
                if (array[getX()][getY()+1] == NULL) // empty cell
                {
                    array[getX()][getY()+1] = new Doodlebug(getX(),getY()+1,0,0,t+1, gridRow, gridCol); // new bug
                    count +=1; // exit loop
                }
                check += 1;
            }
            else if (dir == 2 && getY()-1 >= 0 && getY()-1 < gridCol)
            {
                if (array[getX()][getY()-1] == NULL)
                {
                    array[getX()][getY()-1] = new Doodlebug(getX(),getY()-1,0,0,t+1, gridRow, gridCol);
                    count += 1;
                }
                check += 1;
            }
            else if (dir == 3 && getX()-1 >= 0 && getX()-1 < gridRow)
            {
                if (array[getX()-1][getY()] == NULL)
                {
                    array[getX()-1][getY()] = new Doodlebug(getX()-1,getY(),0,0,t+1, gridRow, gridCol);
                    count += 1;
                }
                check += 1;
            }
            else if (dir == 4 && getX()+1 >= 0 && getX()+1 < gridRow)
            {
                if (array[getX()+1][getY()] == NULL)
                {
                    array[getX()+1][getY()] = new Doodlebug(getX()+1,getY(),0,0,t+1, gridRow, gridCol);
                    count += 1;
                }
                check += 1;
            }
        }
    }
    }
}

/***************************************************************************************************
void Doodlebug::starve()
Description: If a doodlebug has not eaten an ant within three time steps, at the end of the third
time step it will starve and die. The doodlebug should then be removed from the grid of cells.
***************************************************************************************************/
int Doodlebug::starve(Critter*** array, int i, int j, int sp)
{
    if ((sp%3 == 0 && sp>=3)) // starved for 3 time steps
    {
        // Delete the critter
        delete array[i][j];
        // and it's pointer
        array[i][j] = NULL;
        return 1;
    }
    return 0;
}

void Doodlebug::setSP(int sp)
{
    this->sp = sp;
}
int Doodlebug::getSP()
{
    return sp;
}
