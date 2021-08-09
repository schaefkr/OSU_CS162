/*****************************************************************************************
* Program name:         game.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Game class. 
* 			The Game class controls the overall Game simulation. It has a 
* 			dynamic 2D array of Space pointers representing the Game map. 
* 			In addition to having getters and setters for the map Spaces, 
* 			it defines functions to create the map, setMap(), to print the 
* 			map, printMap(), and to print the current round information, 
* 			printRound().  
*****************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "space.hpp"	
#include "player.hpp"	

class Game
{
	private:
		Space *head = nullptr;
		Space *tail = nullptr;
		Space *playerPos = nullptr;
		Space *playerPrevPos = nullptr;
		Player player1;
		Player *playerPtr = nullptr; 
		Space ***map; 
		int rows;
		int cols;
		string printType;
		bool atWork;
		bool stress;
		bool time;
	public:
		Game();
		~Game();
		void setMap();
		void setHead(Space *headPtr);
		Space * getHead();
		void setTail(Space *tailPtr);
		Space * getTail();
		void setPlayerPos(Space *playerPosPtr);
		Space * getPlayerPos();
		void printMap();
		void startGame();
		int genRandomNum();
		void printRound(); 
};
#endif
