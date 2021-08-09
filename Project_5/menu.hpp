/******************************************************************************************
* Program name:         menu.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the header file for the Menu functions. 
* 			It defines a function for the starting menu, menuStart(), a
* 			function to get the user's direction choice for the map, 
* 			menuDirection(), a function to get the user's shop action choice, 
*			menuShop(), and a validation function, menuValidation(), used by
*			all of the menu functions to check that the user's input is valid.
******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "game.hpp"
#include "space.hpp"
#include <string>
using std::string;

bool menuStart(Game *gamePtr);
int menuDirection(Space *posPtr);
int menuShop();
int menuValidation(int min, int max);

#endif
