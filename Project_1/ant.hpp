/*****************************************************************************************
** Program name:        ant.hpp
** Author:              Kristin Schaefer
** Date:                04-14-2019
** Description:         This file contains the header file for the Ant class for the 
                        Langton's Ant Simulation.       
******************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
	private:
		char **board;	// dynamic 2d array representing the board 	
		int boardRows;
		int boardColumns;
		int antRow;
		int antColumn;
		int antUp; 
		int antRight;
		int antDown;
		int antLeft; 
		int antOrientation; 
		int steps;
		char state;
		void moveForward();
		void turnLeft();
		void turnRight();
		void printBoard();
	public:
		Ant();
		void setBoardSize();
		void setBoardSteps();
		void setBoardLocation();
		void startSim();
		void deleteArray();
		void setAntOrientation();
};
#endif


