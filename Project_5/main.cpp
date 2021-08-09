/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			6-11-2019
* Description:		This file contains the main function for Final_Project.  
			The main function creates a Game object and a pointer to that 
			Game object and then passes the pointer to the menuStart()
			function. 
*****************************************************************************************/

#include "menu.hpp"
#include "space.hpp"
#include "home.hpp"
#include "work.hpp"
#include "shop.hpp"
#include "bus.hpp"
#include "train.hpp"
#include "walk.hpp"
#include "game.hpp"
#include "player.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));
	Game game1;			// create game object
	Game *game1Ptr = &game1;	// ptr for game object

	// start menu 
	menuStart(game1Ptr);

	return 0;
} 
