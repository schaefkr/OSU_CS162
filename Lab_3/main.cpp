/***************************************************************************
 * Program name:	main.cpp
 * Author:		Kristin Schaefer
 * Date:		04-21-2019
 * Description:		This is the main file for the dice war game. 
 * 			It creates two dice objects and passes them to the 
 * 			Game constructor. Then the menu function of the 
 * 			Game class is called. If the player chooses 1 to 
 * 			play the game, then the Game functions used to play
 * 			the war game are called.
 * Sources:		http://www.cplusplus.com/forum/beginner/132561/	
***************************************************************************/

#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
#include <iostream>
#include <string> 
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	srand(time(NULL));
	Die p1(1); 
	Die p2(1);
	
	Game gameWar(&p1, &p2);
	bool startGame = gameWar.gameMenu();
	if (startGame)
	{
		gameWar.setRounds();
		gameWar.setDieType();
		gameWar.setNumSides();
		gameWar.playGame();
	}
	return 0;
}




 
