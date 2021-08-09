/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			5-26-2019
* Description:		This file contains the main function for Project3. It creates a
* Game object and then uses that obejct to call the gameSetup(), playTournament(), and 
* playAgain() functions while the user selects to play the tournament and to keep playing
* the tournament.  
* Sources:
* Textbook ch 15, 17 
*****************************************************************************************/

#include "menu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "game.hpp"
#include "team.hpp"
#include "loser.hpp" 
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	bool play, keepPlaying = false;
	Game fantasyCombat;
	srand(time(NULL));	

	play = startMenu();
	if (play)
	{
		do 
		{
			fantasyCombat.gameSetup();
			fantasyCombat.playTournament();
			keepPlaying = playAgain();	
		} while (keepPlaying);
	}
	
	return 0;
}
