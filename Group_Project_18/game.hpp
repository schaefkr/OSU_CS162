/***************************************************************************************************
* Program name:         game.hpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the header file for the Game class for the
*                       Predator-Prey Game.
***************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

// Game stores the number of Doodlebugs, number of Ants, the size of the grid
// in rows and columns and the number of steps the game will be iterated. 
// It also stores a pointer to a pointer of an array of pointers to Critters
class Game
{
	private:
        // Number of ants and doodlebugs to intialize on the game board
		int amountAnt, amountDood;
        // Size X and Y for the game grid board
		int gridRow, gridCol;
        // Number of steps to run the game
		int numSteps;
        // Pointer to 2D array of pointers to critters.
	    Critter ***array;


    public:
		Game();
		~Game();
        // Sets the game object variables to the values supplied by the user. Uses inputVal to assure
        // that the values are valid and in range.
		void setStartValues();
        // Creates the grid and intializes everything to play the game
		void initializeWorld();
        // Logic to articulate the game rounds calling appropriate breed, move, etc functions from
        // the critter derived classes.
		void playGame();
        // Function which prints out the current state of the grid to the user
		void printGrid();
};
#endif
