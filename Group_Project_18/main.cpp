/***************************************************************************************************
* Program name:		main.cpp
* Group:		Group 18
* Authors:		Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:			05-12-2019
* Description:		This file contains the main function for the Predator-Prey Game.
***************************************************************************************************/

#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include "game.hpp"
#include "getRandomNumber.hpp"
#include "inputval.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int input = 0;

	cout << "--------------------------------------------" << endl;
	cout << "Predator-Prey Game" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;

	srand(time(NULL));
	// Create the game object
	Game predatorPrey;
	// Intialize all the info for the game
	predatorPrey.setStartValues();
	predatorPrey.initializeWorld();
	predatorPrey.playGame();

	cout << endl;
	cout << "Do you want to play again? Enter 1 or 2" << endl;
	cout << "1) Play again" << endl;
	cout << "2) Quit" << endl;
	input = inputVal(1,2);
	while (input != 2)
    {
        Game predatorPrey2;
        predatorPrey2.setStartValues();
        predatorPrey2.initializeWorld();
        predatorPrey2.playGame();
        cout << endl;
        cout << "Do you want to play again? Enter 1 or 2" << endl;
        cout << "1) Play again" << endl;
        cout << "2) Quit" << endl;
        input = inputVal(1,2);
    }

	return 0;
}

