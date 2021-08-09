/******************************************************************************************
* Program name:         game.hpp
* Author:               Kristin Schaefer
* Date:                 5-26-2019
* Description:          This file contains the header file for the Game class. The
* Game class contains all of the functions controlling the simulation of the tournament.
* The class contains two Team objects representing the lineup of each team as a doubly-
* linked list of nodes of Character objects. The class also has one Loser (also DLL)
* containing the Character object nodes that have lost a battle round. The class has 
* member functions to control the game setup, gameSetup(), the creation of new players 
* for the team lineups, createPlayer(), the simulation of the tournament, 
* playTournament(), as well as support functions combatRound(), printGame(), and
* printRound() for the playTournament() function.
******************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "team.hpp"
#include "loser.hpp"
#include "character.hpp"

class Game
{
	private:
		Team *team1 = nullptr;
		Team *team2 = nullptr;
		Loser *loserPile = nullptr;
		int teamSize;
		int round;
		int team1Score;
		int team2Score;
		Character *p1 = nullptr;
		Character *p2 = nullptr;
	public:
		Game();
		~Game();
		Character * createPlayer(int player);
		void combatRound();
		void printGame(); 
		void printRound(); 
		void gameSetup();
		void playTournament(); 
};
#endif

