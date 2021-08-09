/***********************************************************************************************
** Program name:        menu.cpp
** Author:              Kristin Schaefer
** Date:                04-14-2019
** Description:         This file contains the main function for the Langton's Ant Simulation. 
***********************************************************************************************/

#include "ant.hpp"
#include "menu.hpp"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// display start menu
	// source for menu function: https://www.youtube.com/watch?v=fxRE5fHTYJg 
	int choice = 1;
	bool startSimulation = menuStart(); 

	if (startSimulation)
	{
		// start simulation
		Ant antBoard;
		antBoard.setAntOrientation(); 
		antBoard.setBoardSize();
		antBoard.setBoardSteps();
		antBoard.setBoardLocation();
		antBoard.startSim();
		antBoard.deleteArray();	

		// replay simulation 
		bool replaySimulation = menuReplay();

		while (replaySimulation)
		{
			Ant antBoard;
			antBoard.setAntOrientation();
			antBoard.setBoardSize();
			antBoard.setBoardSteps();
			antBoard.setBoardLocation();	
			antBoard.startSim();
			antBoard.deleteArray();
			replaySimulation = menuReplay();
		}
	}	
	return 0;
}
