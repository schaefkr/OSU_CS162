/***************************************************************************************************
* Program name:         game.cpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the source file for the Game class for the
* 		 	            Predator-Prey Game. Creates the grid and controls the interaction
* 		 	            between the critters, the board, and printing out the board to the
* 		 	            user.
***************************************************************************************************/

#include "game.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include "inputval.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************************************************
Game::Game()
Description: Game constructor defaults to initalizing everything to 0
***************************************************************************************************/
Game::Game()
{
    amountAnt = 0,
    amountDood = 0,
    gridRow = 0, 
    gridCol = 0,
    numSteps = 0;
}

/***************************************************************************************************
Game::~Game()
Description: Game destructor frees up all the dynamically allocated memory
***************************************************************************************************/
Game::~Game()
{
    // Delete all the pointers
    for(int i = 0; i < gridRow; i++)
    {
        for(int j = 0; j < gridCol; j++)
        {
            delete array[i][j];
        }
    }

    // Free up our dynamic arrays
    for(int i=0; i <gridRow; i++)
    {
         delete [] array[i];
    }
    delete [] array;

}

/***************************************************************************************************
void Game::setStartValues()
Description: This function sets the starting values to play the game. Values sets are: numSteps,
gridRow, gridCol, amountAnt and amountDood. Uses the inputVal to validates that the input from
the user is in range and an acceptable format.
***************************************************************************************************/
void Game::setStartValues()
{
	cout << "Please enter the number of time steps you wish to use: " 
         << endl << endl;
	this->numSteps = inputVal(1,10000);

    // Extra Credit Start
	cout << endl;
	cout << "* EXTRA CREDIT PORTION *" << endl;
    
    // Get the rows desired
	cout << "Please enter the number of rows you wish to use: " << endl;
	this->gridRow = inputVal(1, 1000);

    // Get the columns desired
	cout << "Please enter the number of columns you wish to use: " << endl;
	this->gridCol = inputVal(1, 1000);
    
    // get the number of ants desired
    cout << "Please enter the number of ants you wish to use: " << endl;
	this->amountAnt = inputVal(1, gridCol * gridRow);

    // Get number of doodlebugs desired
	cout << "Please enter the number of doodlebugs you wish to use: " << endl;
	this->amountDood = inputVal(1, gridCol * gridRow);

	// Extra Credit End
}

/***************************************************************************************************
void Game::initializeWorld()
Description: This function initializes the Predator-Prey game world by creating the board and the
ants and doodlebugs based off the information provided by the user.
***************************************************************************************************/
void Game::initializeWorld()
{
	// create the board with the user specified number of rows and columns
	// initialize the world with the user specified number of ants and doodlebugs


    // Next we create and array of pointers to Critters
    // First dimension creation for Critter array
    array = new Critter**[gridRow];

    // Second dimension creation for Critter ptr array
    for(int i=0; i<gridRow; ++i)
    {
        array[i] = new Critter*[gridCol];
    }

    // Initialize all the Critters in the array to null ptrs
    for(int i=0; i<gridRow; ++i)
    {
        for(int j=0; j<gridCol; ++j)
        {
            array[i][j] = NULL;
        }
    }

    // Populate our ants
    int count = 0;
    while (count < amountAnt)
    {
        int x = getRandomNumber(0, gridRow - 1);
        int y = getRandomNumber(0, gridCol - 1);

        if (array[x][y] == NULL) // if the cell is empty
        {
            array[x][y] = new Ant(x,y,0,0, gridRow, gridCol); // create new ant
            count += 1;
        }
    }

    // Populate our doodlebugs
    count = 0;
    while (count < amountDood)
    {
        // Use random to place them. this could be regulated to prevent over-
        // writing existing Critters
        int x = getRandomNumber(0, gridRow - 1);
        int y = getRandomNumber(0, gridCol - 1);

        // Put a new doodlebug there
        if (array[x][y] == NULL)
        {
            array[x][y] = new Doodlebug(x,y,0,0,0, gridRow, gridCol);
            count += 1;
        }
    }

}

/***************************************************************************************************
void Game::playGame()
Description: This function controls the movement of ants and doodlebugs and breeds the ants and 
doodlebugs if the conditions to breed are met. The function also prints the currenty board for each
time step. 
***************************************************************************************************/
void Game::playGame()
{
	// Show and print the initial board positions.
    int currentStep = -1;
    cout << "-------------------------------------------" 
         << endl
         << "Initial board with size " << gridRow << " by "
         << gridCol << " and with " << amountAnt << " ants and "
         << amountDood << " doodlebugs." 
         << endl;

    //printGrid();
    while (currentStep < numSteps)
    {
        // Search for doodlebugs
        for (int i=0; i<gridRow; i++)
        {
            for (int j=0; j<gridCol; j++)
            {
                if (array[i][j] != NULL)
                {  
                    // If doodlebug move first
                    if (array[i][j]->getType() == 'd') 
                    {
                        array[i][j]->move(array,i,j,currentStep); 
                    }
                }
            }
        }

        for (int i=0; i<gridRow; i++)
        {
            for (int j=0; j<gridCol; j++)
            {
                if (array[i][j] != NULL)
                {
                    // If doodlebug, breed the doodlebug
                    if (array[i][j]->getType() == 'd') 
                    {
                        array[i][j]->breed(array,i,j,currentStep); 
                    }
                }
            }
        }

        // Now search for and process all the ants
        for (int i=0; i<gridRow; i++)
        {
            for (int j=0; j<gridCol; j++)
            {
                if (array[i][j] != NULL)
                {
                    if (array[i][j]->getType() == 'a') // if ant
                    {
                        array[i][j]->move(array,i,j,currentStep); // move ant
                    }
                }
            }
        }

        for (int i=0; i<gridRow; i++)
        {
            for (int j=0; j<gridCol; j++)
            {
                if (array[i][j] != NULL)
                {
                    if (array[i][j]->getType() == 'a') // if ant
                    {
                        array[i][j]->breed(array,i,j,currentStep); // breed ant
                    }
                }
            }
        }

        // Increment step
        currentStep += 1;

        // Print the game grid
        printGrid();

        cout << "-------------------------------------------" 
             << endl
             << "   Current Step: " << currentStep 
             << "/" << numSteps << endl;
        cout << "Press enter to continue (hold enter for fast simulation)" 
             << endl;

        cin.ignore();
    }
}

/***************************************************************************************************
void Game::printGrid()
Description: This function displays the current grid of Ants and Doodlebugs.
***************************************************************************************************/
void Game::printGrid()
{
    // Simple print of the char array
    cout << "-------------------------------------------" << endl;
    
    for (int i=0; i<gridRow; i++)
    {
        cout << "|";
        for (int j=0; j<gridCol; j++)
        {
            if (array[i][j] != NULL) // if there is some Critter in the cell
            {
                if (array[i][j]->getType() == 'a') // if it's ant
                {
                    cout << " O"; // print O
                }
                else if (array[i][j]->getType() == 'd') // if it's doodlebug
                {
                     cout << " X"; // print X
                }
            }
            // If it's empty space
            else if (array[i][j] == NULL)
            {
                cout << "  "; // empty character
            }

        }
        cout << " |" << endl;
    }
}



