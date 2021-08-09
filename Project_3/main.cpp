/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			5-12-2019
* Description:		This file contains the main function for Project3.
* Sources:
* Textbook ch 15 
*****************************************************************************************/

#include "menu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "game.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
	bool keepPlaying, gameOver = false;
	int player1, player2 = 0; 
	Game fantasyCombat;
	srand(time(NULL));	

	do 
	{
		cout << "---------------------------------" << endl;
		cout << "Fantasy Combat Game" << endl;
		cout << "---------------------------------" << endl;

		// Main menu for selecting two players for combat
		cout << "Select two players for combat" << endl;
		player1 = mainMenu();
		cout << "Player 1: " << player1 << endl;
		player2 = mainMenu();
		cout << "Player 2: " << player2 << endl;
		fantasyCombat.setPlayers(player1, player2);
	
			// Keep playing game while no player death 
			do
			{
				gameOver = fantasyCombat.combatRound();
			} while (!gameOver);

		keepPlaying = playAgain();	
	} while (keepPlaying);
	
	return 0;
}
