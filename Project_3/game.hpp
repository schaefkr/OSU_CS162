/******************************************************************************************
* Program name:         game.hpp
* Author:               Kristin Schaefer
* Date:                 5-12-2019
* Description:          This file contains the header file for the game function.
******************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "character.hpp"
//#include "vampire.hpp"
#include "barbarian.hpp"
//#include "bluemen.hpp"
//#include "medusa.hpp"
//#include "harrypotter.hpp"

class Game
{
	private:
		Character *p1 = nullptr;
		Character *p2 = nullptr;
		int round;
	public:
		Game();
		~Game();
		void setPlayers(int player1, int player2);
		bool combatRound();
		void printRound(int attack); 
};
#endif

