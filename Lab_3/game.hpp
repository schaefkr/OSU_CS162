/******************************************************************************************
** Program name:        game.hpp
** Author:              Kristin Schaefer
** Date:                04-21-2019
** Description:         This file contains the header file for the Game Class. 
******************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "loadedDie.hpp"

class Game
{
	private:
		Die *ptrDie1 = NULL;
		Die *ptrDie2 = NULL;
		int rounds, currentRound;	
		int p1DieType, p2DieType;
		int p1NumSides, p2NumSides;
		int p1Score, p2Score;
	public:	
		Game(Die *p1ayer1, Die *player2); 
		bool gameMenu();
		void setRounds();
		void setDieType();
		void setNumSides();
		void playGame();
		~Game();
};
#endif
