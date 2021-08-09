/***************************************************************************************************
* Program name:         critter.hpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the header file for the Critter class for the
*                       Predator-Prey Game.
***************************************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
	protected:
		int x;		// x position in grid of cells
		int y;		// y position in grid of cells
        int numSteps;	// counter to keep track of number of steps taken
        char type;   // a == ant d == doodlebug
        int timeSteps;
        int gridRow;
        int gridCol;

	public:
		Critter();
		// pure virtual functions
		virtual void move(Critter ***,int,int,int) = 0;
		virtual void breed(Critter ***,int,int,int) = 0;
		// setters
		void setX(int x);
		void setY(int y);
		void setType(char c);
		void setNumSteps(int numSteps);
		void setTimeSteps(int);
		// getters
		int getX();
        int getY();
        char getType();
		int getNumSteps();
		int getTimeSteps();
};
#endif
